#include <cstdio>
#include <cctype>   // for tolower()
#include <string>
#include <map>
#include <algorithm>


using std::string;

struct Team {
    string name;
    int nPoint, nWin, nTie, nLose, nGIn, nGOut;

    Team() { nPoint = nWin = nTie = nLose = nGIn = nGOut = 0; }
    void reset() { nPoint = nWin = nTie = nLose = nGIn = nGOut = 0; }

    void update(int g1, int g2) {
        nPoint += (g1 > g2) ? 3 : (g1 < g2) ? 0 : 1;
        nWin   += !!(g1 > g2);
        nTie   += !!(g1 == g2);
        nLose  += !!(g1 < g2);
        nGIn   += g1;
        nGOut  += g2;
    }
} records[30];

bool cmp(int a, int b) {
    Team const &record1 = records[a];
    Team const &record2 = records[b];

    // 1. Most points earned.
    if ( record1.nPoint != record2.nPoint )
        return record1.nPoint > record2.nPoint;

    // 2. Most wins.
    if ( record1.nWin != record2.nWin )
        return record1.nWin > record2.nWin;

    // 3. Most goal difference (i.e. goals scored - goals against)
    int nGDiff1 = record1.nGIn - record1.nGOut;
    int nGDiff2 = record2.nGIn - record2.nGOut;
    if ( nGDiff1 != nGDiff2 )
        return nGDiff1 > nGDiff2;

    // 4. Most goals scored.
    if ( record1.nGIn != record2.nGIn )
        return record1.nGIn > record2.nGIn;

    // 5. Less games played.
    int nGame1 = record1.nWin + record1.nTie + record1.nLose;
    int nGame2 = record2.nWin + record2.nTie + record2.nLose;
    if ( nGame1 != nGame2 )
        return nGame1 < nGame2;

    // 6. Lexicographic order. (case insensitive)
    string const &team1 = record1.name;
    string const &team2 = record2.name;
    int size = team1.size() < team2.size() ? team1.size() : team2.size();
    for (int i = 0; i < size; ++i)
        if ( tolower(team1[i]) != tolower(team2[i]) )
            return tolower(team1[i]) < tolower(team2[i]);
    return team1.size() < team2.size();
}


int main() {
    int n, t, g, g1, g2;
    int nT1, nT2;
    char buf[101];
    string team1, team2;
    int records_idx[30];

    scanf("%d ", &n);
    while (n--) {
        scanf("%[^\n]\n", buf);         // without newline character.
        puts(buf);

        scanf("%d ", &t);
        std::map<string, int> team_no;
        for (int i = 0; i < t; ++i) {
            scanf("%[^\n]\n", buf);     // Team name may contain whitespace.
            records[i].reset();
            records[i].name = buf;
            records_idx[i]  = i;
            team_no[ records[i].name ] = i;
        }

        scanf("%d ", &g);
        while (g--) {
            scanf("%[^#]#%d@%d#%[^\n]\n", buf, &g1, &g2, buf+31);
            team1 = buf, team2 = (buf + 31);
            nT1 = team_no[team1];
            nT2 = team_no[team2];

            records[nT1].update(g1, g2);
            records[nT2].update(g2, g1);
        }

        std::sort(records_idx, records_idx+t, cmp);

        for (int i = 0; i < t; ++i) {
            Team const &record = records[ records_idx[i] ];
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                   i+1, record.name.c_str(), record.nPoint,
                   record.nWin + record.nTie + record.nLose, record.nWin, record.nTie, record.nLose,
                   record.nGIn - record.nGOut, record.nGIn, record.nGOut);
        }

        if (n)
            putchar(10);
    }
}
