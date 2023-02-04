def read_matrix(n):
    output = []

    for i in range(n):
        row = []
        row_raw = input()
        for j in range(len(row_raw)):
            row.append(int(row_raw[j]))
        
        output.append(row)

    return output

def print_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if (matrix[i][j] == 0): print(" ", end = " ")
            else: print("#", end = " ")
        
        print("")

def is_all_zero(matrix):
    matrix_size = len(matrix);

    for i in range(matrix_size):
        for j in range(matrix_size):
            if (matrix[i][j] == 1): return False;
    
    return True;

def is_all_zero_bad(matrix):
    matrix_size = len(matrix);
    trobat = True

    for i in range(matrix_size):
        for j in range(matrix_size):
            if (matrix[i][j] == 1): trobat = False;
    
    return trobat;