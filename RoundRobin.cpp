#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, time_slice, time = 0, processes_left;
    cout << "Enter the number of processes: \n";
    cin >> n;

    vector<int> arrival(n), burst(n), completion(n), tat(n), waiting(n), rem_bt(n);
    float avg_tat = 0, avg_wait = 0;

    // Input arrival and burst times
    for(int i = 0; i < n; i++) {
        cout << "Enter arrival and burst time for process " << i + 1 << ": ";
        cin >> arrival[i] >> burst[i];
        rem_bt[i] = burst[i];  // Initialize remaining burst time for each process
    }

    cout << "Enter the Time Slice: ";
    cin >> time_slice;

    processes_left = n;  // Number of processes left to complete

    // Round Robin Scheduling
    while(processes_left > 0) {
        for(int i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {  // Process has remaining burst time
                int exec_time = min(rem_bt[i], time_slice);  // Execute the minimum of remaining burst time or time slice
                time += exec_time;
                rem_bt[i] -= exec_time;

                if(rem_bt[i] == 0) {
                    completion[i] = time;  // Completion time for this process
                    tat[i] = completion[i] - arrival[i];  // Turnaround time
                    waiting[i] = tat[i] - burst[i];  // Waiting time = Turnaround time - Burst time
                    avg_tat += tat[i];
                    avg_wait += waiting[i];
                    processes_left--;  // Process completed
                }
            }
        }
    }

    // Output results
    cout << "\nProcess\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << arrival[i] << "\t" << burst[i] << "\t" 
             << completion[i] << "\t\t" << tat[i] << "\t" << waiting[i] << endl;
    }

    cout << "\nAverage TAT: " << avg_tat / n << endl;
    cout << "Average Waiting Time: " << avg_wait / n << endl;

    return 0;
}
