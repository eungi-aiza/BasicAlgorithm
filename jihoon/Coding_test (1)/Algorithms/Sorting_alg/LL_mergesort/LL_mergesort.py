# linked list node 구현
class LinkedNode:
    def __init__(self, val):
        self.val = val
        self.next = None

# linked list를 이용한 in-place merge sort 구현
def merge_sort(head: LinkedNode) -> LinkedNode:
    if not head or not head.next:
        return head
    
    # linked list를 두 개의 sub list로 나누기
    prev, slow, fast = None, head, head
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
    prev.next = None
    
    # 재귀적으로 sub list를 정렬하고 병합
    left = merge_sort(head)
    right = merge_sort(slow)
    return merge(left, right)

# 두 개의 linked list를 병합하는 함수
def merge(left: LinkedNode, right: LinkedNode) -> LinkedNode:
    if not left:
        return right
    if not right:
        return left
    
    if left.val < right.val: # 부등호 방향 < : asc,  > : desc
        left.next = merge(left.next, right)
        return left
    else:
        right.next = merge(left, right.next)
        return right

def list_to_linked_list(numlist:list)->LinkedNode:
    if not numlist:
        return None
    head = LinkedNode(numlist[0])
    curr = head

    for val in numlist[1:]:
        curr.next = LinkedNode(val)
        curr = curr.next
    return head

def printnode(head: LinkedNode)->None:
    while(head):
        print(head.val, end = "->")
        head = head.next
    return


if __name__ == "__main__":
    a = [1, 3, 2, 4, 5, 6, 7, 8]; ahead = list_to_linked_list(a)
    b = [5, 3, 2, 1, 4, 0, 6, 7]; bhead = list_to_linked_list(b)
    # printnode(ahead)
    # printnode(bhead)
    printnode(merge_sort(ahead))
    printnode(merge_sort(bhead))