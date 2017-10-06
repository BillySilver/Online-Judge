#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF -1270000
using namespace std;

int main() {
    int n;
    int arr[100][100];
    int rowSum[100][100];
    int globalMaxSum, localMaxSum, rowSumPart;

    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
                if (0 == j)
                    rowSum[i][0] = arr[i][0];
                else
                    rowSum[i][j] = rowSum[i][j-1] + arr[i][j];
            }
        }

        globalMaxSum = INF;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = j1; j2 < n; ++j2) {
                // Kadane's Algorithm. (DP)
                localMaxSum = INF;
                for (int i = 0; i < n; ++i) {
                    if (0 == j1)
                        rowSumPart = rowSum[i][j2];
                    else
                        rowSumPart = rowSum[i][j2] - rowSum[i][j1 - 1];

                    localMaxSum = max(localMaxSum + rowSumPart, rowSumPart);
                    globalMaxSum = max(globalMaxSum, localMaxSum);
                }
            }
        }

        cout << globalMaxSum << endl;
    }
}
