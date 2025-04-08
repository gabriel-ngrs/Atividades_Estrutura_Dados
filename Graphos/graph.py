# -*- coding: utf-8 -*-
import queue

class Graph:
    def __init__(self, n):
        self.num_vertices = n
        self.M = [[0 for _ in range(n)] for _ in range(n)]
        self.L = [[] for _ in range(n)]

    def print(self):
        print("Número de Vértices: " + str(self.num_vertices))
        print("Matriz de adjacência:")
        for row in self.M:
            print(row)
        print("Lista de Adjacência:")
        for idx, lst in enumerate(self.L):
            print(f"{idx}: {lst}")
    
    def num_comp(self):
        pred = self.dfs()
        num = 0
        for v in range(self.num_vertices):
            if pred[v] == -1:
                num += 1
        return num
    
    def dfs(self):
        pred = [-1] * self.num_vertices
        visitados = [False] * self.num_vertices
        for v in range(self.num_vertices):
            if not visitados[v]:
                stack = [(v, -1)]  # (nó atual, predecessor)
                while stack:
                    current, prev = stack.pop()
                    if visitados[current]:
                        continue
                    visitados[current] = True
                    pred[current] = prev
                    # Empilha vizinhos em ordem reversa para manter a ordem correta
                    for neighbor in reversed(self.L[current]):
                        if not visitados[neighbor]:
                            stack.append((neighbor, current))
        return pred
    
    def bfs(self, source):
        visitados = [False] * self.num_vertices
        pred = [-1] * self.num_vertices
        D = [-1] * self.num_vertices
        Q = queue.Queue()
        Q.put(source)
        visitados[source] = True
        D[source] = 0
        
        while not Q.empty():
            v = Q.get()
            for u in self.L[v]:
                if not visitados[u]:
                    Q.put(u)
                    visitados[u] = True
                    D[u] = D[v] + 1
                    pred[u] = v
        
        return D, pred
    
    def bfs_path(self, s, t):
        D, pred = self.bfs(s)
        if D[t] == -1:
            print(f"Não há caminho entre os vértices {s} e {t}")
            return
        path = []
        current = t
        while current != -1:
            path.append(current)
            current = pred[current]
        path.reverse()
        print(f"Caminho entre {s} e {t}: {' -> '.join(map(str, path))}")