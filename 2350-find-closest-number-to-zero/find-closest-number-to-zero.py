class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        c = 0

        for i in range(len(nums)):
            if i == 0:
                c = nums[0]
            else:
                num = nums[i]
                dist = abs(num)

                if dist < abs(c):
                    c = num
                elif dist == abs(c) and num > 0:
                    c = num

        return c 
