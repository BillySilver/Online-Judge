class Solution {
public:
    string intToRoman(int num) {
        int digit[7] = {1, 5, 10, 50, 100, 500, 1000};
        char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int nowDigit;
        string result = "";

        if ( digit[6] <= num ) {
            result.append(num/digit[6], 'M');
            num %= digit[6];
        }

        for (int i = 4; i >= 0; i -= 2) {
            nowDigit = num / digit[i];
            if ( 0 == nowDigit )
                continue;

            if ( 4 == nowDigit % 5 ) {
                result += roman[i];
                result += (4 == nowDigit) ? roman[i+1] : roman[i+2];
            }
            else {
                if ( 5 <= nowDigit )
                    result += roman[i+1];

                result.append(nowDigit % 5, roman[i]);
            }

            num %= digit[i];
        }

        return result;
    }
};
