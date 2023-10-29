import sys
input = sys.stdin.readline
from collections import deque

garden = []
M,N,H = map(int,input().split())
for i in range(H):
    tmp=[]
    for j in range(N):
        tmp.append(list(map(int,input().split())))
    garden.append(tmp)

xc=[-1,1,0,0,0,0]
yc=[0,0,-1,1,0,0]
zc=[0,0,0,0,-1,1]

queue = deque()
for i in range(H):
    for j in range(N):
        for k in range(M):
            if(garden[i][j][k]==1):
                queue.append((i,j,k))

while queue:
    x,y,z = queue.popleft()

    for i in range(6):
        qx= x+xc[i]
        qy= y+yc[i]
        qz= z+zc[i]
        if ((0<= qx< H) and (0<= qy < N) and(0<=qz <M) and (garden[qx][qy][qz]==0)):
            queue.append((qx,qy,qz))
            garden[qx][qy][qz] = garden[x][y][z] + 1

res = 0
flag= True

for i in range(H):
    for j in range(N):
        for k in range(M):
            if(res<garden[i][j][k]):
                res=garden[i][j][k]
            if(garden[i][j][k]==0):
                flag = False
                break

if (flag):
    print(res-1)
else:
    print(-1)
