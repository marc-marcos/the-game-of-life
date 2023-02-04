from matrix import read_matrix, print_matrix, is_all_zero
from game_of_life import count_neighbours, next_step
from generate_random_board import generate_random_board
import time, os

m = generate_random_board(50) 
counter = 0

os.system("clear")
while not is_all_zero(m):
    print_matrix(m) 
    print(f"Number of iterations: {counter}.")
    time.sleep(0.1)
    os.system("clear")
    m = next_step(m)
    counter += 1
