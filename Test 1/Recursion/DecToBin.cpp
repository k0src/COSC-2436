#include <iostream>
#include <string>

std::string decimalToBinary(int n) {
    if (n == 0) return "";

    return decimalToBinary(n / 2) + std::to_string(n % 2);
}

int main() 
{
    int n = 13;
    std::string binary = decimalToBinary(n);
    std::cout << binary << std::endl;

    return 0;
}
