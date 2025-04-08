#include <iostream>
#include <vector>

struct Point {
    long long x, y;
};

long long crossProduct(Point& A, Point& B, Point& C) {
    long long dx1 = B.x - A.x;
    long long dy1 = B.y - A.y;
    long long dx2 = C.x - B.x;
    long long dy2 = C.y - B.y;
    return dx1 * dy2 - dy1 * dx2;
}

bool isConvex(std::vector<Point>& points, int n) {
    int sign = 0;

    for (int i = 0; i < n; i++) {
        Point& A = points[i];
        Point& B = points[(i + 1) % n];
        Point& C = points[(i + 2) % n];

        long long z = crossProduct(A, B, C);

        if (z != 0) {
            int current_sign = (z > 0) ? 1 : -1;
            if (sign == 0) {
                sign = current_sign;
            } else if (sign != current_sign) {
                return false;
            }
        }
    }
    return true;
}

int main() 
{
    int n;
    std::cin >> n;
    std::vector<Point> points(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    if (isConvex(points, n)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}