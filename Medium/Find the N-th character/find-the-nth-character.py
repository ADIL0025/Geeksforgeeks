#User function Template for python3

class Solution:
    def nthCharacter(self, s, r, n):
        c = 0
        while r > 0:
            c += n % 2
            n = n // 2
            r -= 1
        ch = s[n]
        for i in range(1, c + 1):
            if ch=='0':
                ch='1'
            else:
                ch='0'
        return ch


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        snr = input().split()
        S, R, N = snr[0], int(snr[1]), int(snr[2])
        ob = Solution()
        print(ob.nthCharacter(S, R, N))
# } Driver Code Ends