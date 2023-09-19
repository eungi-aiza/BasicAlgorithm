
# Function to Check if a substring is a palindrome
def is_palindrome(string, i, j):
 
    while i < j:
        if string[i] != string[j]:
            return False
        i += 1
        j -= 1
    return True
 
#  Function to find the minimum number of cuts needed for palindrome partitioning
 
 
def min_pal_partition(string, i, j):
 
    # Base case: If the substring is empty or a palindrome, no cuts needed
    if i >= j or is_palindrome(string, i, j):
        return 0
 
    ans = float('inf')
 
    # Iterate through all possible partitions and find the minimum cuts needed
    for k in range(i, j):
        count = min_pal_partition(string, i, k) + \
            min_pal_partition(string, k + 1, j) + 1
        ans = min(ans, count)
 
    return ans
 
 
# Driver code
if __name__ == "__main__":
    str = "ababbbabbababa"
 
    # Find the minimum cuts needed for palindrome partitioning and display the result
    print("Min cuts needed for Palindrome Partitioning is",
          min_pal_partition(str, 0, len(str) - 1))