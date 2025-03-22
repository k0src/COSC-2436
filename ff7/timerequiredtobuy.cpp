#include <iostream>
#include <vector>

int timeRequiredToBuy(std::vector<int>& tickets, int k) {
    int time = 0;

    for (int i = 0; i < tickets.size(); i++) {
        if (i <= k)
            time += std::min(tickets[i], tickets[k]);
        else
            time += std::min(tickets[i], tickets[k] - 1);
    }

    return time;
}
int main()
{
    std::vector<int> tickets = {2, 3, 2};
    int k = 2;

    std::cout << timeRequiredToBuy(tickets, k) << std::endl;

    return 0;
}