#include <iostream>
#include <string>
using namespace std;

struct dice {
    int topSide[2];
    int northSide[2];
    int westSide[2];

    dice(int top, int north, int west) {
        topSide[0]   = top;
        topSide[1]   = 7 - top;
        northSide[0] = north;
        northSide[1] = 7 - north;
        westSide[0]  = west;
        westSide[1]  = 7 - west;
    }

    void tumble(int *a, int *b) {
        int tmp = a[0];
        a[0] = b[0];
        b[0] = a[1];
        a[1] = b[1];
        b[1] = tmp;
    }

    void north() {
        tumble(northSide, topSide);
    }

    void south() {
        tumble(topSide, northSide);
    }

    void west() {
        tumble(westSide, topSide);
    }

    void east() {
        tumble(topSide, westSide);
    }
};

int main() {
    int n;
    string command;
    while (cin >> n, n) {
        dice newDice(1, 2, 3);
        while (n--) {
            cin >> command;
            if ("north" == command)
                newDice.north();
            else if ("south" == command)
                newDice.south();
            else if ("west" == command)
                newDice.west();
            else if ("east" == command)
                newDice.east();
        }
        cout << newDice.topSide[0] << endl;
    }
}
