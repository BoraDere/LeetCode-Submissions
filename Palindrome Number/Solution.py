class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        if x == 0:
            return True
        
        size = 1
        temp = x
        dum = 0

        while temp >= 10:
            size += 1
            temp /= 10

        temp = x

        for i in range(size):
            dig = 10**(size-1-i)
            inc = int(temp/dig)
            dum += inc*(10**i)
            temp -= inc*dig
        
        return dum == x
