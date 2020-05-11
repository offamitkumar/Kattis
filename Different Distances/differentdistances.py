while True:
    try:
        x = list(map(float, input().split()))
        if len(x) is 1:
            break
        a,b,c,d,p = [x[i] for i in (0,1,2,3,4)]
        d1 = pow(abs(a-c),p)
        d2 = pow(abs(b-d),p)
        print(float(pow(d1+d2,1.0/p)))
    except EOFError:
        break

