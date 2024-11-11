#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: \n";
    cin >> n;

    vector<int> arrival(n), burst(n), remainingBurst(n), completion(n), tat(n), waiting(n);
    float avg_tat = 0, avg_wait = 0;

    // Input arrival and burst times
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival and burst time for process " << i + 1 << ": ";
        cin >> arrival[i] >> burst[i];
        remainingBurst[i] = burst[i]; // Initialize remaining burst time
    }

    int currentTime = 0, completedProcesses = 0;

    // Preemptive SJF (SRTF) scheduling loop
    while (completedProcesses < n)
    {
        int shortest = -1;
        int minRemainingBurst = INT_MAX;

        // Find the process with the shortest remaining burst time that has arrived
        for (int i = 0; i < n; i++)
        {
            if (arrival[i] <= currentTime && remainingBurst[i] > 0 && remainingBurst[i] < minRemainingBurst)
            {
                minRemainingBurst = remainingBurst[i];
                shortest = i;
            }
        }

        if (shortest != -1) // If a process is found to execute
        {
            remainingBurst[shortest]--; // Execute for one unit of time
            currentTime++; // Increment time

            // If the process has finished
            if (remainingBurst[shortest] == 0)
            {
                completion[shortest] = currentTime;
                tat[shortest] = completion[shortest] - arrival[shortest];
                waiting[shortest] = tat[shortest] - burst[shortest];

                avg_tat += tat[shortest];
                avg_wait += waiting[shortest];
                completedProcesses++;
            }
        }
        else
        {
            currentTime++; // If no process is ready, move time forward
        }
    }

    // Display results
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << arrival[i] << "\t\t" << burst[i] << "\t\t" 
             << completion[i] << "\t\t" << tat[i] << "\t\t" << waiting[i] << endl;
    }

    // Average waiting time and turnaround time
    cout << "\nAverage Turnaround Time: " << avg_tat / n << endl;
    cout << "Average Waiting Time: " << avg_wait / n << endl;

    return 0;
}
