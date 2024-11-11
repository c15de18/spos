#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int m,f,pf = 0;

    cout<<"Enter number of page refernces : ";
    cin>>m;

    vector<int> rs(m);
    cout<<"Enter the reference string : ";
    for(int i = 0; i < m ; i++)
    {
        cin>>rs[i];
    }

    cout<<"Enter number of frames : ";
    cin>>f;

    vector<int> frames(f,-1);
    vector<int> counter(f,0);

    cout<<"\nThe page replacement process : ";

    for(int i = 0; i < m ; i++)
    {
        int found = -1;
        for(int j  = 0; j < f ; j++)
        {
            if(frames[j] == rs[i])
            {
                counter[j]++;
                found = j;
                break;
            }
        }

        if(found == -1)
        {
            int minindex = 0;
            for(int j = 1; j < f; j++)
            {
                if(counter[j] < counter[minindex])
                {
                    minindex = j;
                }
            }
            frames[minindex] = rs[i];
            counter[minindex] = 1;
            pf++; 
        }

        for (int j = 0; j < f; j++) {
            if (frames[j] != -1) {
                cout << frames[j] << "\t";
            } else {
                cout << "-\t";
            }
        }

        if (found == -1) {
            cout << "PF No. " << pf;
        }
        cout << endl;
    }

    cout << "\nTotal number of page faults: " << pf << endl;

    return 0;

}