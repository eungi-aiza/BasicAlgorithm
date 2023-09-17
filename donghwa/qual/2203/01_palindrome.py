class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def ll2str(s):
    res = ""
    while(s):
        res += s.val
        s = s.next

def ll_print(s):
    while(s):
        print(s.val, end=' ')
        s = s.next
    print()

def palindrome(s):
    s_str = ll2str(s)
    n = len(s_str)
    check = True
    for i in range(n//2):
        if s_str[i] != s_str[n-1-i]:
            check = False
    return check

def substring(s, t):
    s_str = ll2str(s)
    t_str = ll2str(t)

    if t_str in s_str:
        return True
    else :
        return False

def max_palindromes(s):
    s_str = lls2str(s)
    n = len(s_str)
    cur_len = n//2
    while(cur_len):
        for i in range(n//2):
            if i+cur_len*2 > len(s_str):
                continue
            tmp = s_str[i:i+cur_len]
            tmp2 = tmp + tmp[::-1]
            if substring()
    
        
    



