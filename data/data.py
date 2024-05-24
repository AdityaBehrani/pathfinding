import random
import argparse

def create_graph(n: int, density: float, outfile: str):
    """Creates a datafile representing a graph."""

    with open(outfile, 'w', encoding="utf-8") as file:
        file.write(f'{n}\n')

        nodes = set(range(1, n))
        selected = set()
        edges = set()

        # ensures a fully connected graph
        curr = 0
        while nodes:
            nxt = nodes.pop()
            selected.add((curr, nxt))
            curr = nxt

        # generates all edges
        for i in range(n):
            for j in range(i + 1, n):
                edges.add((i, j))

        # random edge connections
        num_edges = int(len(edges) * density)
        file.write(f'{len(selected)}\n')
        for _ in range(num_edges):
            a, b = edges.pop()
            file.write(f'{a} {b} {random.randint(1, 10)}\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-n', type=int, help='The number of nodes')
    parser.add_argument('-d', type=float, help='1.0 is a complete graph, \
            and 0 contains N-1 edges (just enough to ensure each node is reachable)')
    parser.add_argument('-o', type=str, help='The output file')

    args = parser.parse_args()
    create_graph(args.n, args.d, args.o)
