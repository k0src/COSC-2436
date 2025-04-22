#include <iostream>
#include <queue>

struct Process {
    int id;
    int burst_time;
};

void roundRobinScheduling(Process processes[], int n, int time_quantum) {
    std::queue<Process> q;
    int total_time = 0;

    // Enqueue all processes initially
    for (int i = 0; i < n; i++) {
        q.push(processes[i]);
    }

    // Process execution loop
    while (!q.empty()) {
        Process current = q.front();
        q.pop();

        // Execute the process for either its 
        // remaining burst time or time quantum
        int execution_time = std::min(current.burst_time, time_quantum);
        std::cout << "Executing Process P" << current.id 
			      << " for " << execution_time << " units" << std::endl;
        total_time += execution_time;
        current.burst_time -= execution_time;

        // If process still has remaining burst time, enqueue it again
        if (current.burst_time > 0) {
            q.push(current);
        } else {
            std::cout << "Process P" << current.id 
					  << " completed at time " << total_time << std::endl;
        }
    }

    std::cout << "Total execution time: " << total_time 
			  << " units" << std::endl;
}

int main()
{
    Process processes[4] = { {1, 10}, {2, 5}, {3, 8}, {4, 12} };
    int time_quantum = 3;
    int n = 4;
    roundRobinScheduling(processes, n, time_quantum);
    return 0;
}