class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int rev = 0;
        int size = -1;
        while (num > 0) { 
            rev = rev * 10 + num % 10; 
            num /= 10;
            size++;
        } 

        int mlp = pow(10, size);
        
        while (rev != 0) {
            int n = (rev % 10) * mlp;
            while (n >= 1000) {
                res += "M";
                n -= 1000;
            }
            while (n >= 500) {
                if (n == 900) {
                    res += "CM";
                    n -= 900;
                }
                else {
                    res += "D";
                    n -= 500;
                }
            }
            while (n >= 100) {
                if (n == 400) {
                    res += "CD";
                    n -= 400;
                }
                else {
                    res += "C";
                    n -= 100;
                }
            }
            while (n >= 50) {
                if (n == 90) {
                    res += "XC";
                    n -= 90;
                }
                else {
                    res += "L";
                    n -= 50;
                }
            }
            while (n >= 10) {
                if (n == 40) {
                    res += "XL";
                    n -= 40;
                }
                else {
                    res += "X";
                    n -= 10;
                }
            }
            while (n >= 5) {
                if (n == 9) {
                    res += "IX";
                    n -= 9;
                }
                else {
                    res += "V";
                    n -= 5;
                }
            }
            while (n >= 1) {
                if (n == 4) {
                    res += "IV";
                    n -= 4;
                }
                else {
                    res += "I";
                    n -= 1;
                }
            }
            mlp /= 10;
            rev /= 10;
        }
        return res;
    }
};