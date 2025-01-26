#include <iostream>
#include <cstdio>
#include <vector>

int main() 
{
    int size;
    scanf("%d", &size); 

    std::vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    std::vector<int> indices(size + 1);

    for (int i = 0; i < size; i++) {
        indices[numbers[i]] = i;
    }

    int rounds = 1;

    for (int n = 1; n < size; n++) {
        if (indices[n + 1] < indices[n]) rounds++;
    }

    printf("%d\n", rounds);

    return 0;
}