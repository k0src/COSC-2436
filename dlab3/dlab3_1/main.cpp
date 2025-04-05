#include <stdio.h>
#include <stdlib.h>

// VECTORS/MAPS + CIN + COUT WAS 0.01 SECONDS TOO SLOW, USING C ARRAYS WORKS LOL

using llu = unsigned long long;

llu maxGCD(llu* arr, llu n) {
    llu max = 0;
    for (llu i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    llu* freq = (llu*) calloc(max + 1, sizeof(llu));

    for (llu i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for (llu i = max; i >= 1; i--) {
        llu count = 0;
        for (llu j = i; j <= max; j += i) {
            count += freq[j];
            if (count >= 2) {
                return i;
            }
        }
    }
    return 1;
}

int main() {
    llu n;
    scanf("%llu", &n);
    
    llu* arr = (llu*) malloc(n * sizeof(llu));
    
    for (llu i = 0; i < n; i++) {
        scanf("%llu", &arr[i]);
    }

    printf("%llu", maxGCD(arr, n));
    
    return 0;
}