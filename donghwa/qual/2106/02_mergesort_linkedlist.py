"""
완성되지 않은 답변임. chatgpt 폴더 참고 바람.
"""

class LinkedNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
def getMiddle(head:LinkedNode)->LinkedNode:
    size = 0
    cur = head
    while(cur):
        cur = cur.next
        size += 1
    
    mid = size//2
    cur = head
    while(mid):
        cur = cur.next
        mid -= 1
    return cur
     
def sortingLL(head: LinkedNode)-> LinkedNode:
    if head == None or head.next == None :
        return head

    middle = getMiddle(head)
    nexttomiddle = middle.next
    


if __name__ == "__main__":
    def list_to_linked_list(numlist:list)->LinkedNode:
        if not numlist:
            return None
        head = LinkedNode(numlist[0])
        curr = head

        for val in numlist[1:]:
            curr.next = LinkedNode(val)
            curr = curr.next
        return head
    def print_linked_list(head: LinkedNode):
        curr = head
        while curr:
            print(curr.val, end=" -> ")
            curr = curr.next
        print("None")
    a = [1, 3, 2, 4, 5, 6, 7, 8]; ahead = list_to_linked_list(a)
    b = [5, 3, 2, 1, 4, 0, 6, 7]; bhead = list_to_linked_list(b)
    c = [2, 4, 1, 7]; chead = list_to_linked_list(c)
    d = [2]; dhead = list_to_linked_list(d)
    print_linked_list(sortingLL(ahead))
    print_linked_list(sortingLL(bhead))
    print_linked_list(sortingLL(chead))
    print_linked_list(sortingLL(dhead))
    print_linked_list(sortingLL(None))