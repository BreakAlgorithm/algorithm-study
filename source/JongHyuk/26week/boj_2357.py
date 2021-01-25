from sys import stdin
import sys
sys.setrecursionlimit(100000)
N,M=map(int,stdin.readline().split())
number=[]

for _ in range(N):
    number.append(int(stdin.readline()))
maxtree=[0 for _ in range(4*len(number))]
mintree=[0 for _ in range(4*len(number))]

def tree_max(start,end,node):
    if start==end:
        maxtree[node]=number[start]
        return maxtree[node]
    mid=(start+end)//2
    maxtree[node]=max(tree_max(start,mid,node*2),tree_max(mid+1,end,node*2+1))
    return maxtree[node]

def tree_min(start,end,node):
    if start==end:
        mintree[node]=number[start]
        return mintree[node]
    mid=(start+end)//2
    mintree[node]=min(tree_min(start,mid,node*2),tree_min(mid+1,end,node*2+1))
    return mintree[node]

def findMin(start,end,node,left,right):
    if left>end or right<start:
        return 1000000001
    if left<=start and end<=right:
        return mintree[node]
    mid=(start+end)//2
    return min(findMin(start,mid,node*2,left,right),findMin(mid+1,end,node*2+1,left,right))


def findMax(start,end,node,left,right):
    if left>end or right<start:
        return 0
    if left<=start and end<=right:
        return maxtree[node]
    mid=(start+end)//2
    return max(findMax(start,mid,node*2,left,right),findMax(mid+1,end,node*2+1,left,right))

tree_max(0,len(number)-1,1)
tree_min(0,len(number)-1,1)
len_num=len(number)
for _ in range(M):
    s,e=map(int,stdin.readline().split())
    print(findMin(0,len_num-1,1,s-1,e-1))

# a=[5,8,7,3,2,5,1,8,9,8,7,3]
# tree=[0 for _ in range(4*len(a))]
# import sys
# sys.setrecursionlimit(100000)
# def init_segment_tree(start,end,node):
#     if start==end:
#         tree[node]=a[start]
#         return tree[node]
#     mid=(start+end)//2
#     tree[node]=init_segment_tree(start,mid,node*2)+init_segment_tree(mid+1,end,node*2+1)
#     return tree[node]

# def _sum(s,e,n,l,r):
#     if l<=s and e<=r:
#         return tree[n]
#     if l>e or r<s:
#         return 0
#     m=(s+e)//2
#     return _sum(s,m,n*2,l,r)+_sum(m+1,e,n*2+1,l,r)
# init_segment_tree(0,len(a)-1,1)
# print(tree)
# print(_sum(0,len(a)-1,1,0,2))