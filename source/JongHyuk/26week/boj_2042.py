import sys
from math import *
sys.setrecursionlimit(10**6)
N,M,K=map(int,sys.stdin.readline().split())
number=[]
for _ in range(N):
    number.append(int(sys.stdin.readline()))
h=int(ceil(log2(N)))
t_size=1<<(h+1)
tree=[0 for _ in range(t_size)]
MOD=1000000007
def init_tree(start,end,node):
    if start==end:
        tree[node]=number[start]
        return tree[node]
    mid=(start+end)//2
    tree[node]=init_tree(start,mid,node*2)+init_tree(mid+1,end,node*2+1)
    return tree[node]

def update_tree(start,end,node,index,value):
    if index<start or end<index:
        return tree[node]
    if start==end:
        tree[node]=value
        return tree[node]
    mid=(start+end)//2
    tree[node]=update_tree(start,mid,node*2,index,value)+update_tree(mid+1,end,node*2+1,index,value)
    return tree[node]

def find_subsum(s,e,n,l,r):
    if l>e or r<s:
        return 0
    if l<=s and e<=r:
        return tree[n]
    mid=(s+e)//2
    return find_subsum(s,mid,n*2,l,r)+find_subsum(mid+1,e,n*2+1,l,r)
len_tree=len(number)
init_tree(0,len_tree-1,1)
for _ in range(M+K):
    a,b,c=map(int,sys.stdin.readline().split())
    if a==1:
        update_tree(0,len_tree-1,1,b-1,c)
    else:
        print(find_subsum(0,len_tree-1,1,b-1,c-1))
