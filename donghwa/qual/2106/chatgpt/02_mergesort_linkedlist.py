class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge(left, right):
    if not left:
        return right
    if not right:
        return left

    if left.val < right.val:
        merged = left
        left = left.next
    else:
        merged = right
        right = right.next

    current = merged

    while left and right:
        if left.val < right.val:
            current.next = left
            left = left.next
        else:
            current.next = right
            right = right.next
        current = current.next

    if left:
        current.next = left
    elif right:
        current.next = right

    return merged

def get_middle(head):
    if not head:
        return head

    slow = head
    fast = head

    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next

    middle = slow.next
    slow.next = None

    return middle

def merge_sort(head):
    if not head or not head.next:
        return head

    middle = get_middle(head)
    left = merge_sort(head)
    right = merge_sort(middle)

    return merge(left, right)

def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

# Example usage:
head = ListNode(12)
head.next = ListNode(11)
head.next.next = ListNode(5)
head.next.next.next = ListNode(6)
head.next.next.next.next = ListNode(7)
head.next.next.next.next.next = ListNode(10)

print("Original List:")
print_linked_list(head)

head = merge_sort(head)

print("Sorted List:")
print_linked_list(head)
