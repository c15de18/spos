#include <iostream>
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], remblockSize[n];
    fill_n(allocation, n, -1);

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i] && (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]))
                bestIdx = j;
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
            remblockSize[i] = blockSize[bestIdx];
        }
    }

    cout << "\nProcess No\tProcess Size\tBlock No\tRemaining Block Size\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\t\t" << remblockSize[i];
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter number of blocks: ";
    cin >> m;
    int blockSize[m];
    for (int i = 0; i < m; i++) {
        cout << "Enter block size " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    cout << "Enter number of processes: ";
    cin >> n;
    int processSize[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter process size " << i + 1 << ": ";
        cin >> processSize[i];
    }

    bestFit(blockSize, m, processSize, n);
    return 0;
}
