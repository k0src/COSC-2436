#include <iostream>
#include <vector>
#include <map>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int countGCDSquareSubarrays(std::vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        int currentGcd = arr[i];
        if (currentGcd == 1) {
            count++;
        }
        
        for (int j = i + 1; j < n; ++j) {
            currentGcd = gcd(currentGcd, arr[j]);
            int length = j - i + 1;

            if (currentGcd == length) {
                count++;
            }
            if (currentGcd == 1 && length > 1) {
                break;
            }
        }
    }
    
    return count;
}

int main() 
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int result = countGCDSquareSubarrays(arr);
    std::cout << result << "\n";
    return 0;
}