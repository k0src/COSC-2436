#include <iostream>
#include <queue>

void generateBinNums(int n) {
    if (n < 1) return;

    std::queue<std::string> q;
    q.push("1");

    for (int i = 0; i < n; i++) {
        std::string front = q.front();
        q.pop();

        std::cout << front << std::endl;

        q.push(front + "0");
        q.push(front + "1");
    }
}

int main()
{
	generateBinNums(5);
	return 0;
}