factorial = [1] 
for i in range(1,10100):
    factorial.append(factorial[i-1]*i)

t = int(input())
for i in range(t):
    x = int(input())
    print (factorial[2*x] // (factorial[x+1] * factorial[x]))
