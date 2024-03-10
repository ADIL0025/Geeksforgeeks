#User function Template for python3
class Solution:

	
	def removeDuplicates(self,str):
        
        ans = ""
        dup = {chr(i): False for i in range(ord('a'), ord('z')+1)}
        dup.update({chr(i): False for i in range(ord('A'), ord('Z')+1)})

        n = len(str)
        
        for ch in str:
            if not dup[ch]:
                ans += ch
                dup[ch] = True
           
        return ans         
	    
	    # code here


#{ 
 # Driver Code Starts
#Initial Template for Python 3





if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        str = input().strip()
        ob = Solution()
        ans = ob.removeDuplicates(str)
        print(ans)
        tc -= 1

# } Driver Code Ends