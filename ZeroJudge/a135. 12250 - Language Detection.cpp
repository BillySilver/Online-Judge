#include <iostream>
#include <cstdio>
#include <string>


std::string maps[6][2] = {
    { "HELLO", "ENGLISH" },
    { "HOLA", "SPANISH" },
    { "HALLO", "GERMAN" },
    { "BONJOUR", "FRENCH" },
    { "CIAO", "ITALIAN" },
    { "ZDRAVSTVUJTE", "RUSSIAN" }
};


int main() {
    int cases = 0;
    std::string s, lang;
    while (std::cin >> s, "#" != s) {
        lang = "UNKNOWN";
        for (int i = 0; i < 6; ++i)
            if ( s == maps[i][0] )
                lang = maps[i][1];

        printf("Case %d: %s\n", ++cases, lang.c_str());
    }
}
