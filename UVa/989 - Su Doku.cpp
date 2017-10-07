#include <cstdio>
#include <cstring>
using namespace std;

int s[9][9], i, j, x, y, n, a, b, sum;
bool X[9][10], Y[9][10], SQ[9][10], answer;
struct record {
    int x, y, n;
} space[81];

void sudoku81() {
    for (y=0; y<9; y++) {
        for (x=0; x<9; x++) {
            scanf("%d", &s[y][x]);
            if (s[y][x])
                X[x][s[y][x]] = Y[y][s[y][x]] = SQ[x/3+y/3*3][s[y][x]] = true;
            else {
                space[j].x = x;
                space[j].y = y;
                space[j++].n = 1;
            }
        }
    }
    if (!space[0].n) goto EXIT;
    for (j=0; space[j].x || space[j].y || space[j].n; j++) {
        x = space[j].x;
        y = space[j].y;
        for (; space[j].n<=9; space[j].n++) {
            if (!X[x][space[j].n] && !Y[y][space[j].n] && !SQ[x/3+y/3*3][space[j].n]) {
                s[y][x] = space[j].n;
                X[x][space[j].n] = Y[y][space[j].n] = SQ[x/3+y/3*3][space[j].n] = true;
                break;
            }
        }
        if (space[j].n == 10) {
            if (!j) {
                answer = false;
                goto EXIT;
            }
            space[j--].n = 1;
            x = space[j].x;
            y = space[j].y;
            X[x][space[j].n] = Y[y][space[j].n] = SQ[x/3+y/3*3][space[j].n] = false;
            s[y][x] = 0;
            space[j].n++;
            j--;
        }
    }
EXIT:
    j = 0;
}

bool xyanswer() {
    for (sum=j=0; j<9; sum+=((a) ? s[i][j++] : s[j++][i]));
    return answer = (sum == 45);
}

bool squareanswer() {
    for (sum=0,i=a; i<a+3; i++)
        for (j=b; j<b+3; sum += s[i][j++]);
    return answer = (sum == 45);
}

void sudoku16() {
    for (y=0; y<4; y++) {
        for (x=0; x<4; x++) {
            scanf("%d", &s[y][x]);
            if (s[y][x])
                X[x][s[y][x]] = Y[y][s[y][x]] = SQ[x/2+y/2*2][s[y][x]] = true;
            else {
                space[j].x = x;
                space[j].y = y;
                space[j++].n = 1;
            }
        }
    }
    if (!space[0].n) goto EXIT;
    for (j=0; space[j].x || space[j].y || space[j].n; j++) {
        x = space[j].x;
        y = space[j].y;
        for (; space[j].n<=4; space[j].n++) {
            if (!X[x][space[j].n] && !Y[y][space[j].n] && !SQ[x/2+y/2*2][space[j].n]) {
                s[y][x] = space[j].n;
                X[x][space[j].n] = Y[y][space[j].n] = SQ[x/2+y/3*2][space[j].n] = true;
                break;
            }
        }
        if (space[j].n == 5) {
            if (!j) {
                answer = false;
                goto EXIT;
            }
            space[j--].n = 1;
            x = space[j].x;
            y = space[j].y;
            X[x][space[j].n] = Y[y][space[j].n] = SQ[x/2+y/2*2][space[j].n] = false;
            s[y][x] = 0;
            space[j].n++;
            j--;
        }
    }
EXIT:;
}

bool xyanswer16() {
    for (sum=j=0; j<4; sum+=((a) ? s[i][j++] : s[j++][i]));
    return answer = (sum == 10);
}

bool squareanswer16() {
    for (sum=0,i=a; i<a+2; i++)
        for (j=b; j<b+2; sum += s[i][j++]);
    return answer = (sum == 10);
}

int main() {
    bool isFirstCase = true;
    while (~scanf("%d", &n)) {
        if ( !isFirstCase )
            puts("");
        else
            isFirstCase = false;

        memset(s, 0, sizeof(s));
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        memset(SQ, 0, sizeof(SQ));
        memset(space, 0, sizeof(space));
        answer = true;
        j = 0 ;
        if (n == 3) {
            sudoku81();
            if (answer) {
                for (a=0; answer && a<2; a++)
                    for (i=0; i<9 && xyanswer(); i++);
                for (a=0; answer && a<9; a+=3)
                    for (b=0; b<9 && squareanswer(); b+=3);
            }
            if (answer)
                for (y=0; y<9; y++) {
                    for (x=0; x<9; x++) {
                        printf("%d", s[y][x]);
                        putchar(8 == x ? '\n' : ' ');
                    }
                }
            else printf("NO SOLUTION\n");
        }
        else if (n == 2) {
            sudoku16();
            if (answer) {
                for (a=0; answer && a<2; a++)
                    for (i=0; i<4 && xyanswer16(); i++);
                for (a=0; answer && a<4; a+=2)
                    for (b=0; b<4 && squareanswer16(); b+=2);
            }
            if (answer)
                for (y=0; y<4; y++) {
                    for (x=0; x<4; x++) {
                        printf("%d", s[y][x]);
                        putchar(3 == x ? '\n' : ' ');
                    }
                }
            else printf("NO SOLUTION\n");
        }
        else {
            scanf("%d", &n);
            printf("%s", !n || n == 1 ? "1\n" : "NO SOLUTION\n");
        }
    }
}
