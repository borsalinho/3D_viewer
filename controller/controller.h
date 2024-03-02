#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>

#include "../Model/model.h"

class Controller {
 public:
  Controller(Model* m) : m_(m){};

  bool FileProcessing(const std::string& path) {
    return m_->FileProcessing(path);
  }

  Maze* GetMaze() { return m_->GetMaze(); }

  void LoadPath(Point start, Point end) { m_->LoadPath(start, end); }

  void CleanPath() { m_->CleanPath(); }

  std::vector<Point> GetPath() { return m_->GetPath(); }

  void GenerateMaze(int cols) { m_->GenerateMaze(cols); }

 private:
  Model* m_;
};

#endif  // CONTROLLER_H
