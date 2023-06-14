class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maximum = 0
        for _ in range(len(s)):
            clist = []
            for i in s[_:]:
                if i not in clist:
                    clist.append(i)
                else:
                    break
            maximum = len(clist) if len(clist) > maximum else maximum
        return maximum