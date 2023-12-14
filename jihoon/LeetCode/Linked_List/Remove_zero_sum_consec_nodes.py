# A Linked List Node
class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None
 
# Function to create Node
def getNode(data):
    temp = ListNode(data)
    temp.next = None
    return temp
 
# Function to print the Linked List
def printList(head):
    while (head.next):
        print(head.val, end=' -> ')
        head = head.next
    print(head.val, end='')
 
# Function that removes continuous nodes
# whose sum is K
def removeZeroSum(head, K):
 
    # Root node initialise to 0
    root = ListNode(0)
 
    # Append at the front of the given
    # Linked List
    root.next = head
 
    # Map to store the sum and reference
    # of the Node
    umap = dict()
 
    umap[0] = root
 
    # To store the sum while traversing
    sum = 0
 
    # Traversing the Linked List
    while (head != None):
 
        # Find sum
        sum += head.val
 
        # If found value with (sum - K)
        if ((sum - K) in umap):
 
            prev = umap[sum - K]
            start = prev
 
            # Delete all the node
            # traverse till current node
            aux = sum
 
            # Update sum
            sum = sum - K
 
            # Traverse till current head
            while (prev != head):
                prev = prev.next
                aux += prev.val
                if (prev != head):
                    umap.remove(aux)
 
            # Update the start value to
            # the next value of current head
            start.next = head.next
 
        # If (sum - K) value not found
        else:
            umap[sum] = head
 
        head = head.next
 
    # Return the value of updated
    # head node
    return root.next
 
 
# Driver Code
if __name__ == '__main__':
 
    # Create Linked List
    head = getNode(1)
    head.next = getNode(2)
    head.next.next = getNode(-3)
    head.next.next.next = getNode(3)
    head.next.next.next.next = getNode(1)
 
    # Given sum K
    K = 5
 
    # Function call to get head node
    # of the updated Linked List
    head = removeZeroSum(head, K)
 
    # Print the updated Linked List
    if(head != None):
        printList(head)
 
    # This code is contributed by pratham76