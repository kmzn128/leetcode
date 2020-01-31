import bisect
nums1 = [1,3]
nums2 = [2]
for num in nums2:
    bisect.insort(nums1, num)
print(nums1)
le = len(nums1)
if(le % 2 == 0):
    print((nums1[le//2]+nums1[le//2-1])/2)
else:
    print(nums1[le//2])