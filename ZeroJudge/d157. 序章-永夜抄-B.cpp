#include <iostream>
#include <string>
using namespace std;
string a, b, c;
int wa, wb, wc, n;

inline void Sin (string &d) {
    char ch;
    while (ch=getchar(), ch==',');
    d = "";
	do d.append(1, ch);
    while (ch=getchar(), ch!=44 && ch!=10);
}

int main() {
	while (Sin(a), a[0]!='G') {
		++n;
		Sin(b), Sin(c);
		if (a[0]!='S' && a[0]!='P') {
			printf("十六夜贏了第%d局的比賽\n", n);
			wa++;
		}
		else if (b[0]!='S' && b[0]!='P') {
			printf("紅美鈴贏了第%d局的比賽\n", n);
			wb++;
		}
		else if (c[0]!='S' && c[0]!='P') {
			printf("帕秋莉·諾雷姬贏了第%d局的比賽\n", n);
			wc++;
		}
		else if (a==b) {
			if (a==c)
				printf("第%d局不分勝負\n", n);
			else if (a[1]=='c') {
				if (c[1]=='t') {
					printf("帕秋莉·諾雷姬贏了第%d局的比賽\n", n);
					wc++;
				}
				else {
					printf("帕秋莉·諾雷姬輸了第%d局的比賽\n", n);
					wa++, wb++;
				}
			}
			else if (a[1]=='t') {
				if (c[1]=='a') {
					printf("帕秋莉·諾雷姬贏了第%d局的比賽\n", n);
					wc++;
				}
				else {
					printf("帕秋莉·諾雷姬輸了第%d局的比賽\n", n);
					wa++, wb++;
				}
			}
			else {
				if (c[1]=='c') {
					printf("帕秋莉·諾雷姬贏了第%d局的比賽\n", n);
					wc++;
				}
				else {
					printf("帕秋莉·諾雷姬輸了第%d局的比賽\n", n);
					wa++, wb++;
				}
			}
		}
		else if (a==c) {
			if (a==b)
				printf("第%d局不分勝負\n", n);
			else if (a[1]=='c') {
				if (b[1]=='t') {
					printf("紅美鈴贏了第%d局的比賽\n", n);
					wb++;
				}
				else {
					printf("紅美鈴輸了第%d局的比賽\n", n);
					wa++, wc++;
				}
			}
			else if (a[1]=='t') {
				if (b[1]=='a') {
					printf("紅美鈴贏了第%d局的比賽\n", n);
					wb++;
				}
				else {
					printf("紅美鈴輸了第%d局的比賽\n", n);
					wa++, wc++;
				}
			}
			else {
				if (b[1]=='c') {
					printf("紅美鈴贏了第%d局的比賽\n", n);
					wb++;
				}
				else {
					printf("紅美鈴輸了第%d局的比賽\n", n);
					wa++, wc++;
				}
			}
		}
		else if (b==c) {
			if (a==b)
				printf("第%d局不分勝負\n", n);
			else if (a[1]=='c') {
				if (b[1]=='a') {
					printf("十六夜贏了第%d局的比賽\n", n);
					wa++;
				}
				else {
					printf("十六夜輸了第%d局的比賽\n", n);
					wb++, wc++;
				}
			}
			else if (a[1]=='t') {
				if (b[1]=='c') {
					printf("十六夜贏了第%d局的比賽\n", n);
					wa++;
				}
				else {
					printf("十六夜輸了第%d局的比賽\n", n);
					wb++, wc++;
				}
			}
			else {
				if (b[1]=='t') {
					printf("十六夜贏了第%d局的比賽\n", n);
					wa++;
				}
				else {
					printf("十六夜輸了第%d局的比賽\n", n);
					wb++, wc++;
				}
			}
		}
		else
			printf("第%d局不分勝負\n", n);
	}
	printf("十六夜總計贏了%d局比賽\n紅美鈴總計贏了%d局比賽\n帕秋莉·諾雷姬總計贏了%d局比賽\n", wa, wb, wc);
	Sin(a);
	printf("%s", wa>wb&&wa>wc ? "趕上旅程" : "繼續做家事");
}