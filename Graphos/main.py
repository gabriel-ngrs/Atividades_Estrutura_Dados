# -*- coding: utf-8 -*-
from graph import Graph

def load_from(fileName):
    with open(fileName, 'r') as f:
        n = int(f.readline())
        g = Graph(n)
        for l in range(n):
            line = f.readline().strip()
            numeros = line.split("\t")
            c = 0
            for i in numeros:
                if c >= n:
                    break
                if i:  # Evita strings vazias
                    g.M[l][c] = int(i)
                    if int(i) != 0:
                        g.L[l].append(c)
                c += 1
    return g

if __name__ == "__main__":
    g = load_from("pcv4.txt")
    g.print()
    print("Número de Componentes:", g.num_comp())
    # Exemplo de uso do BFS para encontrar caminho
    s = 0
    t = 3
    g.bfs_path(s, t)