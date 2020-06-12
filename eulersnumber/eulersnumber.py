fact = [0]*10030
fact[0] = 1

for i in range(1,10004):
    fact[i] = fact[i-1]*i

n = int(input())
s = 1
for i in range(1,n+1):
    s = (s + (1/fact[i]))
print(s)
