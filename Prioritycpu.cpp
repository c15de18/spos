#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> arrival(n), burst(n), priority(n);
    vector<int> completion(n), tat(n), waiting(n);
    float avg_tat = 0, avg_wait = 0;

    // Input process details
    for(int i = 0; i < n; i++) {
        cout << "Enter arrival time, burst time, and priority for process " << i+1 << ": ";
        cin >> arrival[i] >> burst[i] >> priority[i];
    }

    // Sort processes based on priority (lower priority value is higher priority)
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(priority[i] > priority[j] || (priority[i] == priority[j] && arrival[i] > arrival[j])) {
                swap(arrival[i], arrival[j]);
                swap(burst[i], burst[j]);
                swap(priority[i], priority[j]);
            }
        }
    }

    int currentTime = 0;
    for(int i = 0; i < n; i++) {
        currentTime = max(currentTime, arrival[i]) + burst[i];
        completion[i] = currentTime;
        tat[i] = completion[i] - arrival[i];
        waiting[i] = tat[i] - burst[i];
        avg_tat += tat[i];
        avg_wait += waiting[i];
    }

    // Output the results
    cout << "\nArrival\tBurst\tPriority\tCompletion\tTAT\tWaiting\n";
    for(int i = 0; i < n; i++) {
        cout << arrival[i] << "\t" << burst[i] << "\t" << priority[i] << "\t\t"
             << completion[i] << "\t\t" << tat[i] << "\t" << waiting[i] << endl;
    }

    // Calculate and display averages
    cout << "\nAverage TAT: " << avg_tat / n << endl;
    cout << "Average Waiting Time: " << avg_wait / n << endl;

    return 0;
}
