import sys
T, A, B = map(int, input().split())
def sprint(x, y):
    print(x, y)
    sys.stdout.flush()
    return input().strip()

for _ in range(T):
    points = [(5 * (10 ** 8), (-5 * (10 ** 8))),
              (-5 * (10 ** 8), (-5 * (10 ** 8))),
              (5 * (10 ** 8), 5 * (10 ** 8)),
              (-5 * (100 ** 8), 5 * (10 ** 8)), 
              (0, 0)]
    finish = False
    for point in points:
        res = sprint(*point)
        if res == "CENTER":
            finish = True
            break
        elif res == "HIT":
           x, y = point
           break

    if finish:
        continue

    # Calculate rightest x
    right_most = sprint(10 ** 9, y)
    if right_most == "CENTER":
        continue
    left_most = sprint(-10 ** 9, y)
    if left_most == "CENTER":
        continue
    rightest = None
    if right_most == "HIT":
        rightest = 10 ** 9
    else:
        l = x
        r = 10 ** 9
        while l < r - 1:
            m = (l + r) // 2
            m_res = sprint(m, y)
            if m_res == "CENTER":
                finish = True
                break
            elif m_res == res:
                l = m
            else:
                r = m
        rightest = l

    if finish:
        continue

    # Calculate leftest x
    leftest = None
    if left_most == "HIT":
        leftest = -10 ** 9
    else:
        l = -10 ** 9
        r = x
        while l < r - 1:
            m = (l + r) // 2
            m_res = sprint(m, y)
            if m_res == "CENTER":
                finish = True
                break
            elif m_res != res:
                l = m
            else:
                r = m
        leftest = l + 1
    if finish:
        continue

    cx = (leftest + rightest) // 2
    up_most = sprint(cx, 10 ** 9)
    if up_most == "CENTER":
        continue

    down_most = sprint(cx, -10 ** 9)
    if left_most == "CENTER":
        continue

    upest = None
    if up_most == "HIT":
        upest = 10 ** 9
    else:
        l = y
        r = 10 ** 9
        while l < r - 1:
            m = (l + r) // 2
            m_res = sprint(cx, m)
            if m_res == "CENTER":
                finish = True
                break
            elif m_res == "HIT":
                l = m
            else:
                r = m
        upest = l

    if finish:
        continue

    downest = None
    if down_most == "HIT":
        downest = -10 ** 9
    else:
        l = -10 ** 9
        r = y
        while l < r - 1:
            m = (l + r) // 2
            m_res = sprint(cx, m)
            if m_res == "CENTER":
                finish = True
                break
            elif m_res != "HIT":
                l = m
            else:
                r = m
        downest = l + 1

    if finish:
        continue
    cy = (upest + downest) // 2
    sprint(cx, cy)
    exit()
