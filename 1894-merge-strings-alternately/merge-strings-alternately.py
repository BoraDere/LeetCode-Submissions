class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        m, n = len(word1), len(word2)
        s = ""
        i = 0

        for i in range(min(m, n)):
            s += word1[i]
            s += word2[i]
            i += 1

        if m > n:
            s += word1[i:]
        elif n > m:
            s += word2[i:]

        return s