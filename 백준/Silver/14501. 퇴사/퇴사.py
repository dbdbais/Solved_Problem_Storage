import sys
input = sys.stdin.readline

n=int(input())

t=list([0]*n)   #시간
p=list([0]*n)   #가격
dp=list([0]*(n+1))  #지금까지 저장된 값
for i in range(n):
    t[i],p[i]=map(int,input().split())

for i in range(n-1,-1,-1):
    if(t[i]+i>n):   #t[i]시간배열 + 지금 시간 (시간이 초과 할 경우 dp배열을 하나씩 이동)
        dp[i]=dp[i+1]
    else:
        dp[i]= max(dp[i+1],dp[t[i]+i]+p[i]) #일을 하지 않고 쉬었을 떄 , 일을 했을 때를 비교해 큰 값을 dp배열에 저장

print(dp[0])
