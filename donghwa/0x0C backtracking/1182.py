"""
N개의 정수로 이루어진 수열이 있을 때, 
크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

- 입력 : 첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. 
    (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 
    둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 
    주어지는 정수의 절댓값은 100,000을 넘지 않는다.
- 출력 :
    첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.
    
ex.
Input :
5 0
-7 -3 -2 5 8
Output : 
1
"""

import sys

n, s = list(map(int, sys.stdin.readline().split()))
arr = list(map(int, sys.stdin.readline().split()))
cnt = 0


def func(cur, tot):
    global n, arr, cnt, s
    if (cur == n):
        if (tot == s) :
            cnt += 1
        return

    func(cur+1, tot)
    func(cur+1, tot+arr[cur])

func(0,0)
if (s==0) :
    cnt -= 1
print(cnt)