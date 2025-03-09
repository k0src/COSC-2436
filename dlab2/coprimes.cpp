#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <iostream>

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int d = 0;
    while (((a & 1) == 0) && ((b & 1) == 0)) {
        a /= 2;
        b /= 2;
        d++;
    }

    while ((a & 1) == 0) a /= 2;
    while ((b & 1) == 0) b /= 2;

    while (a != b) {
        if (a > b) {
            a -= b;
            while ((a & 1) == 0) a /= 2;
        } else {
            b -= a;
            while ((b & 1) == 0) b /= 2; 
        }
    }

    return a << d;
}


// int gcd(int a, int b) {
//     if (b == 0) return a;
//     return gcd(b, a % b);
// }

int coprimePairs(int* a, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (gcd(a[i], a[j]) == 1) res++;
        }
    }
    return res;
}

int main()
{
    int size, n;
    scanf("%d", &size);

    int* a = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        scanf("%d", &n);
        a[i] = n;
    }

    printf("%d\n", coprimePairs(a, size));

    return 0;
}