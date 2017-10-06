#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    string word[1000], sortedWord[1000], testWord, sortedTestWord;
    int cnt;
    cin >> m;
    while (m--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> word[i];
            sortedWord[i] = word[i];
            sort(sortedWord[i].begin(), sortedWord[i].end());
        }

        while (cin >> testWord, "END" != testWord) {
            printf("Anagrams for: %s\n", testWord.c_str());
            sortedTestWord = testWord;
            sort(sortedTestWord.begin(), sortedTestWord.end());

            cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (sortedTestWord == sortedWord[i])
                    printf("  %d) %s\n", ++cnt, word[i].c_str());
            }
            if (0 == cnt)
                printf("No anagrams for: %s\n", testWord.c_str());
        }

        if (m != 0)
            puts("");
    }
}
