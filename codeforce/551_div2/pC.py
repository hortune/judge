n = int(input())
state = list(input())

if ')' == state[0] or '(' == state[-1] or len(state) % 2 == 1:
    print(":(")
else:
    state[0] = '('
    state[-1] = ')'
    #get_left_most_')'
    left_index = 1
    right_index = 1
    question_index = 1
    while left_index != len(state) -1 and right_index != len(state) -1 and question_index != len(state) - 1: 
        while left_index < len(state) - 1:
            if state[left_index] == ')':
                break
            left_index += 1
        if left_index == len(state) - 1:
            break
        while right_index < left_index:
            if state[right_index] == '(':
                break
            right_index += 1

        if right_index == left_index:
            # find_first_question_mark
            while question_index < right_index:
                if state[question_index] == '?':
                    break
                question_index += 1

            if question_index == right_index:
                print(":(")
                exit()
            else:
                state[question_index] = '('
        left_index += 1
        right_index += 1
        question_index += 1
    
    left_index = len(state) - 2
    right_index = len(state) - 2
    question_index = len(state) - 2
    while left_index != 0 and right_index != 0 and question_index != 0: 
        while right_index > 0:
            if state[right_index] == '(':
                break
            right_index -= 1
        if right_index == 0:
            break
        while right_index < left_index:
            if state[left_index] == ')':
                break
            left_index -= 1

        if right_index == left_index:
            # find_first_question_mark
            while question_index > right_index:
                if state[question_index] == '?':
                    break
                question_index -= 1
            if question_index == right_index:
                print(":(")
                exit()
            else:
                state[question_index] = ')'
        left_index -= 1
        right_index -= 1
        question_index -= 1
    
    next_ele = '('
    for i in range(len(state)):
        if state[i] == '?':
            state[i] = next_ele
            next_ele = ')' if next_ele == '(' else '('

    print(''.join(state))
