class Solution:
    def romanToInt(self, s: str) -> int:
        num = 0
        l = []
        
        d = {"I": 1,
             "V": 5,
             "X": 10,
             "L": 50,
             "C": 100,
             "D": 500,
             "M": 1000,
             "IV": 4,
             "IX": 9,
             "XL": 40,
             "XC": 90,
             "CD": 400,
             "CM": 900}

        l_ = list(s)
        size = len(l_)
        dummy = "0"*size
        
        while s != dummy:
            for i in reversed(d):
                t = s.find(i)

                if t != -1:
                    num += d[i]
                    s = s.replace(i, "0"*len(i), 1)
        
        return num
