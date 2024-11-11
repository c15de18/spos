#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, f, pf = 0;  // m = number of page references, f = number of frames, pf = page fault count

    // Input number of page references
    cout << "Enter number of page references: ";
    cin >> m;

    vector<int> rs(m);  // Reference string
    cout << "Enter the reference string: ";
    for (int i = 0; i < m; i++) {
        cin >> rs[i];
    }

    // Input number of frames
    cout << "Enter number of frames: ";
    cin >> f;

    vector<int> frames(f, -1);  // Frames initialized with -1 (empty frames)
    vector<int> counter(f, 0);  // Counter to keep track of the last use

    cout << "\nThe page replacement process:\n";

    for (int i = 0; i < m; i++) {
        int found = -1;  // Flag to check if the page is found in frames

        // Check if the current page is already in one of the frames
        for (int j = 0; j < f; j++) {
            if (frames[j] == rs[i]) {
                counter[j]++;  // Increment the counter for the found page
                found = j;  // Mark the page as found
                break;
            }
        }

        // If page is not found, replace the least recently used page
        if (found == -1) {
            int minindex = 0;
            for (int j = 1; j < f; j++) {
                if (counter[j] < counter[minindex]) {
                    minindex = j;  // Find the page with the least counter (oldest)
                }
            }
            frames[minindex] = rs[i];  // Replace the least recently used page
            counter[minindex] = 1;  // Reset the counter for the new page
            pf++;  // Increment page fault count
        }

        // Print the current state of the frames
        for (int j = 0; j < f; j++) {
            if (frames[j] != -1) {
                cout << frames[j] << "\t";  // Print page in frame
            } else {
                cout << "-\t";  // Empty frame
            }
        }

        // If page fault occurred, print the page fault number
        if (found == -1) {
            cout << "PF No. " << pf;
        }
        cout << endl;  // New line after each reference
    }

    // Output the total number of page faults
    cout << "\nTotal number of page faults: " << pf << endl;

    return 0;
}
