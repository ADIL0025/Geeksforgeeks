#User function Template for python3

class Solution:
    def search(self, pattern, text):
        n = len(text)
        m = len(pattern)
        index_arr = []

        for i in range(n):
            if text[i:i+m] == pattern:
                index_arr.append(i + 1)

        return index_arr

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        for value in ans:
            print(value,end = ' ')
        print()
# } Driver Code Ends