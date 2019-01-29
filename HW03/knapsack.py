const = int(1e3)
matrix = [[0 for i in range(const)] for j in range(const)]


def top_down(W, wt, val, n):
    n -= 1
    take, no_take = 0, 0
    if not (matrix[n][W] == 0):
        return matrix[n][W]
    if n == 0:
        if wt[0] <= W:
            matrix[n][W] = val[0]
            return val[0]
        else:
            matrix[n][W] = 0
            return 0
    if wt[n] <= W:
        take = val[n] + top_down(W - wt[n], wt, val, n)
    no_take = top_down(W, wt, val, n)
    matrix[n][W] = max(take, no_take)
    return matrix[n][W]


def bottom_up(W, wt, val, n):
    K = [[0 for _ in range(W + 1)] for _ in range(n + 1)]
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i - 1] <= w:
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]
    return K[n][W]


values = [1.2, 2.9, 1.8]
weights = [2.1, 2.2, 3.5]
W = 4.3
n = len(values)

div = 1e1
weights[:] = [int(x * div) for x in weights]
W = int(W*div)

print(top_down(W, weights, values, n))
print(bottom_up(W, weights, values, n))
