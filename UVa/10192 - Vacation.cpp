#include <iostream>
#include <string>
using namespace std;


int main() {
    int C[101][101], tc = 1, i, j;
    string X, Y;
    while (getline(cin, X), X != "#") {
        getline(cin, Y);
        for (i = 0; i <= X.size(); i++) C[i][0] = 0;
        for (j = 1; j <= Y.size(); j++) C[0][j] = 0;

        for (i = 1; i <= X.size(); i++)
            for (j = 1; j <= Y.size(); j++)
                if (X[i - 1] == Y[j - 1])
                    C[i][j] = C[i-1][j-1] + 1;
                else
                    C[i][j] = max(C[i][j-1], C[i-1][j]);
        cout << "Case #" << tc++ << ": you can visit at most " << C[X.size()][Y.size()] << " cities.\n";
    }
}
