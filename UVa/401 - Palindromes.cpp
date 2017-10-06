#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool reverse[127][127];
void init();

int main() {
    init();

    string s;
    bool palindrome, mirrored;
    while (cin >> s) {
        palindrome = mirrored = true;
        for (int i = 0; i < ((s.size()+1) >> 1); ++i) {
            if ( s[i] != s[s.size()-1 - i] )
                palindrome = false;

            if ( false == reverse[ s[i] ][ s[s.size()-1 - i] ] )
                mirrored = false;
        }

        cout << s << " -- is ";
        if (palindrome && mirrored)
            puts("a mirrored palindrome.");
        else if (!palindrome && !mirrored)
            puts("not a palindrome.");
        else if (palindrome)
            puts("a regular palindrome.");
        else
            puts("a mirrored string.");
        puts("");
    }
}

void set(char a, char b = ' ') {
    if (' ' == b)
        b = a;
    reverse[a][b] = reverse[b][a] = true;
}

void init() {
    set('A');
    set('E', '3');
    set('H');
    set('I');
    set('J', 'L');
    set('M');
    set('O');
    set('S', '2');
    set('T');
    set('U');
    set('V');
    set('W');
    set('X');
    set('Y');
    set('Z', '5');
    set('1');
    set('8');
}
