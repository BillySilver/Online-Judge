#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline void rev(char *in, int l, int r) {
    while ( l < r )
        swap(in[l++], in[r--]);
}

int main() {
    char in[1000];
    int size, first_not_space;
    while (gets(in)) {
        size = strlen(in);
        first_not_space = 0;
        for (int i = 1; i < size; ++i) {
            if (' ' != in[i])
                continue;

            rev(in, first_not_space, i-1);

            while (i < size && ' ' == in[++i]);
            first_not_space = i;
        }

        if (' ' != in[size-1])
            rev(in, first_not_space, size-1);

        puts(in);
    }
}
