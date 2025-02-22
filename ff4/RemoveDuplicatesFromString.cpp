#include <iostream>
#include <stack>
#include <string>

std::string removeAdjacentDuplicates(const std::string& s)
{
    std::stack<char> stack;

    for (char c : s) {
        if (!stack.empty() && stack.top() == c) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }

    std::string result;
    while (!stack.empty()) {
        result = stack.top() + result;
        stack.pop();
    }

    return result;
}

int main()
{
    std::string s = "abbaca";

    std::cout << removeAdjacentDuplicates(s) << std::endl;

    return 0;
}