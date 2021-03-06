#include <iostream>
int m[5][3]={{10,6,2},{25,15,5},{53,33,13},{87,47,17},{144,80,30}}, sh, sm, eh, em, allm, am, bm, cm, money, i, e;
const int D = 480, E = 1080, N = 1320, ALL = 1440;
char q, cn[9], sp[4][4];
int main () {
	while (q=getchar(), q!='#') {
		scanf("%s%d%d%d%d", &cn, &sh, &sm, &eh, &em), getchar();
		sm += sh * 60;
		em += eh * 60;
		allm = (em - sm + ALL) % ALL;
		am = bm = cm = 0;
		//480~1080 1080~1320 1320~480
		if (sm >= N) {
			if (sm+allm < ALL)
				cm = allm;
			else {
				cm = ALL - sm;
				allm -= cm;
				if (allm < D)
					cm += allm;
				else {
					cm += D;
					if (allm < E)
						am = allm - D;
					else {
						am = E - D;
						if (allm < N)
							bm = allm - E;
						else {
							bm = N - E;
							cm += allm - N;
						}
					}
				}
			}
		}
		else if (sm >= E) {
			if (sm+allm < N)
				bm = allm;
			else {
				bm = N - sm;
				if (sm+allm < ALL)
					cm = sm+allm - N;
				else {
					cm = ALL - N;
					allm -= ALL - sm;
					if (allm < D)
						cm += allm;
					else {
						cm += D;
						if (allm < E)
							am = allm - D;
						else {
							am = E - D;
							bm += allm - E;
						}
					}
				}
			}
		}
		else if (sm >= D) {
			if (sm+allm < E)
				am = allm;
			else {
				am = E - sm;
				if (sm+allm < N)
					bm = sm+allm - E;
				else {
					bm = N - E;
					if (sm+allm < ALL)
						cm = sm+allm - N;
					else {
						cm = ALL - N;
						allm -= ALL - sm;
						if (allm < D)
							cm += allm;
						else {
							cm += D;
							am += allm - D;
						}
					}
				}
			}
		}
		else {
			if (sm+allm < D)
				cm = allm;
			else {
				cm = D - sm;
				if (sm+allm < E)
					am = sm+allm - D;
				else {
					am = E - D;
					if (sm+allm < N)
						bm = sm+allm - E;
					else {
						bm = N - E;
						cm += sm+allm - N;
					}
				}
			}
		}
		money = m[q-65][0] * am + m[q-65][1] * bm + m[q-65][2] * cm;
		for (i=0,e=1000; e>am; i++,e/=10)
			sp[0][i] = 32;
		sp[0][!am ? i-1 : i] = 0;
		for (i=0,e=1000; e>bm; i++,e/=10)
			sp[1][i] = 32;
		sp[1][!bm ? i-1 : i] = 0;
		for (i=0,e=1000; e>cm; i++,e/=10)
			sp[2][i] = 32;
		sp[2][!cm ? i-1 : i] = 0;
		for (i=0,e=1000000; e>money&&e>100; i++,e/=10)
			sp[3][i] = 32;
		sp[3][i] = 0;
		printf("%s  %s%d  %s%d  %s%d  %c%s%d.", cn, sp[0], am, sp[1],bm, sp[2], cm, q, sp[3], money/100);
		money %= 100;
		putchar(money/10|48), putchar(money%10|48), putchar(10);
	}
}