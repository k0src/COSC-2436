#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool rayIntersectsCube(double x0, double y0, double z0,
                       double dx, double dy, double dz,
                       double cx, double cy, double cz, double s) {
    double half = s / 2.0;
    double minX = cx - half, maxX = cx + half;
    double minY = cy - half, maxY = cy + half;
    double minZ = cz - half, maxZ = cz + half;

    double tx1 = (minX - x0) / dx;
    double tx2 = (maxX - x0) / dx;
    if (tx1 > tx2) swap(tx1, tx2);

    double ty1 = (minY - y0) / dy;
    double ty2 = (maxY - y0) / dy;
    if (ty1 > ty2) swap(ty1, ty2);

    double tz1 = (minZ - z0) / dz;
    double tz2 = (maxZ - z0) / dz;
    if (tz1 > tz2) swap(tz1, tz2);

    double tEntry = max({tx1, ty1, tz1});
    double tExit  = min({tx2, ty2, tz2});

    return tEntry <= tExit && tExit >= 0;
}

int main() 
{
    int n;
    cin >> n;

    double x0, y0, z0, dx, dy, dz;
    cin >> x0 >> y0 >> z0 >> dx >> dy >> dz;

    vector<int> result;
    for (int i = 1; i <= n; ++i) {
        double cx, cy, cz, s;
        cin >> cx >> cy >> cz >> s;

        if (rayIntersectsCube(x0, y0, z0, dx, dy, dz, cx, cy, cz, s)) {
            result.push_back(i);
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    return 0;
}