class Solution:
    def reorganizeString(self, s: str) -> str:
        d = {}

        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1

        _max = max(d, key=d.get)

        if len(s) - d[_max] < d[_max] - 1:
            return ""

        res = [''] * len(s)
        i = 0

        while d[_max]:
            res[i] = _max
            i += 2
            d[_max] -= 1

        for key, value in d.items():
            if key not in res:
                while value:
                    if i >= len(s):
                        i = 1
                    res[i] = key
                    i += 2
                    value -= 1

        return "".join(res)


        