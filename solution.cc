// Given an integer, convert it to a roman numeral.

// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    string intToRoman(int num) {
        char romanChars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int curPos = 0;
        string res("");
        while(num) {
            int digit = num%10;
            switch(digit) {
                case 1:
                case 2:
                case 3:
                    res.append(digit, romanChars[curPos]);
                    break;
                case 4:
                    res.append(1, romanChars[curPos+1]);
                    res.append(1, romanChars[curPos]);
                    break;
                case 5:
                    res.append(1, romanChars[curPos+1]);
                    break;
                case 6:
                case 7:
                case 8:
                    res.append(digit-5, romanChars[curPos]);
                    res.append(1, romanChars[curPos+1]);
                    break;
                case 9:
                    res.append(1, romanChars[curPos+2]);
                    res.append(1, romanChars[curPos]);
                    break;
                case 0:
                    break;
            }
            curPos += 2;
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
