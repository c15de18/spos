#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of processess: \n";
    cin>>n;

    vector<int> arrival(n),burst(n),completion(n),tat(n),waiting(n);
    float avg_tat = 0,avg_wait = 0;

    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Enter arrival and burst time for process : "<<i+1<<" : ";
        cin>>arrival[i]>>burst[i];
    }

    for(int i = 0; i <n-1 ; i++)
    {
        for(int j = i+1; j < n ; j++)
        {
            if(arrival[i] > arrival[j])
            {
                swap(arrival[i],arrival[j]);
                swap(burst[i],burst[j]);
            }
        }
    }

    int currentTime = 0;
    for(int i = 0; i < n; i++)
    {
        currentTime = max(currentTime,arrival[i]) + burst[i];
        completion[i] = currentTime;
        tat[i] = completion[i] - arrival[i];
        waiting[i] = tat[i] - burst[i];
        avg_tat += tat[i];
        avg_wait += waiting[i];
    }

    cout<<"\nProcess\tArrival\tBurst\tCompletion\tTat\tWaiting\n";
    for(int i = 0; i < n ; i++)
    {
        cout<<"P"<<i+1<<"\t"<<arrival[i]<<"\t"<<burst[i]<<"\t"<<completion[i]<<"\t\t"<<tat[i]<<"\t"<<waiting[i]<<endl;
    }

    cout<<"\nAverage TAT : "<<avg_tat/n<<endl;
    cout<<"\nAverage waiting time : "<<avg_wait/n<<endl;
    return 0;
}