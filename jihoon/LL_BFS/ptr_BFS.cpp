// Populating Next Right Pointers in Each Node II

// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Example 1:


// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
// Example 2:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 6000].
// -100 <= Node.val <= 100
 

// Using ONLY BFS
public Node connect_bfs(Node root) {
    if (root == null) {
        return root;
    }
    Queue<Node> queue = new LinkedList<>();
    queue.offer(root);
    while (!queue.isEmpty()) {
        int size = queue.size();
        List<Node> levelNodes = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            Node curNode = queue.poll();
            levelNodes.add(curNode);
            if (curNode.left != null) {
                queue.add(curNode.left);
            }
            if (curNode.right != null) {
                queue.add(curNode.right);
            }
        }
        for (int i = 0; i < levelNodes.size() - 1; i++) {
            Node node = levelNodes.get(i);
            node.next = levelNodes.get(i + 1);
        }
    }
    return root;
}

public Node connect_bfs(Node root) {
       if (root == null) {
           return root;
       }
       Queue<Node> queue = new LinkedList<>();
       queue.offer(root);
       while (!queue.isEmpty()) {
           int levelCount = queue.size();
           Node prev = null;
           for (int i = 0; i < levelCount; i++) {
               Node curNode = queue.poll();
               if (prev != null) {
                   prev.next = curNode;
               }
               prev = curNode;
               if (curNode.left != null) {
                   queue.add(curNode.left);
               }
               if (curNode.right != null) {
                   queue.add(curNode.right);
               }
           }
       }
       return root;
   }

// Using BFS + Linked List

public Node connect_linkedlist(Node root) {
    if (root == null) {
        return root;
    }
    // the curNode as the linkedlist of each level
    Node curNode = root;
    while (curNode != null) {
        // a dummyNode to travesal current Level
        Node dummyNode = new Node(0);
        // the prev Node of next level
        Node prevNode = dummyNode;
        while (curNode != null) {
            if (curNode.left != null) {
                // linked the left child
                prevNode.next = curNode.left;
                // update prev as LinkedList
                prevNode = curNode.left;
            }
            if (curNode.right != null) {
                prevNode.next = curNode.right;
                prevNode = curNode.right;
            }
            // the next node of current level
            curNode = curNode.next;
        }
        // after process the next level, process 
        curNode = dummyNode.next;
    }
    return root;
}

public static Node connect_bfs(Node root) {
if (root == null) {
    return root;
}
Queue<Node> queue = new LinkedList<>();
queue.offer(root);
while (!queue.isEmpty()) {
    int levelCount = queue.size();
    Node prev = null;
    for (int i = 0; i < levelCount; i++) {
        Node curNode = queue.poll();
        if (prev != null) {
            prev.next = curNode;
        }
        prev = curNode;
        if (curNode.left != null) {
            queue.add(curNode.left);
        }
        if (curNode.right != null) {
            queue.add(curNode.right);
        }
    }
} 
return root;}

//Using Recursion

public Node connect(Node root) {
        if (root == null || (root.left == null && root.right == null)) {
            return root;
        }

        if (root.left != null && root.right != null) {
            root.left.next = root.right;
            root.right.next = getNextHasChildrenNode(root);
        }

        if (root.left == null) {
            root.right.next = getNextHasChildrenNode(root);
        }

        if (root.right == null) {
            root.left.next = getNextHasChildrenNode(root);
        }

        // right should first
        root.right = connect(root.right);
        root.left = connect(root.left);

        return root;
    }

    public Node getNextHasChildrenNode(Node root) {
        while (root.next != null) {
            if (root.next.left != null) {
                return root.next.left;
            }
            if (root.next.right != null) {
                return root.next.right;
            }

            root = root.next;
        }

        return null;
    }