

# # swap(s, i, j) swaps the ith and jth characters of string, s
# def swap(list_s, i, j):
#     list_s[i], list_s[j] = list_s[j], list_s[i]
#     return list_s

# def perm_backtrack(list_s, i, s_len, result):
#     if i == s_len:
#         result.add(''.join(list_s))
#         return result
#     else:
#         for j in range(i, s_len):
#             swap(list_s, i, j)
#             perm_backtrack(list_s, i+1, s_len, result)
#             swap(list_s, i, j) # for backtracking
#     return result

# def str_perm(s):
#     result = set()
#     return list(perm_backtrack(list(s), 0, len(s), result))

result = set()
def perm_backtrack(list_s, i, curr, remain):
    if len(remain) == 0:
        #print("this")
        result.add(''.join(curr))
        return
    else:
        #print(remain)
        for i in range(len(list_s)-1):
            pivot_char = list_s[i]
            curr.append(pivot_char)
            remain.remove(pivot_char)
            perm_backtrack(list_s, i+1, curr, remain)
            curr.remove(pivot_char)
            remain.append(pivot_char)
    return result

def str_perm(s):
    perm_backtrack(list(s), 0, [], list(s))
    return list(result)



def main():
    print(str_perm("abc"))
    print(str_perm("abb"))

if __name__ == "__main__":
    main()