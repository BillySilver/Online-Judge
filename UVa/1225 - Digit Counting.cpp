#include <cstdio>

int main() {
    int t, N;
    int a, b, c;
    int cnt;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (int i = 0; i < 10; ++i) {
            // For the units digit.
            cnt = N / 10;
            if (i <= N % 10 && 0 != i)
                cnt++;

            // N is represented as the form of "a-b-c", where "b" is the currently processing digit.
            // And now, b is the tens digit.
            c = N % 10;
            b = (N - c) / 10 % 10;
            a = N / 100;

            for (int digit = 10; N >= digit; digit *= 10) {
                // from 0 to "[a-1]-9-9_".
                cnt += (a - (0 == i && a > 0)) * digit;
                // from "a-0-0" to "a-[0~b-1]-9_".
                if (i < b && !(0 == i && 0 == a))
                    cnt += digit;
                // from "a-b-0" to "a-b-c".
                else if (i == b && !(0 == i && 0 == a))
                    cnt += (c + 1); // Including c = 0.

                c += b * digit;
                b = a % 10;
                a = a / 10;
            }

            printf("%d", cnt);
            putchar(9 == i ? '\n' : ' ');
        }
    }
}
