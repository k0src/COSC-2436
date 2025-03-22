#include <iostream>
#include <vector>

typedef long long ll;

ll countSubordinates(ll employee, std::vector<std::vector<ll>>& subordinates, std::vector<ll>& result) {
    ll total = 0;
    
    for(ll sub : subordinates[employee]) {
        total += 1 + countSubordinates(sub, subordinates, result);
    }
    
    result[employee] = total;
    return total;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll n;
    std::cin >> n;

    std::vector<std::vector<ll>> subordinates(n + 1);

    for (ll i = 2; i <= n; i++) {
        ll b;
        std::cin >> b;
        subordinates[b].push_back(i);
    }

    std::vector<ll> res(n + 1, 0);

    countSubordinates(1, subordinates, res);

    for(ll i = 1; i <= n; i++) {
        std::cout << res[i] << " ";
    }

    return 0;
}