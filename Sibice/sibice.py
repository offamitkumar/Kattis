import math
t,l,b = map(int , input().split())
di = math.sqrt(l**2+b**2)
while t:
    t -= 1
    x = int(input())
    if x >di and x>l and x>b:
        print("NE")
    else:
        print("DA")
