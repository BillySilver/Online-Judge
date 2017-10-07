#include <iostream>
#include <string>
using namespace std;


bool minus_sign;

string SMPlus(string a, string b) {         // StringMathPlus
    int i;
    if (a.size() > b.size())
        b.insert(0, a.size()-b.size(), 0);  // 從第0位開始 插入長度差個數的0
    else if (a.size() < b.size())
        a.insert(0, b.size()-a.size(), 0);
    for (i=a.size()-1; i>0; i--) {
        a[i] = a[i] + b[i];
        a[i-1] += a[i] / 10;
        a[i] %= 10;
    }
    a[i] = a[i] + b[i];
    if (a[i]/10) {
        a.insert(0, 1, a[0]/10);
        a[i+1] %= 10;
    }
    return a;
}

string SMMultiply(string a, string b) {     // StringmMathMultiply
    int i, adot, bdot;
    string m[10], r;
    minus_sign = false;
    if (a == "0" || b == "0")
        return "0";
    if (a[0] == '-') {
        a.erase(0, 1);
        minus_sign = true;
    }
    if (b[0] == '-') {
        b.erase(0, 1);
        minus_sign = !minus_sign;
    }
    adot = a.find('.') == string::npos ? 0 : a.size() - a.find('.');
    bdot = b.find('.') == string::npos ? 0 : b.size() - b.find('.');
    a.erase(a.size()-adot, 1) , b.erase(b.size()-bdot, 1);
    adot -= !(!adot);
    bdot -= !(!bdot);
    for (i=a.size()-1; i>=0; i--)
        a[i] -= '0';
    for (i=b.size()-1; i>=0; i--)
        b[i] -= '0';
    m[0].insert(0, a.size(), 0);
    m[1].assign(a.begin(), a.end());
    for (i=2; i<10; i++)
        m[i] += SMPlus(m[i-1], a);
    for (i=b.size()-1; i>=0; i--){
        a = m[b[i]];
        a.append(b.size()-1-i, 0);
        r = SMPlus(a, r);
    }
    for (i=0; i<r.size(); i++)
        r[i] += '0';
    r.insert(r.size()-adot-bdot, 1, '.');
    for (i=r.size()-1; r[i]=='0'; i--)
        r.erase(r.size()-1);
    if (r[r.size()-1] == '.') r.erase(r.size()-1);
    for (i=0; i<r.size()-1 && r[i]=='0'; i++);
    r.erase(0, i);
    if (r[0] == '.') r.insert(0, 1, '0');
    if (minus_sign) r.insert(0, 1, '-');
    return r;
}


int main() {
    int n, i, dot;
    string s, ans;
    while (cin >> s) {
        cin >> n;
        ans = s;
        for (i = 1; i < n; i++)
            ans = SMMultiply(s, ans);

        // Remove the suffix zeros following the decimal point.
        dot = ans.find('.') == string::npos ? ans.size() : ans.find('.');
        while ( '0' == ans[ans.size()-1] && dot < ans.size() )
            ans.resize(ans.size() - 1);

        if (ans.size() > 1 && ans[0] == 48 && ans[1] == '.')
            ans.erase(0, 1);
        cout << ans << endl;
    }
}
