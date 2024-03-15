#User function Template for python3

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None


class Solution:
    def sort(self, head):
        #return head
        first = Node(-1)
        first.next = head
        second = Node(-2)
        second.next = head.next
        if not second.next:
            return head
            
        def reverse(head):
            dummy = None
            prev = dummy
            temp = head
            while(temp):
                nxt = temp.next
                temp.next = prev 
                prev = temp 
                temp = nxt
            return prev
        def merge_sorted_lists(h1, h2):
            dummy = Node(-1)
            temp = dummy 
            i = h1 
            j = h2 
            while(i and j):
                # print("here", i.data, j.data, temp.data)
                if i.data <= j.data:
                    temp.next = i
                    temp = i
                    i = i.next
                else:
                    temp.next = j
                    temp = j
                    j = j.next 
            # print("idhar",temp)
            if j :
                temp.next = j
                # return dummy.next 
            else:
                temp.next = i
            return dummy.next
        temp = head 
        while(temp):
            if not temp.next or not temp.next.next:
                if temp.next:
                    temp.next = None
                break
            nxt_ptr = temp.next.next 
            # print("nxt_ptr", nxt_ptr.data)
            temp.next.next = nxt_ptr.next
            temp.next = nxt_ptr
            temp = nxt_ptr
        # print("temp", temp.data)
        temp2 = second
        head2 = reverse(temp2.next)
        ans_node = merge_sorted_lists(head2, head)
        return ans_node



#{ 
 # Driver Code Starts
#Initial Template for Python 3

class Llist:
    def __init__(self):
        self.head=None
    
    def insert(self,data,tail):
        node=Node(data)
        
        if not self.head:
            self.head=node
            return node
        
        tail.next=node
        return node
        

def printList(head):
    while head:
        print(head.data,end=' ')
        head=head.next
        
if __name__ == '__main__':
    t=int(input())
    
    for tcs in range(t):
        
        n1=int(input())
        arr1=[int(x) for x in input().split()]
        ll1=Llist()
        tail=None
        for nodeData in arr1:
            tail=ll1.insert(nodeData,tail)
            
        
        ob = Solution()
        resHead=ob.sort(ll1.head)
        printList(resHead)
        print()
        
    
    
# } Driver Code Ends