inputs = list(map(int, input().split()))
max_ = max(inputs)
min_ = min(inputs)
for i in inputs:
    if i != max_ and i!= min_:
        mid = i 
        
print(min_, mid, max_)