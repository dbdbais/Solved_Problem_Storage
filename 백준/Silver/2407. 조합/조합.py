import sys
input = sys.stdin.readline

n,m = map(int,input().split())
bunja=n
bunmo=1
tmp=n
tmp2=1
for _ in range(m-1):
    tmp= tmp-1
    tmp2= tmp2 +1
    bunja *= tmp
    bunmo *= tmp2
print(bunja//bunmo)