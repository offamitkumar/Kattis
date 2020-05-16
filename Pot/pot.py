t = int(input())
total = 0
while t:
    t -= 1
    x = int(input())
    pw = x%10
    x //= 10
    total += x**pw
print(total)
