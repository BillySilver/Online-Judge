#include <iostream>
using namespace std;
int T, dn, mn, yn, db, mb, yb, status, old, c;
char g;
void check() {
	if (yn <= yb) {
		if (yn == yb) {
			if (mn <= mb) {
				if (mn == mb) {
					if (dn >= db)
						goto OK;
				}
			}
			else goto OK;
		}
		status = 1;
		return;
	}
	if (yn-131 >= yb) {
		if (yn-131 == yb) {
			if (mn >= mb) {
				if (mn == mb) {
					if (dn < db)
						goto OK;
				}
			}
			else goto OK;
		}
		status = 2;
		return;
	}
OK:
	old = yn-yb;
	if (mn <= mb) {
		if (mn==mb) {
			if (dn >= db)
				return;
		}
		old--;
	}
}
int main() {
	for (scanf("%d",&T); T--; ) {
		c++;
		status = 0;
		scanf("%d%c%d%c%d",&dn,&g,&mn,&g,&yn);
		scanf("%d%c%d%c%d",&db,&g,&mb,&g,&yb);
		check();
		if (status) printf("Case #%d: %s birth date\n", c, status==1 ? "Invalid" : "Check");
		else printf("Case #%d: %d\n", c, old);
	}
}
