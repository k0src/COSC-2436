#include "help.h"

using namespace std;

void printDecreasing(int n) {
    if (n == 0) return;
    cout << n << " ";
    printDecreasing(n - 1);
}

void printBothWays(int n) {
    if (n == 0) return;
    cout << n << " ";
    printBothWays(n - 1);
    cout << n << " ";
}

int mystery(int n) {
    if (n == 1) return 1;
    return n + mystery(n - 1);
}

string buildString(int n) {
    if (n == 0) return "";
    return "(" + buildString(n - 1) + ")";
}

void complexTrace(int n) {
    if (n == 0) return;
    cout << "A" << n << " ";
    complexTrace(n - 1);
    cout << "B" << n << " ";
    complexTrace(n - 1);
    cout << "C" << n << " ";
}

void hardRec(int n) {
    if (n <= 0) return;
    cout << "[" << n << "] ";
    hardRec(n - 2);
    cout << "<" << n << "> ";
    hardRec(n - 1);
}

void insane(int a, int b) {
    if (a <= 0 || b <= 0) {
        cout << "* ";
        return;
    }
    cout << "(" << a << "," << b << ") ";
    insane(a - 1, b);
    insane(a, b - 2);
    cout << "[" << a << "," << b << "] ";
}

int main()
{
    cout << "1:\n";
    printDecreasing(3);
    cout << "\n2:\n";
    printBothWays(2);
    cout << "\n3:\n";
    cout << mystery(4);
    cout << "\n4:\n";
    cout << buildString(3);
    cout << "\n5:\n";
    complexTrace(2);
    cout << "\n6:\n";
    hardRec(3);
    cout << "\n7:\n";
    insane(2, 3);

    return 0;
}