from sys import stdin
from collections import deque

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]


class node:
  def __init__(self, pos_x, pos_y, r):
    self.posx = pos_x
    self.posy = pos_y
    self.r = r


def bfs(i):
  q = deque()
  q.append((i))

  while q:
    src = q.popleft()

    for dest in range(N):
      if not visited[dest] and connection[src][dest]:
        q.append((dest))
        visited[dest] = True


T = int(stdin.readline())
visited = [[]]

while T:
  N = int(stdin.readline())
  visited = [False for _ in range(N + 1)]
  connection = [[False] * N for _ in range(N)]
  nodes = []
  for _ in range(N):
    pos_x, pos_y, r_value = map(int, stdin.readline().split())

    nodes.append(node(pos_x, pos_y, r_value))

  for i in range(N):
    for j in range(N):
      if i == j: continue

      diff_x = nodes[i].posx - nodes[j].posx
      diff_y = nodes[i].posy - nodes[j].posy
      sum_r = nodes[i].r + nodes[j].r

      if (diff_x * diff_x + diff_y * diff_y) <= (sum_r * sum_r):
        connection[i][j] = connection[j][i] = True

  cnt = 0

  for i in range(N):
    if not visited[i]:
      visited[i] = True
      bfs(i)
      cnt += 1

  print(cnt)

  T -= 1
