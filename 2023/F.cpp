from collections import deque

def get_prime_factors(num):
    factors = []
    i = 2
    while i * i <= num:
        if num % i:
            i += 1
        else:
            num //= i
            factors.append(i)
    if num > 1:
        factors.append(num)
    return factors

def build_graph(spider_legs):
    graph = {}
    for i, legs in enumerate(spider_legs, start=1):
        factors = get_prime_factors(legs)
        for factor in factors:
            node = 300001 + factor
            graph[i] = graph.get(i, []) + [node]
            graph[node] = graph.get(node, []) + [i]
    return graph

def bfs_shortest_path(graph, start, target):
    queue = deque([(start, 0)])
    visited = set()

    while queue:
        node, distance = queue.popleft()
        if node in visited:
            continue
        visited.add(node)

        if node == target:
            return distance

        for neighbor in graph[node]:
            queue.append((neighbor, distance + 1))

    return -1

def main():
    n = int(input())
    spider_legs = list(map(int, input().split()))
    s, t = map(int, input().split())

    graph = build_graph(spider_legs)
    shortest_distance = bfs_shortest_path(graph, s, t)

    if shortest_distance == -1:
        print(-1)
    else:
        print(shortest_distance // 2)

if __name__ == "__main__":
    main()
