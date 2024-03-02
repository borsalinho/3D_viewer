#ifndef SRC_MAZE_MODEL_PATHFINDER_H
#define SRC_MAZE_MODEL_PATHFINDER_H

#include <queue>
#include <vector>


#include "../point/point.h"
#include "../maze/maze.h"


class PathFinder {
 public:
  PathFinder() = default;

  // Point start;
  // Point end;

  void FindPath(const Maze* walls, const Point& start,
                          const Point& end) {
  std::vector<std::vector<bool>> visited(walls->wall_right_.size(),
                               std::vector<bool>(walls->wall_right_[0].size(), false));
  std::vector<std::vector<int>> wave(walls->wall_right_.size(),
                           std::vector<int>(walls->wall_right_[0].size(), -1));
  wave[start.y][start.x] = 0;
  std::deque<Point> q;
  q.push_back(start);
  while (!q.empty()) {
    Point current = q.front();
    q.pop_front();
    size_t y = current.y;
    size_t x = current.x;
    if (y == end.y && x == end.x) {
      path_.push_back(end);
      while (!(x == start.x && y == start.y)) {
        int dx = 0;
        int dy = 0;
        if (x > 0 && wave[y][x - 1] == wave[y][x] - 1 &&
            walls->wall_right_[y][x - 1] == 0) {
          dx = -1;
        } else if (x < walls->wall_right_.size() - 1 &&
                   wave[y][x + 1] == wave[y][x] - 1 &&
                   walls->wall_right_[y][x] == 0) {
          dx = 1;
        } else if (y > 0 && wave[y - 1][x] == wave[y][x] - 1 &&
                   walls->wall_down_[y - 1][x] == 0) {
          dy = -1;
        } else if (y < walls->wall_right_[0].size() - 1 &&
                   wave[y + 1][x] == wave[y][x] - 1 && walls->wall_down_[y][x] == 0) {
          dy = 1;
        }
        x += dx;
        y += dy;
        path_.insert(path_.begin(), Point(x, y));
      }
      return;
    }
    if (visited[y][x]) {
      continue;
    }
    visited[y][x] = true;
    static int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (const auto& dir : directions) {
      int dx = dir[0];
      int dy = dir[1];
      int nx = x + dx;
      int ny = y + dy;
      if (nx < 0 || nx >= walls->wall_right_.size() || ny < 0 ||
          ny >= walls->wall_right_[0].size()) {
        continue;
      }
      if (dy == 1 && walls->wall_down_[y][x] == 1) {
        continue;
      }
      if (dx == 1 && walls->wall_right_[y][x] == 1) {
        continue;
      }
      if (dy == -1 && walls->wall_down_[y - 1][x] == 1) {
        continue;
      }
      if (dx == -1 && walls->wall_right_[y][x - 1] == 1) {
        continue;
      }
      if (!visited[ny][nx]) {
        wave[ny][nx] = wave[y][x] + 1;
        q.push_back(Point(nx, ny));
      }
    }
  }
}

  void CleanPath() { 
    path_.clear(); 
  }

  std::vector<Point> GetPath() { 
    return path_; 
  }

 private:
  std::vector<Point> path_;
};

#endif  // SRC_MAZE_MODEL_PATHFINDER_H
