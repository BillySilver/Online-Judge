class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman2Digit;
        roman2Digit['I'] = 1;
        roman2Digit['V'] = 5;
        roman2Digit['X'] = 10;
        roman2Digit['L'] = 50;
        roman2Digit['C'] = 100;
        roman2Digit['D'] = 500;
        roman2Digit['M'] = 1000;

        int ans = 0;
        int tmp = 1e5;
        char now;
        for (int i=0; i<s.size(); ++i) {
            now = s[i];
            if ( ('I' == now || 'X' == now || 'C' == now) && tmp > roman2Digit[now] ) {
                tmp = roman2Digit[now];
                ans += tmp;
            }
            else {
                if ( tmp != 1e5 ) {
                    if ( 1 < roman2Digit[now] / tmp ) {
                        ans -= tmp << 1;
                    }
                }
                ans += roman2Digit[now];
                tmp = 1e5;
            }
        }

        return ans;
    }
};
