p = [];
p.append(1)

for i in range(500000):
    p.append((p[i] * (i + 1)))


n, m = map(int, input().split());

a = list(map(int, input().split()));

sum = 0;

for i in a:
    sum += p[i]

if sum % p[m] == 0:
    print("Yes")
else:
    print("No")