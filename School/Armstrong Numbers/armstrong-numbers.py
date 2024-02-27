#User function Template for python3

class Solution:
    def armstrongNumber (self, n):
        arr = [int(x) for x in str(n)]
        sum=0
        for i in range(len(arr)):
            sum+=pow(arr[i],3)
        if sum==n:
            return "Yes"
        else:
            return "No"

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = input()
        n=int(n)
        ob = Solution()
        print(ob.armstrongNumber(n))
# } Driver Code Ends