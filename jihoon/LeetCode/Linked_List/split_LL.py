# Python program for the above approach
 
# Structure of a Node
class Node:
    def __init__(self):
        self.data = 0;
        self.next = next;
 
# Function to find the length of
# the Linked List
def sizeOfLL(head):
    size = 0;
 
    # While head is not None
    while (head != None):
        size += 1;
        head = head.next;
     
    return size;
 
# Function to partition list into
# 3 parts such that maximum size
# difference between parts is minimum
def Partition_of_list(head):
    size = sizeOfLL(head);
    temp = head;
    ans = [];
 
    # If size is less than 3
    if (3 >= size):
       
        # Partition linked list
        # into one Node each
        while (temp != None):
            next = temp.next;
            temp.next = None;
            ans.append(temp);
            temp = next;
         
 
        # The remaining parts (3-size)
        # will be filled by empty
        # the linked list
        y = 3 - size;
        while (y != 0):
            ans.append(None);
            y-=1;
         
    else:
        # Minimum size
        minSize = size // 3;
        rem = size % 3;
 
        # While size is positive
        # and temp is not None
        while (size > 0 and temp != None):
            m = 0;
 
            # If remainder > 0, then
            # partition list on the
            # basis of minSize + 1
            if (rem != 0):
                m = minSize + 1;
                rem-=1;
             
 
            # Otherwise, partition
            # on the basis of minSize
            else:
                m = minSize;
             
            curr = temp;
 
            # Iterate for m-1 steps
            # in the list
            for j in range(1,m):# (j = 1; j < m and temp.next != None; j+=1):
                temp = temp.next;
             
 
            # Change the next of the
            # current Node to None
            # and add it to the ans
            if (temp.next != None):
                x = temp.next;
                temp.next = None;
                temp = x;
                ans.append(curr);
             
            # Otherwise
            else:
                # Pushing to ans
                ans.append(curr);
                break;
             
            size -= m;
         
    # Return the resultant lists
    return ans;
 
# Function to insert elements in list
def push(head, d):
    temp = Node();
    temp.data = d;
    temp.next = None;
 
    # If the head is None
    if ((head) == None):
        (head) = temp;
 
    # Otherwise
    else:
        curr = (head);
 
        # While curr.next is not None
        while (curr.next != None):
            curr = curr.next;
         
        curr.next = temp;
     
    return head;
 
 
# Function to display the Linked list
def display(head):
    # While head is not None
    while (head.next != None):
        # Print the data
        print(head.data , "->", end="");
        head = head.next;
     
    print(head.data );
 
# Driver Code
if __name__ == '__main__':
   
    # Given Input
    head = None;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
 
    # Function Call
    v = Partition_of_list(head);
 
    for i in range(len(v)):
        display(v[i]);
 
# This code is contributed by umadevi9616