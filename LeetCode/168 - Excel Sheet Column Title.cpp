class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n) {
            ans.insert(0, 1, (n - 1)%26 + 'A');
            n = (n - 1) / 26;
        }
        return ans;
    }
};
