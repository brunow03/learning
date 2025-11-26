import pygame
import numpy as np

# Initialize pygame
pygame.init()

# --- CONFIGURATION ---
CELL_SIZE = 10      # Size of each cell in pixels
GRID_WIDTH = 80     # Number of cells horizontally
GRID_HEIGHT = 60    # Number of cells vertically
FPS = 10            # Frames per second (simulation speed)

# Window size
WIDTH = GRID_WIDTH * CELL_SIZE
HEIGHT = GRID_HEIGHT * CELL_SIZE

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GRAY = (40, 40, 40)

# Initialize window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Conway's Game of Life")

import pdb; pdb.set_trace()

# --- CREATE THE GRID ---
# 0 = dead cell, 1 = alive cell
grid = np.random.choice([0, 1], size=(GRID_HEIGHT, GRID_WIDTH))

# Control whether simulation runs automatically
running = False

pdb.set_trace()

# --- MAIN LOOP ---
clock = pygame.time.Clock()
done = False
while not done:
    pdb.set_trace()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True

        # Spacebar toggles simulation run/pause
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                running = not running

        # Mouse click toggles cells manually
        if pygame.mouse.get_pressed()[0]:
            x, y = pygame.mouse.get_pos()
            grid[y // CELL_SIZE, x // CELL_SIZE] = 1
        elif pygame.mouse.get_pressed()[2]:
            x, y = pygame.mouse.get_pos()
            grid[y // CELL_SIZE, x // CELL_SIZE] = 0

    # --- UPDATE GRID IF RUNNING ---
    if running:
        new_grid = np.copy(grid)

        # Iterate through each cell
        for y in range(GRID_HEIGHT):
            for x in range(GRID_WIDTH):
                # Count alive neighbors using slicing (wrap edges)
                neighbors = np.sum(grid[y-1:y+2, x-1:x+2]) - grid[y, x]

                # Apply Conway's rules
                if grid[y, x] == 1 and (neighbors < 2 or neighbors > 3):
                    new_grid[y, x] = 0   # Dies
                elif grid[y, x] == 0 and neighbors == 3:
                    new_grid[y, x] = 1   # Becomes alive

        grid = new_grid

    # --- DRAW GRID ---
    screen.fill(BLACK)
    for y in range(GRID_HEIGHT):
        for x in range(GRID_WIDTH):
            if grid[y, x] == 1:
                pygame.draw.rect(screen, WHITE,
                                 (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1))
            else:
                pygame.draw.rect(screen, GRAY,
                                 (x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1))

    pygame.display.flip()
    clock.tick(FPS)

pygame.quit()
