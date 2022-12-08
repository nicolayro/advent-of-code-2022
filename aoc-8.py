grid = []
with open("build/data") as f:
    for line in f:
        grid.append([int(tree) for tree in line.strip()])

part1 = 0
grid_len = len(grid)
for i in range(grid_len):
    for j in range(grid_len):
        tree = grid[i][j]

        # check left
        visible = True
        for k in range(j):
            if grid[i][k] >= tree:
                visible = False
                break
        
        if visible:
            part1 += 1
            continue

        # check right
        visible = True
        for k in range(j + 1, grid_len):
            if grid[i][k] >= tree:
                visible = False
                break
 
        if visible:
            part1 += 1
            continue

        # check top
        visible = True
        for k in range(i):
            if grid[k][j] >= tree:
                visible = False
                break

 
        if visible:
            part1 += 1
            continue

        # check bottom
        visible = True
        for k in range(i + 1, grid_len):
            if grid[k][j] >= tree:
                visible = False
                break

        if visible:
            part1 += 1
            continue


scores = []
for i in range(grid_len):
    for j in range(grid_len):
        if i == 0 or j == 0 or i == grid_len - 1 or j == grid_len - 1:
            continue

        tree = grid[i][j]

        # check left
        left = j
        for k in range(j):
            if grid[i][j - k - 1] >= tree:
                left = k + 1
                break
        
        # check right
        right = grid_len - j - 1
        for k in range(j + 1, grid_len):
            if grid[i][k] >= tree:
                right = k - j
                break
 
        # check top
        top = i
        for k in range(i):
            if grid[i - k - 1][j] >= tree:
                top = k + 1
                break

        # check bottom
        bottom = grid_len - i - 1
        for k in range(i + 1, grid_len):
            if grid[k][j] >= tree:
                bottom = k - i
                break
        
        scores.append(left * right * bottom * top)

print(f'part1 {part1}')
print(f'part2 {max(scores)}')
