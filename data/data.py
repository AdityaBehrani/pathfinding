import random
N = 1000
print(N)
edges = set()

for i in range(N):
    for j in range(i + 1, N):
        edges.add((i, j))

selected = set()
nodes = {i for i in range(1, N)}

# ensures a fully connected graph
curr = 0
while nodes:
    next = nodes.pop()
    selected.add((curr, next))
    curr = next

# random edge connections
for _ in range(len(edges) // 200):
    selected.add(edges.pop())

print(len(selected))
for edge in selected:
    a, b = edge
    print(a, b, random.randint(1, 10)) 
