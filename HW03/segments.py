import sys

n = int(input())
c = 4
x = []
y = []
x.append(-1)
y.append(-1)

for _ in range(n):
    point = input().split()
    x.append(int(point[0]))
    y.append(int(point[1]))


def calculate(i, j):
    sum_xy = 0
    sum_x = 0
    sum_y = 0
    sum_xq = 0
    for k in range(i, j + 1):
        sum_xy += x[k] * y[k]
        sum_x += x[k]
        sum_y += y[k]
        sum_xq += x[k] ** 2
    # print(i, " ", j, ": ", sum_x, " ", sum_y, " ", sum_xq, " ", sum_xy, end="")
    a = ((j - i + 1) * sum_xy - sum_x * sum_y) / ((j - i + 1) * sum_xq - sum_x ** 2)
    b = (sum_y - a * sum_x) / (j - i + 1)
    # print(a, ":a ", b, ":b ")
    sse = 0
    for k in range(i, j + 1):
        sse += (y[k] - a * x[k] - b) ** 2
    return sse


e = []
for i in range(n + 1):
    e.append([])
    for j in range(n + 1):
        if j <= i:
            e[i].append(0)
        else:
            e[i].append(calculate(i, j))


# ----------------------------- phase 1 (slide) -----------------------------
def opt(j):
    if j == 0:
        return 0
    mini = int(sys.maxsize)
    for i in range(1, j + 1):
        w = e[i][j] + c + opt(i - 1)
        if w < mini:
            mini = w
    return mini


print("slide: ", opt(n))

# ----------------------------- phase 2 (memoize) -----------------------------
m = [0]
for j in range(1, n+1):
    mini = int(sys.maxsize)
    for i in range(1, j+1):
        w = e[i][j] + c + m[i-1]
        if w < mini:
            mini = w
    m.append(mini)

print("memo:", m[n])
# ----------------------------- phase 3 (exercise) -----------------------------
M = [0]
for i in range(1, n+1):
    # print("i: ", i)
    k = 1
    mini = int(sys.maxsize)
    while i+k <= n:
        j = i + k
        # print("j: ", j)
        w = e[i][j] + c + M[i - 1]
        if w < mini:
            mini = w
        k += 1
    M.append(mini)

print("exercise:", M[n])
