import sys

if (len(sys.argv) == 4):
    from generate_random_board import generate_random_board
    from game_of_life import next_step
    from matrix import is_all_zero, print_matrix
    import time
    import pygame
    
    DIMENSION = int(sys.argv[1])
    ROW_AND_COLS = int(sys.argv[2])

    matrix = generate_random_board(ROW_AND_COLS)

    pygame.init()

    pygame.display.set_caption("Input the starting setup...")
    window_surface = pygame.display.set_mode((DIMENSION, DIMENSION))

    background = pygame.Surface((DIMENSION, DIMENSION))
    background.fill(pygame.Color('#000000'))

    is_running = True
    stopped = False

    while is_running:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                is_running = False

            if event.type == pygame.MOUSEBUTTONUP:
                pos = pygame.mouse .get_pos()
            
            if event.type == pygame.KEYDOWN:
                if event.key == 32:
                    stopped = not stopped


        if (not stopped):
            time_before = time.time()
            window_surface.blit(background, (0, 0))
            


            # PRINTING THE BOARD
            
            for i in range(len(matrix)):
                for j in range(len(matrix)):
                    if (matrix[i][j] == 1):
                        pygame.draw.rect(window_surface, pygame.Color('#d6d6d4'), ((DIMENSION/ROW_AND_COLS)*j, (DIMENSION/ROW_AND_COLS)*i, DIMENSION/ROW_AND_COLS, DIMENSION/ROW_AND_COLS))

            # DRAWING LINES

            for i in range(1, ROW_AND_COLS):
                pygame.draw.line(window_surface, pygame.Color('#262625'), (((DIMENSION/ROW_AND_COLS)*i), 0), (((DIMENSION/ROW_AND_COLS)*i), DIMENSION))
                pygame.draw.line(window_surface, pygame.Color('#262625'), (0,((DIMENSION/ROW_AND_COLS)*i)), (DIMENSION, ((DIMENSION/ROW_AND_COLS)*i)))

            # NEXT STEP AND DELAY

            matrix = next_step(matrix)
            
            pygame.display.update()
            time_after = time.time()

            delay = float(sys.argv[3])
            if (delay != -1):
                time.sleep(delay - (time_after - time_before))

else:
    print("python3 index.py <window-size> <number-rows> <delay>")