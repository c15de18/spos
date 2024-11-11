#include<iostream>
using namespace std;

void worstFit(int blockSize[],int m,int processSize[],int n)
{
    int allocation[n],remblockSize[n];
    fill_n(allocation,n,-1);

    for(int i = 0; i < n ; i++)
    {
        int worstIdx = -1;
        for(int j = 0; j < m ; j++)
        {
            if(blockSize[j] > processSize[i] && (worstIdx == -1 || blockSize[worstIdx] < blockSize[j]))
            {
                worstIdx = j;
            }
        }
    
        if(worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
            remblockSize[i] = blockSize[worstIdx];
        }
        else
        {
            remblockSize[i] = 0;
        }
    }
    cout<<"\nProcess no\tProcess Size\tBlock no\tRemaining block size\n";
    for(int i = 0; i < n ; i++)
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
    cout<<"Enter the number of blocks : "<<endl;
    cin>>m;
    int blockSize[m];
    for(int i = 0; i < m ; i++)
    {
        cout<<"Enter block size "<<i+1<< " : ";
        cin>>blockSize[i];
    }

    cout<<"Enter the number of process : "<<endl;
    cin>>n;
    int processSize[n];
    for(int i = 0; i < n ; i++)
    {
        cout<<"Enter process size "<<i+1<< " : ";
        cin>>processSize[i];
    }

    worstFit(blockSize,m,processSize,n);

    return 0;
}