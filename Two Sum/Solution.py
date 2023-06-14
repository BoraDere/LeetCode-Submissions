class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in nums:
            temp1 = nums.copy()
            temp1.remove(i)
            for j in temp1:
                if i + j == target: 
                    if nums.index(i) != nums.index(j):
                        return [nums.index(i), nums.index(j)]  
                    else:
                        temp2 = nums.copy()
                        temp2.remove(i)
                        return [nums.index(i), temp2.index(j)+1] 