#include<iostream>
#include<vector>
using namespace std;

int main() {
    int m, f, pf = 0, next = 1;

    // Input the number of page references
    cout << "Enter number of page references: ";
    cin >> m;

    vector<int> rs(m);
    cout << "Enter the reference string: ";
    for (int i = 0; i < m; i++) {
        cin >> rs[i];
    }

    // Input the number of frames
    cout << "Enter number of frames: ";
    cin >> f;

    vector<int> frames(f, -1);  // Initialize frames to empty (-1)
    vector<int> counter(f, 0);  // Initialize counters for LRU

    cout << "\nThe page replacement process is:\n";

    // LRU page replacement algorithm
    for (int i = 0; i < m; i++) 
    {
        bool found = false;

        // Check if the page is already in memory
        for (int j = 0; j < f; j++) 
        {
            if (frames[j] == rs[i]) 
            {
                counter[j] = next++;  // Update counter for the LRU
                found = true;
                break;
            }
        }

        // If page is not found, it's a page fault
        if (!found) 
        {
            int replace_index = -1;

            if (i < f) 
            {  // Fill initial frames with pages
                replace_index = i;
            } 
            else 
            {  // Replace the LRU page
                int min = 0;
                for (int j = 1; j < f; j++) 
                {
                    if (counter[min] > counter[j]) 
                    {
                        min = j;
                    }
                }
                replace_index = min;
            }

            frames[replace_index] = rs[i];  // Replace the page
            counter[replace_index] = next++;  // Set the current time for the new page
            pf++;  // Increment page fault count
        }

        // Print current state of frames
        for (int j = 0; j < f; j++) 
        {
            if (frames[j] != -1) 
            {
                cout << frames[j] << "\t";  // Display page in the frame
            } 
            else 
            {
                cout << "-\t";  // Display empty frame
            }
        }

        // Print page fault message if a page fault occurred
        if (!found) 
        {
            cout << "PF No. " << pf;  // Display the page fault number
        }

        cout << endl;
    }

    // Output total page faults
    cout << "\nTotal number of page faults: " << pf << endl;

    return 0;
}
