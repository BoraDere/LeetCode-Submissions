class Solution:
    def longestPalindrome(self, s: str) -> str:
        def reverser(s):
            return s[::-1]


        if s == reverser(s):
            return s

        r = s[0]

        for i in range(len(s)-1):
            _ = s[i:]
            for j in range(len(_)-1):
                if _[:len(_)-j] == reverser(_[:len(_)-j]) and len(_[:len(_)-j]) > len(r):
                    r = _[:len(_)-j]
        
        return r
    