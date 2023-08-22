class LinkedNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
def merge(start, mid, end):
    cur = None
    while(cur != end) :
        if start.val > mid.val: # start가 더 클 때
            cur.next = mid
            start = start.next
            mid = mid.next     
            cur = cur.next
        else : # start가 더 작을 때
            
            
    
    
def mergesortHelp(start:LinkedNode, end:LinkedNode, size:int):
    if start == end:
        return
    else :
        cnt = size//2
        mid = start
        while(cnt>1):
            mid = mid.next
            cnt -= 1   
        mergesortHelp(start, mid, size//2)
        mergesortHelp(mid.next, end, size-size//2)
        mid.next = None 
        merge()
            
        
def sortingLL(head: LinkedNode)-> LinkedNode:
    end = head.copy()
    if head != None:
        size = 1
        while(end.next):
            size += 1
            end = end.next
    else :
        size = 0
        print("No node in LinkedList")
        return 
    
    mergesortHelp(head, end, size)
        
if __name__ == "__main__":
    node2 = LinkedNode(2)
    node4 = LinkedNode(4)
    node1 = LinkedNode(1)
    node7 = LinkedNode(7)
    node2.next = node4
    node4.next = node1
    node1.next = node7
    
    head = node2
    
    