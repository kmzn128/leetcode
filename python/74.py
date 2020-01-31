class Solution:
    
    def __init__(self):
        pass
    
    def bin_search(self, target, left, right, li):
        if(left > right):
            return -1
        mid = (right-left)//2+left
        if(li[mid] == target):
            return mid
        elif(li[mid] < target):
            return self.bin_search(target, mid+1, right, li)
        else:
            return self.bin_search(target, left, mid-1, li)
    
    def bin_search2(self, target, left, right, li):
        if(left > right):
            return -1
        if(left == right):
            return left
        low_bound = li[0]
        up_bound = li[-1]
        if(target < low_bound):
            return -1
        if(target > up_bound):
            return len(li)-1
        mid = (right-left)//2+left
        if(mid+1 <= len(li)-1 and li[mid] <= target and li[mid+1] > target):
            return mid
        elif(mid+1 <= len(li)-1 and li[mid+1] <= target):
            return self.bin_search2(target, mid+1, right, li)
        else:
            return self.bin_search2(target, left, mid-1, li)
    
    
    def searchMatrix(self, matrix, target):
        N = len(matrix)
        if(N == 0):
            return False
        M = len(matrix[0])
        if(M == 0):
            return False
        left_row = [row[0] for row in matrix]
        num_row = self.bin_search2(target, 0, N-1, left_row)
        if(num_row == -1):
            return False
        ind = self.bin_search(target, 0, M-1, matrix[num_row])
        return True if ind >= 0 else False



# matrix = [
#   [1,   3,  5,  7],
#   [10, 11, 16, 20],
#   [23, 30, 34, 50]
# ]
# target = 3
matrix = [[1],[3]]
target = 3
# print(Solution().bin_search(10, 0, 3, [1,3,5,7])) 
# print(Solution().bin_search(1, 0, 3, [1,3,5,7]))
#print(Solution().bin_search2(3, 0, 3, [1,3,5,7])) 
#print(Solution().bin_search2(-1, 0, 3, [1,3,5,7]))
   
Solution().searchMatrix(matrix, target)