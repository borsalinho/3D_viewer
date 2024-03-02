#ifndef MODEL_MAZE_H
#define MODEL_MAZE_H

#include <vector>

struct Maze {
    int cols_;
    int rows_;
    std::vector<std::vector<int>> wall_right_;
    std::vector<std::vector<int>> wall_down_;
};

#endif // MODEL_MAZE_H
