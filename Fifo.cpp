#include<iostream>
#include<vector>
using namespace std;

int main() {
    int m, f, pf = 0, count = 0;

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

    vector<int> frames(f, -1); 
    

    cout << "\nThe page replacement process is:\n";

 
    for (int i = 0; i < m; i++) 
    {
        bool found = false;

        // Check if the page is already in memory
        for (int j = 0; j < f; j++) 
        {
            if (frames[j] == rs[i]) 
            {
                found =true;
                break;
            }
        }

        // If page is not found, it's a page fault
        if (!found) 
        {
            frames[count] = rs[i];
            count = (count+1) % f;
            pf++;
        }

        for (int j = 0; j < f; j++) 
        {
            if (frames[j] != -1) 
            {
                cout << frames[j] << "\t";
            } 
            else 
            {
                cout << "-\t";
            }
        }

        if (!found) {
            cout << "PF No. " << pf;
        }
        cout << endl;
    }

    
    cout << "\nTotal number of page faults: " << pf << endl;

    return 0;
}
