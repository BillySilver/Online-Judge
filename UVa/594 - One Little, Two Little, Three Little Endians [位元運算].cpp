#include <cstdio>


int main() {
    unsigned endian1, endian2;      // To avoid ">> i*8" arithmetically.
    const int mask = (1 << 8) - 1;

    while (~scanf("%d", &endian1)) {
        endian2 = 0;
        for (int i = 0; i < 4; ++i)
            (endian2 <<= 8) |= (endian1 & (mask << i*8)) >> i*8;

        printf("%d converts to %d\n", endian1, endian2);
    }
}
