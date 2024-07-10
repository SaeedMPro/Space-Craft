import random
from typing import List
from dataclasses import dataclass

@dataclass
class Location:
    x: int
    y: int

def generate_map(x: int, y: int, start: Location) -> List[List[int]]:
    grid = [[0 for _ in range(y)] for _ in range(x)]
    grid[start.x][start.y] = 0
    
    #Destination
    dest = Location(random.randint(0, x - 1), random.randint(0, y - 1))
    while dest == start:
        dest = Location(random.randint(0, x - 1), random.randint(0, y - 1))
    grid[dest.x][dest.y] = 5

    #Wormhole
    wormhole_start = Location(random.randint(0, x - 1), random.randint(0, y - 1))
    while grid[wormhole_start.x][wormhole_start.y] != 0:
        wormhole_start = Location(random.randint(0, x - 1), random.randint(0, y - 1))
    wormhole_end = Location(random.randint(0, x - 1), random.randint(0, y - 1))
    while grid[wormhole_end.x][wormhole_end.y] != 0 or wormhole_end == wormhole_start:
        wormhole_end = Location(random.randint(0, x - 1), random.randint(0, y - 1))
    grid[wormhole_start.x][wormhole_start.y] = 4
    grid[wormhole_end.x][wormhole_end.y] = 4

    #Space Object(2*2)
    space_object_top_left = Location(random.randint(0, x - 2), random.randint(0, y - 2))
    while any(grid[space_object_top_left.x + dx][space_object_top_left.y + dy] != 0 for dx in range(2) for dy in range(2)):
        space_object_top_left = Location(random.randint(0, x - 2), random.randint(0, y - 2))
    for dx in range(2):
        for dy in range(2):
            grid[space_object_top_left.x + dx][space_object_top_left.y + dy] = 3

    #Space Current
    start_current = Location(random.randint(0, x - 1), random.randint(0, y - 1))
    while grid[start_current.x][start_current.y] != 0:
        start_current = Location(random.randint(0, x - 1), random.randint(0, y - 1))
    
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    current_length = 0
    max_length = min(10, x * y // 4) 
    while current_length < max_length:
        grid[start_current.x][start_current.y] = 1 if current_length == 0 else 2
        next_steps = [(start_current.x + dx, start_current.y + dy) for dx, dy in directions]
        valid_steps = [step for step in next_steps if 0 <= step[0] < x and 0 <= step[1] < y and grid[step[0]][step[1]] == 0]
        if not valid_steps:
            break
        start_current = Location(*random.choice(valid_steps))
        current_length += 1
    grid[start_current.x][start_current.y] = 1  # Mark the end of the current

    return grid

def print_map_to_file(grid: List[List[int]], file) -> None:
    for row in grid:
        file.write(' '.join(str(cell) for cell in row) + '\n')

def main() -> None:
    with open('testcase.txt', 'w') as file:
        n = 0
        while n < 1:
            x, y, energy = random.randint(2, 9), random.randint(2, 9), random.randint(1,int(1e3))
            start = Location(random.randint(0, x - 1), random.randint(0, y - 1))
            grid = generate_map(x, y, start)
            file.write(f"{x} {y}\n")
            file.write(f"{start.x} {start.y} {energy}\n")
            print_map_to_file(grid, file)
            n += 1

if "__main__" == __name__ :
    main()
