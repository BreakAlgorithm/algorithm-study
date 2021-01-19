# from sys import stdin
# N=int(stdin.readline())
# M=int(stdin.readline())
# graph={}
# for i in range(1,N+1):
#     graph[i]=[]
# for i in range(1,N+1):
#     tmp=list(map(int,stdin.readline().split()))
#     for j in range(len(tmp)):
#         if tmp[j]==1:
#             graph[i].append(j+1)
# route=list(map(int,stdin.readline().split()))
# start=route[0]

# def is_possible(target):
#     visit=[False for _ in range(N+1)]
#     q=[]
#     global start
#     q.append(start)
#     while q:
#         s=q.pop()
#         if s==target:
#             start=target
#             return True
#         elif not visit[s]:
#             visit[s]=True
#             for end in graph[s]:
#                 if not visit[end]:
#                     q.append(end)

#     return False
# flag=True
# for target in route[1:]:
#     if not is_possible(target):
#         flag=False
#         break
# if flag:
#     print('YES')
# else:
#     print('NO')

from sys import stdin
N=int(stdin.readline())
M=int(stdin.readline())
parent=[0]
for i in range(1,N+1):
    parent.append(i)

def parent_find(x):
    if x==parent[x]:
        return x
    # p=parent_find(parent[x])
    # parent[x]=p
    # return parent[x]
    return parent_find(parent[x])

def union(x,y):
    x=parent_find(x)
    y=parent_find(y)
    if x!=y:
        parent[y]=x

for x in range(1,N+1):
    link=list(map(int,stdin.readline().split()))
    for y in range(1,len(link)+1):
        if link[y-1] ==1:
            union(x,y)

tour=list(map(int,stdin.readline().split()))
res=set([parent_find(i) for i in tour])
if len(res)==1:
    print("YES")
else:
    print("NO")

