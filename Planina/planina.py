itr = int(input())
start = 2
for _ in range(1 , itr+1):
    start += (start - 1)
print(start*start)
