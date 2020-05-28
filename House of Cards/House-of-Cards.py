def tile(x):
    return (x*(3*x+1))//2
x=int(input())
while tile(x)%4 is not 0:
    x+=1
print(x)
