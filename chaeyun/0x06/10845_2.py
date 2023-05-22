from sys import stdin

MX = 10000
dat = [0] * MX
head = 0
tail = 0

def push(x):
    global tail
    dat[tail] = x
    if tail == MX - 1:
        tail = 0
    else:
        tail += 1

def pop():
    global head
    if head == tail:
        print(-1)
    else:
        print(dat[head])
        if head == MX - 1:
            head = 0
        else:
            head += 1

def size():
    if head <= tail:
        return tail - head
    else:
        return tail + MX - head

def empty():
    return 1 if head == tail else 0

def front():
    if head == tail:
        print(-1)
    else:
        print(dat[head])

def back():
    if head == tail:
        print(-1)
    else:
        print(dat[tail - 1])

n = int(stdin.readline())

while n > 0:
    n -= 1
    cmd = stdin.readline().split()

    if cmd[0] == 'push':
        x = int(cmd[1])
        push(x)
    elif cmd[0] == 'pop':
        pop()
    elif cmd[0] == 'size':
        print(size())
    elif cmd[0] == 'empty':
        print(empty())
    elif cmd[0] == 'front':
        front()
    elif cmd[0] == 'back':
        back()
