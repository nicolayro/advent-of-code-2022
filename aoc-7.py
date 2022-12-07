USABLE_SPACE = 70_000_000 - 30_000_000

class Directory:
    def __init__(self, parent, name) -> None:
        self.parent = parent
        self.name = name

        self.files = []
        self.dirs = []
    
    def add_file(self, file):
        self.files.append(file)
    
    def add_dir(self, dir):
        self.dirs.append(dir)
    
    def solve1(self, task1 = 0):
        size = 0
        for dir in self.dirs:
            task1, dir_size = dir.solve1(task1)
            size += dir_size

        for file in self.files:
            size += file.size

        task1 += size if size <= 100_000 else 0
        return task1, size
    
    def solve2(self, total_size, task2 = USABLE_SPACE):
        size = 0
        for dir in self.dirs:
            task2, dir_size = dir.solve2(total_size, task2)
            size += dir_size

        for file in self.files:
            size += file.size
        
        task2 = min(task2, size) if total_size - size <= USABLE_SPACE else task2
        return task2, size

    
    def __str__(self) -> str:
        return f'dir {self.name}'
    

class File:
    def __init__(self, name, size) -> None:
        self.name = name
        self.size = size

    def __str__(self):
        return f'file {self.name}\t{self.size}'

def change_directory(curr, new):
    if curr is None:
        return Directory(None, new)

    if new == '..':
        return curr.parent
    
    for dir in curr.dirs:
        if dir.name == new:
            return dir
    
    new_dir = Directory(curr, new)
    curr.add_dir(new_dir)
    return new_dir

def main():
    cd = None
    with open("build/data") as f:
        for line in f:
            tokens = line.strip().split(" ")
            if tokens[1] == 'cd':
                cd = change_directory(cd, tokens[2])
            elif tokens[0] == "dir":
                cd.add_dir(Directory(cd, tokens[1]))
            elif not tokens[1] == 'ls':
                cd.add_file(File(tokens[1], int(tokens[0])))

    while True:
        if cd.parent is None:
            break
        cd = cd.parent

    part1, total_size  = cd.solve1()
    part2, _ = cd.solve2(total_size)
    print(f'part1: {part1}')
    print(f'part2: {part2}')

if __name__ == "__main__":
    main()
