#include "help.h"

using namespace std;

struct lines {
    int id;
    int priority;
    int time;
};

void priorityRoundRobin(lines arr[], int n, int quantumTime) {
    queue<lines> q;

    int total_execution_time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].priority == 1) {
            q.push(arr[i]);
        }
    }

    while (!q.empty()) {
        lines process = q.front();
        q.pop();

        int execution_time = min(quantumTime, process.time); // MIN!!!
        process.time -= execution_time;

        cout << "Working on process " << process.id << " for " << execution_time << " units." << endl; 
        
        if (process.time > 0) {
            q.push(process);
        } else {
            cout << "Finished working on process " << process.id << "." << endl;
        }

        total_execution_time += execution_time;
    }

    cout << "Total execution time: " << total_execution_time << "." << endl;
}

int main()
{
    lines arr[5] = {{10, 1, 12}, {12, 2, 11}, {5, 1, 6}, {9, 3, 10}, {3, 1, 16}};
    priorityRoundRobin(arr, 5, 8);

    return 0;
}