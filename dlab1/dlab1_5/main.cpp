#include <cstdio>
#include <cmath>

int main()
{
    long n_vertices;
    scanf("%ld", &n_vertices);

    long* x_vertices = new long[n_vertices];
    long* y_vertices = new long[n_vertices];

    for (long i = 0; i < n_vertices; i++) {
        scanf("%ld", &x_vertices[i]);
        scanf("%ld", &y_vertices[i]);
    }

    long area = 0.0;

    long j = n_vertices - 1;

    for (long i = 0; i < n_vertices; i++) {
        area += (x_vertices[j] + x_vertices[i]) * (y_vertices[j] - y_vertices[i]);
        j = i;
    }

    area = std::abs(area);

    printf("%ld", area);

    delete[] x_vertices;
    delete[] y_vertices;

    return 0;
}