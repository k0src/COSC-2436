#include <stdio.h>
#include <stdlib.h>

using llu = unsigned long long;

const llu MOD = 1000000007;

// modular inverse - fermats theorem
llu modpow(llu a, llu b, llu mod) {
    llu result = 1;
    while (b) {
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

llu modinv(llu a, llu mod) {
    return modpow(a, mod - 2, mod);
}

llu numValidBracketSeqeunces(llu n) {
    if (n % 2 == 1) return 0;

    llu res = 1;

    for (llu i = 0; i < (n / 2); i++) {
        res = (res * (2 * (n / 2) - i)) % MOD;
        res = (res * modinv(i + 1, MOD)) % MOD;
    }
    res = (res * modinv((n / 2) + 1, MOD)) % MOD;

    return res;
}

int main() {
    llu n;
    scanf("%llu", &n);

    printf("%llu", numValidBracketSeqeunces(n));
    
    return 0;
}