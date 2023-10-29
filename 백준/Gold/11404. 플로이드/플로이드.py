import sys
input = sys.stdin.readline

def printArr(arr):
    for a in range(1,len(arr)):
        for b in range(1,len(arr[0])):
            if(arr[a][b]==inf):
                print(0,end=" ")
            else:
                print(arr[a][b],end=" ")
        print()


inf = int(1e9)
n=int(input())
pair=int(input())
arr = [[inf] * (n+1) for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1,n+1):
        if(i==j):
            arr[i][j]=0

for _ in range(pair):
    start,arrive,cost = map(int,input().split())
    if(arr[start][arrive]>cost):    #경로가 하나가 아님에 주의할 것.
        arr[start][arrive]=cost

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j])

printArr(arr)
