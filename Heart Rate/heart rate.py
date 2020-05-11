n = int(input())
while n:
    n = n - 1
    b,p = input().split()
    b = int(b)
    p = float(p)
    print((b-1)*60/p , b*60/p , (b+1)*60/p)

