from matrix import print_matrix

def count_neighbours(matrix, i, j):
    matrix_size = len(matrix)
    neighbours = 0

    if (i > 0):
        if (j > 0 and matrix[i-1][j-1]): neighbours += 1
        if (matrix[i-1][j]): neighbours += 1
        if (j < matrix_size-1 and matrix[i-1][j+1]): neighbours += 1

    if (j > 0 and matrix[i][j-1]): neighbours += 1
    if (j < matrix_size-1 and matrix[i][j+1]): neighbours += 1

    if (i < matrix_size-1):
        if (j > 0 and matrix[i+1][j-1]): neighbours += 1
        if (matrix[i+1][j]): neighbours += 1 
        if (j < matrix_size-1 and matrix[i+1][j+1]): neighbours += 1

    return neighbours


def next_step(matrix):
    matrix_size = len(matrix)
    new_matrix = []

    for i in range(matrix_size):
        row = []
        for j in range(matrix_size):
            neighbours = count_neighbours(matrix, i, j)

            if (matrix[i][j] == 1 and (neighbours != 3 and neighbours != 2)): row.append(0)
            elif (matrix[i][j] == 0 and neighbours == 3): row.append(1)
            else: row.append(matrix[i][j])
        
        new_matrix.append(row)
    
    return new_matrix
