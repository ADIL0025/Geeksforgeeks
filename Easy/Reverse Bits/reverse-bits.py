#User function Template for python3

class Solution:
    def reversedBits(self, x):
        x1=0
        for i in range(0,32):
            x1=(x1<<1)|(x&1)
            x>>=1
        return x1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        X=int(input())
        
        ob = Solution()
        print(ob.reversedBits(X))
# } Driver Code Ends