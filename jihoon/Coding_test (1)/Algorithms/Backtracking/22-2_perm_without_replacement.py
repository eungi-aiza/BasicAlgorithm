## Backtracking permutation
## 22-2 기출

ans = []
def toString(List):
    return ''.join(List) 
def permute(a, l, r, ans):
    if l == r:
        if toString(a) not in ans : 
          ans.append(toString(a))
    else:
        for i in range(l, r):
            a[l], a[i] = a[i], a[l]
            permute(a, l+1, r, ans)
            a[l], a[i] = a[i], a[l]  # backtrackA
 
string = "abb"
n = len(string)
a = list(string) 
permute(a, 0, n,ans)