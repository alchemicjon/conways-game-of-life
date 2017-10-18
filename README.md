# conways-game-of-life
An implementation of Conway's Game of Life written in C++

Conway's Game of Life takes place on a two-dimensional grid. Each cell in the grid is either alive or dead. As time passes, changes in the cells follow the below set of rules:

1. Each cell in the grid has 8 neighbors. These neighbors are the cells directly above, below, left, and right, diagonally above to the left and right, and diagonally below to the left and right.
2. If an occupied cell has 0 or 1 neighbors, it dies.
3. If an occupied cell more than 3 neighbors, it also dies.
4. If an empty cell has exactly 3 neighbors, a new cell is born in that space.
5. Births and deaths in each generation occur instantaneously. 
