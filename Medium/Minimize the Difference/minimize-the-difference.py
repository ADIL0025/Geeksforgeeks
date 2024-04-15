from typing import List


class Solution:
    def minimizeDifference(self, n : int, k : int, arr : List[int]) -> int:
        # code here
        prefix_max = [0] * n
        prefix_min = [0] * n
        suffix_max = [0] * n
        suffix_min = [0] * n
        
        prefix_max[0] = arr[0]
        prefix_min[0] = arr[0]
        for i in range(1, n):
            prefix_max[i] = max(prefix_max[i-1], arr[i])
            prefix_min[i] = min(prefix_min[i-1], arr[i])
        
        suffix_max[n-1] = arr[n-1]
        suffix_min[n-1] = arr[n-1]
        for i in range(n-2, -1, -1):
            suffix_max[i] = max(suffix_max[i+1], arr[i])
            suffix_min[i] = min(suffix_min[i+1], arr[i])
        
        min_diff = float('inf')
        for i in range(n-k+1):
            if i == 0:
                diff = suffix_max[k] - suffix_min[k]
            elif i == n-k:
                diff = prefix_max[n-k-1] - prefix_min[n-k-1]
            else:
                diff = max(prefix_max[i-1], suffix_max[i+k]) - min(prefix_min[i-1], suffix_min[i+k])
            min_diff = min(min_diff, diff)
        
        return min_diff
        



#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        k = int(input())
        
        
        arr=IntArray().Input(n)
        
        obj = Solution()
        res = obj.minimizeDifference(n, k, arr)
        
        print(res)
        

# } Driver Code Ends