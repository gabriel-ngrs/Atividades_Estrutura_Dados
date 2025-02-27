# -*- coding: utf-8 -*-
from maze import Maze
from collections import deque

def main():
    maze_csv_path = "C:\Programação\Atividades_Estrutura_Dados\labirinto\labirinto1.txt"
    maze = Maze() 
    maze.load_from_csv(maze_csv_path)
    maze.init_player()  # Inicializa jogador e prêmio

    # Pilha para o backtracking
    stack = deque()
    initial_pos = maze.get_init_pos_player()
    stack.append(initial_pos)

    # Conjunto para rastrear posições visitadas
    visited = set()

    found = False

    while stack:
        current_pos = stack.pop()

        # Verifica se encontrou o prêmio
        if maze.find_prize(current_pos):
            print("\nTesouro encontrado na posição:", current_pos)
            found = True
            break

        # Marca a posição como visitada e move o jogador (simulação)
        visited.add(current_pos)
        x, y = current_pos

        # Obtém posições adjacentes válidas e não visitadas
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # cima, baixo, esquerda, direita
        for dx, dy in directions:
            new_x = x + dx
            new_y = y + dy

            # Verifica se está dentro dos limites do labirinto
            if 0 <= new_x < maze.M.shape[0] and 0 <= new_y < maze.M.shape[1]:
                new_pos = (new_x, new_y)
                if maze.is_free(new_pos) and new_pos not in visited:
                    stack.append(new_pos)

    if not found:
        print("\nNão foi possível encontrar o tesouro.")

if __name__ == "__main__":
    main()