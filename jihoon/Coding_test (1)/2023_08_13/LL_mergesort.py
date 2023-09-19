class LinkedNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def merge_and_sort(first: LinkedNode, second: LinkedNode):
    result_head = None
    if first == None:
        return second
    if second == None:
        return first
    
    if (first.val > second.val):
        result_head = first
        first.next = merge_and_sort(first.next, second)
    elif (second.val >= first.val):
        result_head = second
        second.next = merge_and_sort(first, second.next)

    return result_head


def devide_LL(head: LinkedNode, LL_len: int):
    curr = head
    print("LL_len: ", LL_len)
    if (LL_len == 0):
        print("Base case LL_len = 0: ")
        return None
    if (LL_len == 1):
        print("Base case LL_len = 1: ", curr.val)
        mid_ptr = curr.next
        curr.next = None
        return head
    mid_len = LL_len // 2
    cnt = 0
    curr = head

    if (LL_len %2 == 1):             # 1/ 3/ 2/ 4 / 5, 6, 7, 8
        while cnt < mid_len:
            print("curr: ", curr.val)
            cnt += 1
            curr = curr.next

        mid_ptr = curr
        #next_node = curr.next
        curr.next = None
    else:
        while cnt < mid_len:
            print("curr: ", curr.val)
            cnt += 1
            curr = curr.next

        next_node = curr.next
        mid_ptr = next_node
        curr.next = None

    # mid_ptr = next_node

    left = devide_LL(head, mid_len)
    if (LL_len %2 == 1): 
        right = devide_LL(mid_ptr, mid_len+1)
    else:
        right = devide_LL(mid_ptr, mid_len)

    sorted_list = merge_and_sort(left, right)
    return sorted_list

def sortingLL(head: LinkedNode) -> LinkedNode:
    LL_len = 0
    curr = head

    # Find LL's length
    while curr:
        LL_len += 1
        curr = curr.next
    
    return devide_LL(head, LL_len)

# if __name__ == '__main__':
#     li = LinkedNode(15)
     
#     # Let us create a unsorted linked list
#     # to test the functions created.
#     # The list shall be a: 2->3->20->5->10->15
#     curr = li
#     numbers = [10, 5, 20, 3, 2]
#     for n in numbers:
#         curr.next = LinkedNode(n)
#         curr = curr.next

#     curr = li

#     while curr:
#         print(curr.val)
#         curr = curr.next
     
#     # Apply merge Sort
#     sortingLL(li)
#     print ("Sorted Linked List is:")
#     while curr:
#         print(curr.val)
#         curr = curr.next

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