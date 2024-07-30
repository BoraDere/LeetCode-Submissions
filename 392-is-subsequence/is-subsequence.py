class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        m, n = len(s), len(t)
        if m > n:
            return False

        if m == n:
            if s == t:
                return True
            else:
                return False
        
        if m != 0:
            try:
                for c in t:
                    if c == s[0]:
                        s = s[1:]
            except:
                nop = 0
            
        return len(s) == 0