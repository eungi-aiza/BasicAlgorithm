# max_panlindrome FAIL
"""
(a) linked list의 모든 node val을 순서대로 print하는 함수 짜기
(b) 해당 linked list가 palindrome인지 확인하는 palindrome(s) 짜기
(c) substring(s,t): t in s인지
(d) maximal palindrome함수 짜기 (a,b,c활용)
"""
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def printnode(head: ListNode)->None:
    while(head):
        print(head.val, end = "->")
        head = head.next
    print("None")
    

def is_palindrome(head):
    # Helper function to reverse a linked list
    def reverse_linked_list(node):
        prev = None
        while node:
            next_node = node.next
            node.next = prev
            prev = node
            node = next_node
        return prev

    # Find the middle of the linked list using the slow and fast pointer approach
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    # Reverse the second half of the linked list
    second_half = reverse_linked_list(slow)

    # Compare the first and second halves of the linked list
    first_half = head
    while second_half:
        if first_half.val != second_half.val:
            return False
        first_half = first_half.next
        second_half = second_half.next

    return True

def is_substring(s, t):
    if not s or not t:
        return False

    s_ptr = s
    t_ptr = t

    while s_ptr:
        if s_ptr.val == t_ptr.val:
            s_tmp = s_ptr
            t_tmp = t_ptr
            while t_tmp and s_tmp and t_tmp.val == s_tmp.val:
                t_tmp = t_tmp.next
                s_tmp = s_tmp.next

            if not t_tmp:  # If we reached the end of t, it's a substring.
                return True

        s_ptr = s_ptr.next

    return False

def max_palindromes(s):
    palindromes = []
    current = s

    while current:
        if is_palindrome(current):
            is_maximal = True

            for palindrome in palindromes:
                if is_substring(current, palindrome):
                    is_maximal = False
                    break

            if is_maximal:
                palindromes.append(current)

        current = current.next

    return palindromes



# Example usage:
# is_palindrome
# Create a palindrome linked list: 1 -> 2 -> 3 -> 2 -> 1
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(2)
head.next.next.next.next = ListNode(1)

print(is_palindrome(head))  # Output should be True

# Create a non-palindrome linked list: 1 -> 2 -> 3 -> 4 -> 5
non_palindrome = ListNode(1)
non_palindrome.next = ListNode(2)
non_palindrome.next.next = ListNode(3)
non_palindrome.next.next.next = ListNode(4)
non_palindrome.next.next.next.next = ListNode(5)

print(is_palindrome(non_palindrome))

# is_substring
# Create linked list s: 1 -> 2 -> 3 -> 4 -> 5
s = ListNode(1)
s.next = ListNode(2)
s.next.next = ListNode(3)
s.next.next.next = ListNode(4)
s.next.next.next.next = ListNode(5)

# Create linked list t: 3 -> 4
t = ListNode(3)
t.next = ListNode(4)

# Check if t is a substring of s
print(is_substring(s, t))  # Output should be True

# Create another linked list t: 2 -> 6
t = ListNode(2)
t.next = ListNode(6)

# Check if t is a substring of s
print(is_substring(s, t))  # Output should be False

# max_palindrome
# Create linked list s: a -> bab -> c -> dd -> abc -> e -> aba -> f -> g
s = ListNode('a')
s.next = ListNode('b')
s.next.next = ListNode('a')
s.next.next.next = ListNode('b')
s.next.next.next.next = ListNode('c')
s.next.next.next.next.next = ListNode('d')
s.next.next.next.next.next.next = ListNode('d')
s.next.next.next.next.next.next.next = ListNode('a')
s.next.next.next.next.next.next.next.next = ListNode('b')
s.next.next.next.next.next.next.next.next.next = ListNode('c')
s.next.next.next.next.next.next.next.next.next.next = ListNode('e')
s.next.next.next.next.next.next.next.next.next.next.next = ListNode('a')
s.next.next.next.next.next.next.next.next.next.next.next.next = ListNode('b')
s.next.next.next.next.next.next.next.next.next.next.next.next.next = ListNode('a')
s.next.next.next.next.next.next.next.next.next.next.next.next.next.next = ListNode('f')
s.next.next.next.next.next.next.next.next.next.next.next.next.next.next.next = ListNode('g')

max_palindromes_list = max_palindromes(s)
for palindrome in max_palindromes_list:
    values = []
    current = palindrome
    while current:
        values.append(current.val)
        current = current.next
    print("".join(values))