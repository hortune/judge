n = int(input())

automaton = [ 
            [1, 1, 1, 1, 1, 1, 1],
            [1, 0, 0, 0, 0, 0, 0],
            [1, 0, 1, 1, 0, 0, 0],
            [1, 0, 1, 1, 0, 0, 0],
            [1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1],
        ] 


while n:
    actions = input().strip()
    state = 0

    for ele in actions:
        ele = ord(ele) - ord('1')
        
        if automaton[state][ele]:
            state = ele
    print(state + 1)
    n -= 1
