#include <iostream>
#include <vector>
#include <unordered_map>

#include <unordered_map>

long long subarraySum(std::vector<long long>& a, long long sum) {
    long long res = 0;
    long long prefix_sum = 0;
    std::unordered_map<long long, long long> prefix_sum_map;
    prefix_sum_map[0] = 1;

    for (long long i = 0; i < a.size(); i++) {
        prefix_sum += a[i];
        
        if (prefix_sum_map.find(prefix_sum - sum) != prefix_sum_map.end()) {
            res += prefix_sum_map[prefix_sum - sum];
        }
        prefix_sum_map[prefix_sum]++;
    }

    return res;
}

int main()
{
    long long n, sum, x;
    std::cin >> n >> sum;

    std::vector<long long> a;

    for (long long i = 0; i < n; i++) {
        std::cin >> x;
        a.push_back(x);
    }

    std::cout << subarraySum(a, sum);

    return 0;
}