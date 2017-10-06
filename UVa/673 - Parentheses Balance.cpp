#include <iostream>
#include <cstdio>
using namespace std;

bool parenthesesBalance(char *in) {
    int sp = 0;
    char stk[200];

    for (int i = 0; in[i]; ++i) {
        switch (in[i]) {
            case '(':
                stk[sp++] = '(';
                break;
            case '[':
                stk[sp++] = '[';
                break;
            case ')':
                if (--sp < 0)
                    return false;
                if (stk[sp] != '(')
                    return false;
                break;
            case ']':
                if (--sp < 0)
                    return false;
                if (stk[sp] != '[')
                    return false;
                break;
        }
    }

    return 0 == sp;
}

int main() {
    int n;
    char in[200];
    cin >> n;
    getchar();
    while (n--) {
        gets(in);
        puts(parenthesesBalance(in) ? "Yes" : "No");
    }
}
