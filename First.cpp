#include<iostream>
using namespace std;

void firstFit(int blockSize[],int m,int processSize[],int n)
{
    int allocation[n],remblockSize[n];
    fill_n(allocation,n,-1);

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                remblockSize[i] = blockSize[j];
                break;
            }
        }
    }

    cout<<"\nProcess No\tProcess Size\tBlock No\tRemaining Block Size\n";
    for(int i = 0; i < n;i++)
    {
        cout<<" "<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
        if(allocation[i] != -1)
        {
            cout<<allocation[i] + 1<<"\t\t"<<remblockSize[i];
        }
        else
        {
            cout<<"Not allocated";
        }
        cout<<endl;
    }
}

int main()
{
    int m,n;
    cout<<"Enter the number of blocks : ";
    cin>>m;
    int blockSize[m];
    for(int i = 0 ; i < m ; i++)
    {
        cout<<"Enter block size : "<<i+1<<" : ";
        cin>>blockSize[i];
    }

    cout<<"Enter the number of process : ";
    cin>>n;
    int processSize[n];
    for(int i = 0 ; i < n ; i++)
    {
        cout<<"Enter process size : "<<i+1<<" : ";
        cin>>processSize[i];
    }

    firstFit(blockSize,m,processSize,n);
    return 0;
}
