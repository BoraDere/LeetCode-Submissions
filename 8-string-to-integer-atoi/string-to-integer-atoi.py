class Solution:
    def myAtoi(self, s: str) -> int:
        res = ""
        l = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
        sign = 1
        _min = -(2**31)
        _max = (2**31) - 1
        i = 0

        if s == "":
            return 0

        for c in s:
            if c == " ":
                i += 1
            else:
                break

        try:
            if s[i] == "-":
                sign *= -1
                i += 1
            elif s[i] == "+":
                i += 1
        except:
            return 0

        for j in range(i, len(s)):
            if s[j] not in l:
                break
            res += s[j]
        
        if res == "":
            return 0

        res = sign * int(res)

        if res < _min:
            return _min
        elif res > _max:
            return _max
        else:
            return res

            
        