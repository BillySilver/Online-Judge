class Solution {
 public:
    int calculate(string s) {
        deque<int> num;
        deque<char> opr;
        int result = 0;
        char oprtmp;
        for (int i = 0; i < s.size(); ++i) {
            if ( ' ' == s[i] )
                continue;

            if ( isdigit(s[i]) ) {
                result = 0;
                while (i < s.size() && isdigit(s[i]))
                    (result *= 10) += s[i++]^48;
                --i;

                if ( opr.size() > 0 ) {
                    oprtmp = opr.back();
                    if ( '+' == oprtmp ) {
                        result = num.back() + result;
                        num.pop_back();
                        opr.pop_back();
                    } else if ( '-' == oprtmp ) {
                        result = num.back() - result;
                        num.pop_back();
                        opr.pop_back();
                    }
                }
                num.push_back(result);
            } else {
                if ( ')' == s[i] ) {
                    opr.pop_back();

                    if ( opr.size() > 0 ) {
                        oprtmp = opr.back();
                        if ( '+' == oprtmp ) {
                            result = num.back();
                            num.pop_back();
                            result = num.back() + result;
                            num.pop_back();
                            opr.pop_back();
                            num.push_back(result);
                        } else if ( '-' == oprtmp ) {
                            result = num.back();
                            num.pop_back();
                            result = num.back() - result;
                            num.pop_back();
                            opr.pop_back();
                            num.push_back(result);
                        }
                    }
                } else {
                    opr.push_back(s[i]);
                }
            }
        }
        return num.front();
    }
};
