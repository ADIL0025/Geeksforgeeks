#User function Template for python3

class Solution:
	def find_median(self, v):
		# Code here
        sort_v=sorted(v)
        n=len(sort_v)
        if n%2 == 0:
            sums = (0+(n-1))//2
            aveg=(sort_v[sums]+sort_v[sums+1])//2
            return aveg
        else:
            res = (0+(n-1))//2
        return sort_v[res]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		v = list(map(int,input().split())) 
		ob = Solution();
		ans = ob.find_median(v)
		print(ans)
# } Driver Code Ends