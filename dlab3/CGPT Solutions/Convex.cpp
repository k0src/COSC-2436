#include <iostream>
#include <vector>

struct Point {
    long long x, y;
};

long long cross(const Point& A, const Point& B, const Point& C) {
    long long dx1 = B.x - A.x;
    long long dy1 = B.y - A.y;
    long long dx2 = C.x - B.x;
    long long dy2 = C.y - B.y;
    return dx1 * dy2 - dy1 * dx2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> points(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    int sign = 0;

    for (int i = 0; i < n; ++i) {
        const Point& A = points[i];
        const Point& B = points[(i + 1) % n];
        const Point& C = points[(i + 2) % n];
        long long z = cross(A, B, C);
        if (z != 0) {
            int current_sign = (z > 0) ? 1 : -1;
            if (sign == 0) {
                sign = current_sign;
            } else if (sign != current_sign) {
                std::cout << "NO\n";
                return 0;
            }
        }
    }

    std::cout << "YES\n";
    return 0;
}