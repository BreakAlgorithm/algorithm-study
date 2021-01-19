# from sys import stdin
# N,M,K=map(int,stdin.readline().split())
# cost=[0]+list(map(int,stdin.readline().split()))
# tree={}
# visit=[False for _ in range(N+1)]
# _cost=0

# for i in range(1,N+1):
#     tree[i]=[]
# for _ in range(M):
#     s,e=map(int,stdin.readline().split())
#     tree[s].append(e)
#     tree[e].append(s)

# def find_lc(i):
#     q=[i]
#     _min=100000000
#     while q:
#         start=q.pop()
#         _min=min(_min,cost[start])
#         visit[start]=True
#         for end in tree[start]:
#             if not visit[end]:
#                 q.append(end)
#     return _min
#     return 0


# for i in range(1,N+1):
#     if not visit[i]:
#         _cost+=find_lc(i)
# if _cost>K:
#     print('Oh no')
# else:
#     print(_cost)
from sys import stdin
import sys
sys.setrecursionlimit(1000000)
N,M,k=map(int,stdin.readline().split())
money=[0]+list(map(int,stdin.readline().split()))
parent=[0]+[i for i in range(1,N+1)]

def find_parent(x):
    if parent[x]==x:
        return x
    return find_parent(parent[x])

def union(x,y):
    x=find_parent(x)
    y=find_parent(y)
    if x!=y:
        parent[y]=x

for i in range(M):
    x,y=map(int,stdin.readline().split())
    if money[x]<=money[y]:
        union(x,y)
    else:
        union(y,x)
_cost=0
for a in set(parent):
    _cost+=money[a]
if _cost>k:
    print("Oh no")
else:
    print(_cost)
