#!/bin/bash

# Check if correct number of arguments
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <cpp_file> <test_file>"
    exit 1
fi

CPP_FILE="$1"
TEST_FILE="$2"
BINARY="a.out"
DIFF_FILE="diff.txt"

# Check if files exist
if [ ! -f "$CPP_FILE" ] || [ ! -f "$TEST_FILE" ]; then
    echo "Error: One or both input files do not exist"
    exit 1
fi

# Compile the C++ program with proper flags
g++ -std=c++14 -Wall -Wextra -pedantic "$CPP_FILE" -o "$BINARY"
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Read number of tests
NUM_TESTS=$(head -n 1 "$TEST_FILE" | tr -d '[:space:]')
if ! [[ "$NUM_TESTS" =~ ^[0-9]+$ ]]; then
    echo "Invalid test file format: Number of tests must be a positive integer"
    exit 1
fi

# Initialize diff file
> "$DIFF_FILE"
FAILED=false

# Read the entire test file content
TEST_CONTENT=$(<"$TEST_FILE")

# Process each test case
for ((test=1; test<=NUM_TESTS; test++)); do
    # Extract input section for this test
    INPUT_SECTION=$(echo "$TEST_CONTENT" | awk -v test=$test '
        BEGIN { found=0; inInput=0; testNum=0 }
        /^Input:/ { 
            testNum++; 
            if(testNum == test) { 
                inInput=1; 
                found=1; 
                next; 
            } else if(found == 1) { 
                exit; 
            }
        }
        /^Output:/ { if(found == 1) { inInput=0; next; } }
        { if(inInput == 1 && found == 1 && $0 != "") print $0 }
    ')

    # Extract expected output section for this test
    EXPECTED_OUTPUT=$(echo "$TEST_CONTENT" | awk -v test=$test '
        BEGIN { found=0; inOutput=0; testNum=0 }
        /^Input:/ { 
            if(found == 1 && inOutput == 1) { 
                exit; 
            }
            testNum++; 
        }
        /^Output:/ { 
            if(testNum == test) { 
                inOutput=1; 
                found=1; 
                next; 
            } 
        }
        { if(inOutput == 1 && found == 1 && $0 != "") print $0 }
    ')

    # Run program with input
    ACTUAL_OUTPUT=$(echo "$INPUT_SECTION" | ./"$BINARY" 2>/dev/null)
    
    # Check if program crashed
    if [ $? -ne 0 ]; then
        echo -e "\033[31mFAILED\033[0m"
        FAILED=true
        {
            echo "Test $test:"
            echo "Expected Output:"
            echo "$EXPECTED_OUTPUT"
            echo "Actual Output:"
            echo "Program crashed"
            echo
        } >> "$DIFF_FILE"
        continue
    fi

    # Normalize whitespace for comparison
    # 1. Trim trailing whitespace from each line
    # 2. Remove trailing newlines
    # 3. Normalize spaces between items (collapse multiple spaces to single space)
    normalize_whitespace() {
        # Trim trailing whitespace, normalize internal spaces, and trim trailing newlines
        echo "$1" | sed 's/[[:space:]]*$//' | sed 's/[[:space:]]\+/ /g' | sed -z 's/\n*$//'
    }

    EXPECTED_CLEAN=$(normalize_whitespace "$EXPECTED_OUTPUT")
    ACTUAL_CLEAN=$(normalize_whitespace "$ACTUAL_OUTPUT")

    # Compare normalized outputs
    if [ "$ACTUAL_CLEAN" = "$EXPECTED_CLEAN" ]; then
        echo -e "\033[32mPASSED\033[0m"
    else
        echo -e "\033[31mFAILED\033[0m"
        FAILED=true
        
        # Append to diff file
        {
            echo "Test $test:"
            echo "Expected Output:"
            echo "$EXPECTED_OUTPUT"
            echo "Actual Output:"
            echo "$ACTUAL_OUTPUT"
            echo
        } >> "$DIFF_FILE"
    fi
done

# Clean up
rm -f "$BINARY"

# Remove diff file if no failures
if [ "$FAILED" = false ]; then
    rm -f "$DIFF_FILE"
fi