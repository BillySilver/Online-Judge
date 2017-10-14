#include <cstdio>
#include <cstring>
#include <algorithm>


char code[51];


int main() {
    while (scanf("%s", code), '#' != *code)
        puts( std::next_permutation(code, code+strlen(code)) ? code : "No Successor" );
}
