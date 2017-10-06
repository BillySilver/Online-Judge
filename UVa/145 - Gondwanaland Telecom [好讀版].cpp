#include <cstdio>
#include <algorithm>

// 0, 600, 840, 1440.
const int Min[4] = {0, 10*60, 14*60, 24*60};
const double Charges[5][3] = {
    {0.10, 0.06, 0.02},
    {0.25, 0.15, 0.05},
    {0.53, 0.33, 0.13},
    {0.87, 0.47, 0.17},
    {1.44, 0.80, 0.30}
};

char step, strPhone[9];
int hStart, mStart, hEnd, mEnd;
int mDur, t[3];
double money;

int main() {
    while (step = getchar(), step != '#') {
        scanf("%s %d %d %d %d",
            &strPhone,
            &hStart,
            &mStart,
            &hEnd,
            &mEnd
        ), getchar();
        mStart += (hStart + 16) % 24 * 60;
        mEnd   += (hEnd + 16) % 24 * 60;
        mDur   = (mEnd - mStart + Min[3] - 1) % Min[3] + 1;
        // Sure to mEnd > mStart.
        mEnd   = mStart + mDur;

        money = 0;
        for (int i = 0; i < 3; ++i) {
            t[i] = 0;

            if ( Min[i] <= mStart && mStart < Min[i+1] ) {
                t[i] += std::min(mEnd, Min[i+1]) - mStart;
            } else if ( mStart < Min[i] && Min[i] < mEnd ) {
                t[i] += std::min(mEnd, Min[i+1]) - Min[i];
            }

            if ( (Min[3] + Min[i]) <= mEnd )
                t[i] += std::min(mEnd - Min[3], Min[i+1]) - Min[i];

            money += Charges[step - 'A'][i] * t[i];
        }

        printf("%10s%6d%6d%6d%3c%8.2f\n",
            strPhone,
            t[0],
            t[1],
            t[2],
            step,
            money
        );
    }
}
