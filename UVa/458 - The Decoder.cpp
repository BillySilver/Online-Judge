#include <cstdio>

int main() {
    int i;
    char in[1000];
    while (gets(in)) {
        for (i=0; in[i]; ++i)
            in[i] -= 7;
        puts(in);
    }
}
