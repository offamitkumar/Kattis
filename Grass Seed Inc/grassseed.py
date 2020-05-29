cost = float(input())
n = int(input())
z = 0.0
while n>0:
    n -= 1
    x, y = map(float, input().split())
    z += (x*y)
print("{price:.6f}".format(price=cost*z))
