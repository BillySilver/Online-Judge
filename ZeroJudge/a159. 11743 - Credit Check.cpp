#include <cstdio>


int main() {
    int n, credit, dSum;
    scanf("%d", &n);
    while (n--) {
        dSum = 0;
        for (int i = 0; i < 4; i++) {
            scanf("%d", &credit);
            for (int j = 0; j < 4; j++) {
                if (j & 1)
                    dSum += (credit % 5) * 2 + (5 <= credit % 10);
                else
                    dSum += credit % 10;
                credit /= 10;
            }
        }

        puts( dSum % 10 ? "Invalid" : "Valid" );
    }
}
