class Solution {
    map<int, bool> happy;

public:
    Solution() {
        happy[1] = true;
    }

    bool isHappy(int n) {
        if ( happy.find(n) != happy.end() )
            return happy[n];

        happy[n] = false;
        int sum = 0, ni = n;
        while (ni) {
            sum += (ni % 10) * (ni % 10);
            ni /= 10;
        }
        return happy[n] = isHappy(sum);
    }
};
