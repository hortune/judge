from functools import cmp_to_key
from bisect import bisect_right, bisect_left


while True:
    n = int(input())
    if n == 0:
        break
    
    course = dict()
    
    students = [ tuple(sorted(list(map(int,input().split())))) for _ in range(n)]

    for student in students:
        course[student] = course[student]+1 if student in course else 1
    
    for index,student in enumerate(students):
        students[index] = course[student]
    
    students.sort()
    print(len(students) - bisect_left(students,students[-1]))
