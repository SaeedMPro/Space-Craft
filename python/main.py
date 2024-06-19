from typing import List
from dataclasses import dataclass

testcase: str = "/home/acontius/amin/Learning/uni/4thsemester/algo/Project/Space-Craft/cpp/testcase.txt"

@dataclass
class Location:
    x: int
    y: int

def read_file(file_path: str) -> tuple:
    with open(file_path, 'r') as file:
        lines = file.readlines()
        
        size   = list(map(int, lines[0].strip().split()))
        info   = list(map(int, lines[1].strip().split()))
        location = Location(info[0], info[1])
        energy = info[2]
        
        space_map = []
        for line in lines[2:]:
            row = list(map(int, line.strip().split()))
            space_map.append(row)
        
        return size, location, energy, space_map

def main() -> None:
    size, location, energy, space_map = read_file(testcase)
    
    print(f"Size: {size}")
    print(f"Location: {location}")
    print(f"Initial Energy: {energy}")
    print("Space map:")
    for row in space_map:
        print(*row)

if __name__ == "__main__":
    main()
