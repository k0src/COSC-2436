#include <iostream>

using ll = long long;

void pointLocation(ll points[]) {
    // p1 - [0, 1], p2 - [2, 3], p3 - [4, 5]
    float d = ((points[4] - points[0]) * (points[3] - points[1])) - 
            ((points[5] - points[1]) * (points[2] - points[0]));

    const float EPSILON = 1e-6;

    if (std::abs(d) < EPSILON) {
        std::cout << "TOUCH\n";
        return;
    } else if (d < -EPSILON) {
        std::cout << "LEFT\n";
    } else {
        std::cout << "RIGHT\n";
    }
}

int main()
{
    ll tests;
    std::cin >> tests;
    ll points[6];

    for (ll i = 0; i < tests; i++) {
        for (ll j = 0; j < 6; j++) {
            std::cin >> points[j];
        }
        pointLocation(points);
    }

    return 0;
}