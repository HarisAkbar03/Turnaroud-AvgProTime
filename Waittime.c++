#include <iostream>
#include <algorithm> // For std::sort
using namespace std;

// Function to calculate waiting time for FCFS
void calculateFCFSWaitingTime(int burstTimes[], int n, int waitingTime[]) {
    waitingTime[0] = 0; // First process has 0 waiting time
    for (int i = 1; i < n; i++) {
        waitingTime[i] = burstTimes[i - 1] + waitingTime[i - 1];
    }
}

// Function to calculate turnaround time for FCFS
void calculateTurnaroundTime(int burstTimes[], int n, int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = burstTimes[i] + waitingTime[i];
    }
}

// Function to calculate waiting time for SJF
void calculateSJFWaitingTime(int burstTimes[], int n, int waitingTime[]) {
    int sortedBurstTimes[n];
    copy(burstTimes, burstTimes + n, sortedBurstTimes);
    sort(sortedBurstTimes, sortedBurstTimes + n); // Sort burst times in ascending order

    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = sortedBurstTimes[i - 1] + waitingTime[i - 1];
    }
}

// Function to print results
void printResults(const char* method, int burstTimes[], int n, int waitingTime[], int turnaroundTime[]) {
    cout << "----------------- " << method << " -----------------\n";
    cout << "Process ID | Waiting Time | Turnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "     " << i + 1 << "           |      " << waitingTime[i] << "        |        " << turnaroundTime[i] << "\n";
    }
}

int main() {
    int burstTimes[] = {2, 1, 8, 4, 5}; // Example burst times
    int n = sizeof(burstTimes) / sizeof(burstTimes[0]);
    int waitingTimeFCFS[n], turnaroundTimeFCFS[n];
    int waitingTimeSJF[n], turnaroundTimeSJF[n];

    // FCFS Scheduling
    calculateFCFSWaitingTime(burstTimes, n, waitingTimeFCFS);
    calculateTurnaroundTime(burstTimes, n, waitingTimeFCFS, turnaroundTimeFCFS);
    printResults("FCFS", burstTimes, n, waitingTimeFCFS, turnaroundTimeFCFS);

    // SJF Scheduling
    calculateSJFWaitingTime(burstTimes, n, waitingTimeSJF);
    calculateTurnaroundTime(burstTimes, n, waitingTimeSJF, turnaroundTimeSJF);
    printResults("SJF", burstTimes, n, waitingTimeSJF, turnaroundTimeSJF);

    return 0;
}
