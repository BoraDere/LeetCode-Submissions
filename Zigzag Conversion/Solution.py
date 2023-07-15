class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if len(s) <= 1 or numRows == 1:
            return s
        t = divmod(len(s), 2*numRows - 2)
        quotient = t[0]; remainder = t[1]
        factor = 0
        l = []
        factor = 1 if remainder <= numRows else 1 + remainder - numRows

        for i in range(numRows): # 0 1 2 3 4
            if i == 0 or i == numRows -1:
                for j in range(quotient + factor): # 0 1 2 + factor
                    try:
                        l.append(s[i + 2*(numRows - 1)*j])
                    except:
                        nop = 0
            else:
                for j in range(quotient + factor): # 0 1 2 + factor
                    try:
                        l.append(s[i + 2*(numRows - 1)*j])
                        l.append(s[i + 2*(numRows - 1)*j + (numRows - i - 1)*2])
                    except:
                        nop = 0
        return "".join(i for i in l)