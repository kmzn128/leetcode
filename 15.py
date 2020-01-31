import bisect
import collections
nums = [0,0,0,1,-1]
def three_sum(nums):
    nums.sort()
    ans = set()
    ans_key = set()
    for i in range(len(nums)-1):
        for j in range(i+1, len(nums)):
            nums_c = nums[:]
            a = nums_c[i]
            b = nums_c[j]
            nums_c = nums_c[j+1:]
            k = bisect.bisect_left(nums_c, -(a+b))
            if(k >= 0 and k < len(nums_c)):
                c = nums_c[k]
                if(a+b+c == 0):
                    ans.add((a,b,c))
    return ans
print(three_sum(nums))        