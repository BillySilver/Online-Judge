/*
00-1
01-11
02-21
03-1211
04-111221
05-312211
06-13112221
07-1113213211
08-31131211131221
09-13211311123113112211
10-11131221133112132113212221
11-3113112221232112111312211312113211
12-1321132132111213122112311311222113111221131221
13-
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int i1, i2, count, num, n;
	string name[31];
	name[0] = "1";
	for (i1=1; i1<31; i1++) {
		name[i1] = "";
		num = name[i1-1][0] - '0';
		for (count=i2=0; i2<name[i1-1].size()+1; i2++) {
			if (num == name[i1-1][i2] - '0')
				count++;
			else {
				name[i1] += count + '0';
				name[i1] += num + '0';
				count = 1;
				num = name[i1-1][i2] - '0';
			}
		}
	}
	while (cin >> n)
		cout << name[n] << endl;
}