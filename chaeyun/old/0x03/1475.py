from collections import Counter
import math

dct = Counter(input())
dct['9'] = math.ceil((dct['6']+dct['9'])/ 2)
if dct['6'] : dct.pop('6')
mc = dct.most_common(1)[0]
print(int(mc[1]))
