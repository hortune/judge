dist = lambda x, y: abs(x[0] - y[0]) + abs(x[1] - y[1])
x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())
# first simulate 64 point
points = [(x0, y0)]
for i in range(1, 64):
    x = ax * points[i-1][0] + bx
    y = ay * points[i-1][1] + by
    points.append((x, y))


# enumerate the distance
# forward
ans = 0
for start in range(len(points)):
    for end in range(start, len(points)):
        tans = 0
        budget = dist(points[start], (xs, ys))
        if budget > t:
            continue
        tans += 1
        for i in range(1, end - start + 1):
            budget += dist(points[start + i], points[start + i - 1])
            if budget > t:
                break
            tans += 1
        ans = max(tans, ans)

        tans = 0
        budget = dist(points[end], (xs, ys))
        if budget > t:
            continue
        tans += 1
        for i in range(1, end - start + 1):
            budget += dist(points[end - i], points[end - i + 1])
            if budget > t:
                break
            tans += 1
        ans = max(tans, ans)
print(ans)
