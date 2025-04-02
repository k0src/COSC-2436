#include "help.h"

using namespace std;

struct Process {
    int id;
    int burst_time;
    Process(int id, int burst_time) : id(id), burst_time(burst_time) {}
};

void roundRobin(vector<Process>& processes, int time_quantum) {
    queue<Process> q;

    int total_execution_time = 0;

    for (const auto& p : processes) {
        q.push(p);
    }

    while (!q.empty()) {
        Process current_process = q.front();
        q.pop();

        int execution_time = min(time_quantum, current_process.burst_time);
        current_process.burst_time -= execution_time;

        cout << "Executing process " << current_process.id << " for "
             << execution_time << " units." << endl;

        if (current_process.burst_time > 0) {
            q.push(current_process);
        }

        total_execution_time += execution_time;
    }

    cout << "Total execution time: " << total_execution_time << endl;
}

int main()
{
    vector<Process> proccesses;

    proccesses.push_back({1, 10});
    proccesses.push_back({2, 13});
    proccesses.push_back({3, 9});
    proccesses.push_back({4, 18});

    roundRobin(proccesses, 8);

    return 0;
}