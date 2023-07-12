import random

def generate_random_board(n):
    board = []

    for i in range(n):
        row = []
        for j in range(n):
            row.append(random.randint(0, 1))
        
        board.append(row)
    
    return board
