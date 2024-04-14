#User function Template for python3
def upper_bound(arr, x):
    low = 0 
    high = len(arr) - 1 
    
    while low <= high:
        mid = (low + high) >> 1 
        
        if arr[mid] > x:
            high = mid - 1 
        else:
            low = mid + 1 
            
    return low 

class Solution:
    def countElements(self, a, b, n, query, q):
        # code here
        
        b.sort()
        
        res = []
        for i in query:
            cnt = upper_bound(b, a[i])
            res.append(cnt)
            
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    q = int(input())
    query = []
    ob = Solution()
    for i in range(q):
        query.append(int(input()))
    ans = ob.countElements(a, b, n, query, q)
    for i in range(q):
        print(ans[i])

# } Driver Code Ends