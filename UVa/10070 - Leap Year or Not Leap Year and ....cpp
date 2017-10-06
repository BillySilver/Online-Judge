#include <iostream>
#include <stdio.h>
#include <string.h>
int Flag, Mod4, Mod100, Mod400, Mod15, Mod55, i, Len, leap, cas;
char A[1000000];

int main() {
	while (~scanf("%s", A)) {
		if (cas++) puts("");
		leap = Flag = Mod4 = Mod100 = Mod400 = Mod15 = Mod55 = 0;
		Len = strlen (A);
		for (i=0; i< Len; i++) {
			Mod4 = ((Mod4 * 10) + (A[i]-'0')) % 4;
			Mod100 = ((Mod100 * 10) + (A[i]-'0')) % 100;
			Mod400 = ((Mod400 * 10) + (A[i]-'0')) % 400;
			Mod15 = ((Mod15 * 10) + (A[i]-'0')) % 15;
			Mod55 = ((Mod55 * 10) + (A[i]-'0')) % 55;
		}
		if ((!Mod4 && Mod100) || !Mod400){
			puts("This is leap year.");
			leap = 1;
			Flag = 1;
		}
		if (!Mod15){
			puts("This is huluculu festival year.");
			Flag = 1;
		}
		if (leap && !Mod55)
			puts("This is bulukulu festival year.");
		if (!Flag)
			puts("This is an ordinary year.");
	}
}