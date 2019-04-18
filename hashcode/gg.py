import random
g = int(input())
H = []
V = []
scores = {}


for i in range(g):
    row = input().split()
    if row[0] == 'H':
        H.append(((i,),sorted(row[2:])))
    else:
        V.append((i,sorted(row[2:])))
    
    for ele in row[2:]:
        scores[ele] = scores.get(ele,0)+1

random.shuffle(V)
for i in range(0,round(len(V)),2):
    H.append(((V[i][0],V[i+1][0]), list(set([*V[i][1],*V[i+1][1]]))))

NH = []
for ele in H:
    score = 0
    t_scores = []
    for i in ele[1]:
        t_scores.append(scores[i])
    t_scores.sort(key=lambda k : -k)
    score = sorted(t_scores[:min(5,len(t_scores))], key=lambda k : -k)
    NH.append((ele[0],score))

NH.sort(key=lambda k: k[1])
print(len(NH))
for i in NH:
    if len(i[0]) == 2:
        print(i[0][1],i[0][0])
    else:
        print(i[0][0])

