#include <iostream>
#include <queue>

#include <stack>

void reverseFirstKElements(std::queue<int>& q, int k) {
    if (k <= 0 || k > q.size()) {
        return; 
    }

    std::stack<int> s;

    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

void reverseFirstKElementsRec(std::queue<int>& q, int k) {
	if (k <= 0 || q.empty()) {
		return;
	}

	int front = q.front();
	q.pop();

	reverseFirstKElementsRec(q, k - 1);

	q.push(front);
}

void reorderQueue(std::queue<int>& q, int k) {
	for (int i = 0; i < q.size() - k; i++) {
		q.push(q.front());
		q.pop();
	}
}

int main()
{
	std::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	reverseFirstKElementsRec(q, 3);
	reorderQueue(q, 3);

	while (!q.empty()) {
		std::cout << q.front() << std::endl;
		q.pop();
	}

	return 0;
}