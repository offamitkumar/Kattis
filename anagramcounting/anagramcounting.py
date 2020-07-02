import math
while True:
    try:
        x = input()
        total = math.factorial(len(x))
        y = [0] * 200
        for _ in x:
            y[ord(_)] += 1
        for _ in y:
            if _ > 0:
                total //= math.factorial(_)
        print(total)
    except EOFError:
        break
