#include <iostream>
#include <string>
using namespace std;


bool minus_sign, Multiply, AsmallthanB;

string SIMinus(string a, string b) {    // StringIntegerMinus
    int i;
    if (!Multiply) {
        minus_sign = false;
        if (a[0] == '-') {
            a.erase(0, 1);
            if (b[0] == '-') {
                b.erase(0, 1);
                swap(a, b);             // -a-(-b)=b-a
            }
            else {                      // -a-b=-(a+b)
                minus_sign = true;
                goto SIPlus;
            }
        }
        else if (b[0] == '-') {
            b.erase(0, 1);
SIPlus:
            if (a.size() > b.size())                    // 以下為SIPlus(a, b)
                b.insert(0, a.size()-b.size(), '0');    // 從第0位開始 插入長度差個數的'0'
            else if (a.size() < b.size())
                a.insert(0, b.size()-a.size(), '0');
            for (i=a.size()-1; i>0; i--) {
                a[i] = a[i] - '0' + b[i] - '0';
                a[i-1] += a[i] / 10;
                a[i] %= 10;
            }
            a[i] = a[i] - '0' + b[i] - '0';
            if (a[i]/10) {
                a.insert(0, 1, a[0]/10);
                a[i+1] %= 10;
            }
            for (i=0; i<a.size(); i++)
                a[i] += '0';
            if (minus_sign) a.insert(0, 1, '-');
            return a;
        }
        if (a.size() > b.size())
            b.insert(0, a.size()-b.size(), '0');        // 從第0位開始 插入長度差個數的'0'
        else if (a.size() < b.size())
            a.insert(0, b.size()-a.size(), '0');
        for (i=a.size()-1; i>=0; i--) {
            a[i] -= '0';
            b[i] -= '0';
        }
        for (i=0; i<a.size(); i++) {                    // 確保 a >= b, minus_sign記負號用
            if (a[i] > b[i]) break;
            if (a[i] == b[i]) continue;
            minus_sign = true;
            swap(a, b);
            break;
        }
        for (i=a.size()-1; i>=0; i--) {
            while (a[i] < b[i]) {
                a[i] += 10;
                a[i-1] -= 1;
            }
            a[i] -= b[i];
        }
        for (i=0; i<a.size()-1 && !a[i]; i++);
        a.erase(0, i);                                  // 清除前面所剩的0
        for (i=0; i<a.size(); i++)
            a[i] += '0';
        if (minus_sign) a.insert(0, 1, '-');
    }
    else {
        if (a.size() > b.size())
            b.insert(0, a.size()-b.size(), 0);
        for (i=0; i<a.size(); i++) {
            if (a[i] > b[i]) break;
            if (a[i] == b[i]) continue;
            AsmallthanB = true;
            return a;
        }
        for (i=a.size()-1; i>=0; i--) {
            while (a[i] < b[i]) {
                a[i] += 10;
                a[i-1] -= 1;
            }
            a[i] -= b[i];
        }
    }
    return a;
}

string SIPlus(string a, string b) {     // StringIntegerPlus
    int i;
    if (!Multiply) {
        minus_sign = false;
        if (a[0] == '-') {
            a.erase(0, 1);
            if (b[0] == '-') {
                b.erase(0, 1);
                minus_sign = true;      // -a+(-b)=-(a+b)
            }
            else return SIMinus(b, a);  // -a+b=b-a
        }
        else if (b[0] == '-') {
            b.erase(0, 1);
            return SIMinus(a, b);       // a+(-b)=a-b
        }
        if (a.size() > b.size())
            b.insert(0, a.size()-b.size(), '0');    // 從第0位開始 插入長度差個數的'0'
        else if (a.size() < b.size())
            a.insert(0, b.size()-a.size(), '0');
        for (i=a.size()-1; i>0; i--) {
            a[i] = a[i] - '0' + b[i] - '0';
            a[i-1] += a[i] / 10;
            a[i] %= 10;
        }
        a[i] = a[i] - '0' + b[i] - '0';
        if (a[i]/10) {
            a.insert(0, 1, a[0]/10);
            a[i+1] %= 10;
        }
        for (i=0; i<a.size(); i++)
            a[i] += '0';
        if (minus_sign) a.insert(0, 1, '-');
    }
    else {
        if (a.size() > b.size())
            b.insert(0, a.size()-b.size(), 0);       // 從第0位開始 插入長度差個數的0
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
    }
    return a;
}

string SIMultiply(string a, string b) { // StringIntegerMultiply
    int i;
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
    for (i=a.size()-1; i>=0; i--)
        a[i] -= '0';
    for (i=b.size()-1; i>=0; i--)
        b[i] -= '0';
    m[0].insert(0, 1, 0);
    m[1].assign(a.begin(), a.end() );
    Multiply = true;
    for (i=2; i<10; i++)
        m[i] += SIPlus(m[i-1], a);
    for (i=b.size()-1; i>=0; i--){
        a = m[b[i]];
        a.append(b.size()-1-i, 0);
        r = SIPlus(a, r);
    }
    Multiply = false;
    for (i=0; i<r.size(); i++)
        r[i] += '0';
    if (minus_sign) r.insert(0, 1, '-');
    return r;
}

string SIDivide(string a, string b, bool remain=0) {    // StringIntegerDivide,remain ? 求餘數 : 求商數
    int i, j;
    string m, r;
    bool remainsign = minus_sign = false;
    if (b == "0") return "Error!";
    if (a[0]=='-') {
        a.erase(0, 1);
        minus_sign = true;
        remainsign = true;
    }
    if (b[0]=='-') {
        b.erase(0, 1);
        minus_sign = !minus_sign;
    }
    if (a.size() < b.size())
        return remain ? string(remainsign ? "-" : "") + a : "0";
    if (a.size() == b.size()) {
        for (i=0; i<a.size(); i++) {
            if (a[i] > b[i]) break;
            if (a[i] == b[i]) continue;
            return remain ? string(remainsign ? "-" : "") + a : "0";
        }
    }
    for (i=a.size()-1; i>=0; i--)
        a[i] -= '0';
    for (i=b.size()-1; i>=0; i--)
        b[i] -= '0';
    m = b;
    m.append(a.size()-b.size(), 0);
    Multiply = true;
    AsmallthanB = false;
    for (j=a.size()+1; !(j==b.size() && AsmallthanB); j--) {
        AsmallthanB = false;
        for (i=0; i<10; i++) {      // a一直減m，直到a<m，此時i=a/m;
            a = SIMinus(a, m);
            if (AsmallthanB) break;
        }
        if (i==10) i--;             // i是直接減9遍才跳出會變成10
        if (!a[0] && a.size()!=1)   // a前面減到變0時刪掉一個
            a.erase(0, 1);
        r.append(1, i);
        m.erase(m.size()-1);        // m/=10
    }
    Multiply = false;
    if (!remain) {
        for (i=0; i<r.size()-1 && !r[i]; i++);
        r.erase(0, i);              // 清除前面所剩的0
        for (i=0; i<r.size(); i++)
            r[i] += '0';
        if (minus_sign) r.insert(0, 1, '-');
        return r;
    }
    else {
        for (i=0; i<a.size()-1 && !a[i]; i++);
        a.erase(0, i);              // 清除前面所剩的0
        for (i=0; i<a.size(); i++)
            a[i] += '0';
        if (remainsign && a!="0") a.insert(0, 1, '-');
        return a;
    }
}


int main() {
    string s;
    while (cin >> s)
        if (s=="0")
            puts("1");
        else
            // (s + 2) * s - (s * 3) + 2.
            // Or, (s * 2) + (s - 2) * (s - 1).
            // = s^2 -s + 2.
            puts(SIPlus(SIMinus(SIMultiply(SIPlus(s, "2"), s) , SIMultiply(s, "3")), "2").c_str());
}
