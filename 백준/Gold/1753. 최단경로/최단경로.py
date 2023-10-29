import heapq
import sys
input = sys.stdin.readline

inf = int(1e9)      #무한대를 표현
v, e = map(int, input().split())    #정점과 간선을 입력받음
distance = [inf] * (v + 1);     #연산의 편의성을 위해 index 0 비워놓고 나머지는 무한대로 만든다.

graph = [[] for i in range(v + 1)]  #마찬가지로 연산의 편의성을 위해 index 0 비우고 i,j간의 가중치를 2차원배열로 표현

def dijkstra(start):
    distance[start] = 0     #시작 정점의 distance 를 0으로 만듬.
    heap = []                  #heap을 정의할 리스트.
    heapq.heappush(heap, (0, start))    #heap에 첫번 째 정점을 넣는다.(최소의 가중치를 가진다.)
    distance[start] = 0                 #자기자신으로 가는 distance는 0이므로 이니셜라이즈.

    for i in range(e):      #간선을 입력받는다.
        u,v,w = map(int,input().split())
        graph[u].append((v,w))      #2차원 배열에 저장.
    while heap:                     #Heap이 비어있지 않다면
        weight, vertice = heapq.heappop(heap)   #가중치와 정점을 꺼낸다(최소의 가중치를 가진다)

        if distance[vertice] < weight:  #start에서 방금 꺼낸 정점의 길이를 거치는 것보다 바로 가는게 작다면
            continue
        for element in graph[vertice]:     #방금 꺼낸 정점(번호)의 행을 돈다.
            cost = weight + element[1]      #지금 꺼낸 가중치와 2차원배열의 가중치를 더한다.
            if cost < distance[element[0]]:     #방금 꺼낸 정점을 거쳐 다른 정점으로 이동하는 것이 더 나은 경우
                distance[element[0]] = cost     #UPDATE
                heapq.heappush(heap, (cost, element[0]))    #heap에 현재 더한 cost와 거쳐서 도착한 정점을 PUSH한다.

def main():
    start = int(input())
    dijkstra(start)
    for i in range(1,v+1):
        if(distance[i]==inf):
            print("INF")
        else:
            print(distance[i])
main()










