class Solution:
    def convert(self, s: str, numRows: int) -> str:
        """ PAYPALISHIRING  = 3     14//3 = 4
        P  A  Y  P  A  L  I  S  H  I  R  I  N  G
        0  4  11 5  1  6  12 7  2  8  13 9  3  10    
        """

        """PAYPALISHIRING   = 4     14//4 = 3
        P  A  Y  P  A  L  I  S  H  I  R  I  N  G
        0  3  8  12 9  4  1  5  10 13 11 6  2  7
        """

s = "PAYPALISHIRING"
numRows = 3
for i in range(1, numRows+1): # 1 2 3
    ind = numRows - i if numRows - i != 0 else numRows - 1
    print(s[i-1::2*ind])
    