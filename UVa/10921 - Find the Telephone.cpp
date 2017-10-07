#include <iostream>
#include <string>
using namespace std;


int main() {
     int i;
     string s, x1="-01ABCDEFGHIJKLMNOPQRSTUVWXYZ", x2="-0122233344455566677778889999";
     while (cin >> s) {
           for (i = 0; i < s.size(); i++)
                s[i] = x2[x1.find(s[i])];
           cout << s << endl;
     }
}
