#include <iostream>
#include <algorithm>
using namespace std;
int aac[1001], bac[1001], cac[1001], t, sa, sb, sc, da, db, dc, i, cas;
bool solvea[10001], solveb[10001], solvec[10001];

int main() {
	cin >> t;
	while (t--) {
		memset(solvea, 0, sizeof(solvea));
		memset(solveb, 0, sizeof(solveb));
		memset(solvec, 0, sizeof(solvec));
		for (cin>>sa,i=0; i<sa; i++) {
			cin >> aac[i];
			solvea[aac[i]] = true;
		}
		for (cin>>sb,i=0; i<sb; i++) {
			cin >> bac[i];
			solveb[bac[i]] = true;
		}
		for (cin>>sc,i=0; i<sc; i++) {
			cin >> cac[i];
			solvec[cac[i]] = true;
		}
		for (da=i=0; i<sa; i++) {
			if (!solveb[aac[i]]&&!solvec[aac[i]]) da++;
			else aac[i]=20000;
		}
		for (db=i=0; i<sb; i++) {
			if (!solvea[bac[i]]&&!solvec[bac[i]]) db++;
			else bac[i]=20000;
		}
		for (dc=i=0; i<sc; i++) {
			if (!solvea[cac[i]]&&!solveb[cac[i]]) dc++;
			else cac[i]=20000;
		}
		printf("Case #%d:\n", ++cas);
		if (da>db&&da>dc) {
			printf("1 %d ", da);
			sort (aac, aac+sa);
			for (i=0; i<sa&&aac[i]!=20000; i++) 
				printf("%d ", aac[i]);
		}
		else if (db>da&&db>dc) {
			printf("2 %d ", db);
			sort (bac, bac+sb);
			for (i=0; i<sb&&bac[i]!=20000; i++)
				printf("%d ", bac[i]);
		}
		else if (dc>da&&dc>db) {
			printf("3 %d ", dc);
			sort (cac, cac+sc);
			for (i=0; i<sc&&cac[i]!=20000; i++)
				printf("%d ", cac[i]);
		}
		else if (da==db&&db==dc) {
			printf("1 %d ", da);
			sort (aac, aac+sa);
			for (i=0; i<sa&&aac[i]!=20000; i++)
				printf("%d ", aac[i]);
			printf("\n2 %d ", db);
			sort (bac, bac+sb);
			for (i=0; i<sb&&bac[i]!=20000; i++)
				printf("%d ", bac[i]);
			printf("\n3 %d ", dc);
			sort (cac, cac+sc);
			for (i=0; i<sc&&cac[i]!=20000; i++)
				printf("%d ", cac[i]);
		}
		else if (da==db) {
			printf("1 %d ", da);
			sort (aac, aac+sa);
			for (i=0; i<sa&&aac[i]!=20000; i++)
				printf("%d ", aac[i]);
			printf("\n2 %d ", db);
			sort (bac, bac+sb);
			for (i=0; i<sb&&bac[i]!=20000; i++)
				printf("%d ", bac[i]);
		}
		else if (da==dc) {
			printf("1 %d ", da);
			sort (aac, aac+sa);
			for (i=0; i<sa&&aac[i]!=20000; i++)
				printf("%d ", aac[i]);
			printf("\n3 %d ", dc);
			sort (cac, cac+sc);
			for (i=0; i<sc&&cac[i]!=20000; i++)
				printf("%d ", cac[i]);
		}
		else if (db==dc) {
			printf("2 %d ", db);
			sort (aac, aac+sa);
			for (i=0; i<sa&&aac[i]!=20000; i++)
				printf("%d ", bac[i]);
			printf("\n3 %d ", dc);
			sort (cac, cac+sc);
			for (i=0; i<sc&&cac[i]!=20000; i++)
				printf("%d ", cac[i]);
		}
		printf("\n");
	}
}