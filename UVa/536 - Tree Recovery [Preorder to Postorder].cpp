#include <iostream>
#include <string>
using namespace std;

string pre, in;

void pre2post(int preL, int preR, int inL, int inR) {
    if (preL > preR)
        return;

    char cRoot = pre[preL];
    int rootIn = in.find(cRoot);
    int lenL = rootIn - inL;
    int lenR = inR - rootIn;

    pre2post(preL+1, preL+lenL, inL, rootIn-1);
    pre2post(preR-lenR+1, preR, rootIn+1, inR);
    cout << cRoot;
}

int main() {
    while (cin >> pre >> in) {
        pre2post(0, pre.size()-1, 0, in.size()-1);
        cout << endl;
    }
}
