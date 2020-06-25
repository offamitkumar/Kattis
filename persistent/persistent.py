while True:
    x = int(input())
    if x is -1:
        break
    if x <=9 :
        print(x+10)
        continue
    factors=[]
    for i in range(9,1,-1):
        while x % i is 0:
            x = x//i
            factors.append(i)
    if x >= 10 :
        print("There is no such number.")
    else:
        factors.sort()
        for i in factors:
            print(i,end='')
        print('')
