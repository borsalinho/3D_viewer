#ifndef MODEL_H
#define MODEL_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "file/file.h"
#include "fileParser/fileParser.h"
#include "fileValidator/fileValidator.h"
#include "maze/maze.h"
#include "pathFinder/pathFinder.h"

class Model {  // Facade для Facade'ов
 public:
  Model(){};

  ~Model() {
    if (file_) delete file_;
    if (maze_) delete maze_;
    if (path_finder_) delete path_finder_;
  }

  bool FileProcessing(const std::string& path) {
    file_ = new File(path);
    FileValidator file_validator;
    FileParser file_parser;

    file_->OpenFile();

    if (!file_->GetStream()->is_open() || !file_validator.IsValid(file_)) {
      return false;
    }

    maze_ = new Maze;
    *maze_ = file_parser.Parsing(file_);
    file_->CloseFile();

    path_finder_ = new PathFinder;

    return true;
  }

  Maze* GetMaze() { return maze_; }

  void LoadPath(Point& start, Point& end) {
    ;
    path_finder_->FindPath(maze_, start, end);
  }

  void CleanPath() { path_finder_->CleanPath(); }

  std::vector<Point> GetPath() { return path_finder_->GetPath(); }

  void GenerateMaze(int cols) {
    std::cout << "я GenerateMaze " << std::endl;

    srand(time(0));
    maze_->cols_ = cols;
    maze_->rows_ = cols;

    // 1 сначало обнулим и пол и стенки
    for (int i = 0; i < maze_->cols_; i++) {
      for (int j = 0; j < maze_->rows_; j++) {
        maze_->wall_down_[i][j] = 0;
        maze_->wall_right_[i][j] = 0;
      }
    }
    std::vector<int> groups(maze_->cols_, 0);

    for (int i = 0; i < maze_->cols_; i++) {
      std::cout << groups[i] << ' ';
    }

    std::cout << std::endl;

    int group_num = 1;

    for (int j = 0; j < maze_->rows_ - 1; j++) {
      // 2 они все новые, поэтому присваиваю к каждой ячейке свою группу
      for (int i = 0; i < maze_->cols_; i++) {
        if (groups[i] == 0) {
          groups[i] = group_num++;
        }
      }

      std::cout << "я проверка групп" << std::endl;
      for (int i = 0; i < maze_->cols_; i++) {
        std::cout << groups[i] << ' ';
      }
      std::cout << std::endl;

      // 3 Добавление
      for (int i = 0; i < maze_->cols_ - 1; i++) {
        int res = RandomZeroOne();
        if (res == 1 || groups[i] == groups[i + 1]) {
          maze_->wall_right_[j][i] = 1;
        } else {
          for (int k = 0; k < maze_->cols_; k++) {
            if (groups[k] == groups[i + 1]) {
              groups[k] = groups[i];
            }
          }
        }
      }

      maze_->wall_right_[j][maze_->cols_ - 1] = 1;

      std::cout << "я проверка правых стенок после 3" << std::endl;
      for (int i = 0; i < maze_->cols_; i++) {
        std::cout << maze_->wall_right_[j][i] << ' ';
      }
      std::cout << std::endl;

      // 4
      for (int i = 0; i < maze_->cols_; i++) {
        int group_count = 0;
        for (int k = 0; k < maze_->cols_; k++) {
          if (groups[k] == groups[i]) {
            group_count++;
          }
        }
        int res = RandomZeroOne();
        if (group_count != 1 && res == 1) {
          maze_->wall_down_[j][i] = 1;
        }
      }

      std::cout << "я проверка нижних стенок после 4" << std::endl;
      for (int i = 0; i < maze_->cols_; i++) {
        std::cout << maze_->wall_down_[j][i] << ' ';
      }
      std::cout << std::endl;

      // 4.1   4.2
      for (int i = 0; i < maze_->cols_; i++) {
        int count_down = 0;
        for (int k = 0; k < maze_->cols_; k++) {
          if (groups[k] == groups[i] && maze_->wall_down_[j][k] == 0) {
            count_down++;
          }
        }

        if (count_down == 0) {
          maze_->wall_down_[j][i] = 0;
        }
      }

      std::cout << "я проверка нижних стенок после 4.1 4.2" << std::endl;
      for (int i = 0; i < maze_->cols_; i++) {
        std::cout << maze_->wall_down_[j][i] << ' ';
      }
      std::cout << std::endl;

      // 5.1

      for (int i = 0; i < maze_->cols_; i++) {
        if (maze_->wall_down_[j][i] == 1) {
          /* Присваиваем ячейки пустое множество */
          groups[i] = 0;
        }
      }

      std::cout << "я проверка групп в конце" << std::endl;
      for (int i = 0; i < maze_->cols_; i++) {
        std::cout << groups[i] << ' ';
      }
      std::cout << std::endl;
    }

    std::cout << "я ПОСЛДЕНЯЯ проверка групп" << std::endl;
    for (int i = 0; i < maze_->cols_; i++) {
      std::cout << groups[i] << ' ';
    }
    std::cout << std::endl;

    // 5.2
    //  2 они все новые, поэтому присваиваю к каждой ячейке свою группу
    for (int i = 0; i < maze_->cols_; i++) {
      if (groups[i] == 0) {
        groups[i] = group_num++;
      }
    }

    // 3 Добавление
    for (int i = 0; i < maze_->cols_ - 1; i++) {
      int res = RandomZeroOne();
      if (res == 1 || groups[i] == groups[i + 1]) {
        maze_->wall_right_[maze_->rows_ - 1][i] = 1;
      } else {
        for (int k = 0; k < maze_->cols_; k++) {
          if (groups[k] == groups[i + 1]) {
            groups[k] = groups[i];
          }
        }
      }
    }

    std::cout << "я ПОСЛДЕНЯЯ проверка правых стенок после 3" << std::endl;
    for (int i = 0; i < maze_->cols_; i++) {
      std::cout << maze_->wall_right_[maze_->rows_ - 1][i] << ' ';
    }
    std::cout << std::endl;

    for (int i = 0; i < maze_->cols_ - 1; i++) {
      if (groups[i] != groups[i + 1]) {
        maze_->wall_right_[maze_->rows_ - 1][i] = 0;

        for (int k = 0; k < maze_->cols_; k++) {
          if (groups[k] == groups[i + 1]) {
            groups[k] = groups[i];
          }
        }
      }
      maze_->wall_down_[maze_->rows_ - 1][i] = 1;
    }
    maze_->wall_down_[maze_->rows_ - 1][maze_->cols_ - 1] = 1;
  }

 private:
  File* file_;
  Maze* maze_;
  PathFinder* path_finder_;

  std::vector<int> sideLine_;
  int counter_;

  int RandomZeroOne() { return rand() % 2; }
};

#endif  // MODEL_H
