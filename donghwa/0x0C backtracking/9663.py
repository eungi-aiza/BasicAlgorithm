"""
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
- 입력 : 첫째 줄에 N이 주어진다. (1 ≤ N < 15)
- 출력 : 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

ex.
입력  :
8
출력 : 
92
"""

import sys

n = int(sys.stdin.readline().rstrip())

isused1 = [0]*40
isused2 = [0]*40
isused3 = [0]*40

cnt = 0

def func(cur):
    global n, cnt
    if (cur == n):
        cnt += 1
        return
    for i in range(n):
        if isused1[i] or isused2[cur+i] or isused3[cur-i+n-1] :
            continue
        isused1[i] = 1
        isused2[cur+i] = 1
        isused3[cur-i+n-1] = 1
        func(cur+1)
        isused1[i] = 0
        isused2[cur+i] = 0
        isused3[cur-i+n-1] = 0

func(0)
print(cnt)
        