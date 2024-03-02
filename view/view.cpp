#include "view.h"

#include "ui_view.h"

view::view(Controller *c, QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::view), c_(c) {
  ui_->setupUi(this);
}

view::~view() { delete ui_; }

void view::mousePressEvent(QMouseEvent *event) {
  if (repaintToUpdate_) {
    if (event->button() == Qt::LeftButton) {
      int x = event->position().x();
      int y = event->position().y();

      if (x > 10 && x <= 500 && y > 10 && y <= 500) {
        int cellWidth =
            ui_->maze_board->width() / c_->GetMaze()->rows_;  // width:500 px
        int cellHeight =
            ui_->maze_board->height() / c_->GetMaze()->cols_;  // height:500 px

        int resX = x / cellWidth + 1;
        int resY = y / cellHeight + 1;

        qDebug() << x << y;
        qDebug() << "res: " << resX << resY;

        if (countMouseClick_ == 0) {
          c_->CleanPath();

          SetStartPoint(resX, resY);
          countMouseClick_++;
        } else if (countMouseClick_ == 1) {
          SetEndPoint(resX, resY);
          countMouseClick_--;

          CreateFinderPath();
          repaint();
        }
      }
    } else {
      event->ignore();
      //   getter.CleanPath();
      c_->CleanPath();
      countMouseClick_ = 0;
    }
  }
}

void view::CreateFinderPath() {
  Point start;
  start.x = startPoint_.x - 1;
  start.y = startPoint_.y - 1;
  Point end;
  end.x = endPoint_.x - 1;
  end.y = endPoint_.y - 1;
  c_->LoadPath(start, end);
}

// отрисовка
void view::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  if (repaintToUpdate_) {
    painter.fillRect(rect(), Qt::black);
    painter.setPen(QPen(Qt::white, 2));

    int cellWidth =
        ui_->maze_board->width() / c_->GetMaze()->rows_;  // width:500 px
    int cellHeight =
        ui_->maze_board->height() / c_->GetMaze()->cols_;  // height:500 px

    painter.drawRect(10, 10, 500, 500);
    for (int i = 0; i < c_->GetMaze()->rows_; ++i) {
      for (int j = 0; j < c_->GetMaze()->cols_; ++j) {
        int x = j * cellWidth + 10;
        int y = i * cellHeight + 10;
        if (c_->GetMaze()->wall_down_[i][j]) {
          painter.drawLine(x, y + cellHeight, x + cellWidth, y + cellHeight);
        }

        if (c_->GetMaze()->wall_right_[i][j]) {
          painter.drawLine(x + cellWidth, y, x + cellWidth, y + cellHeight);
        }
      }
    }

    painter.setPen(QPen(Qt::green, 2));
    if (c_->GetPath().size() > 1) {
      for (unsigned int i = 0; i < c_->GetPath().size() - 1; ++i) {
        //        qDebug() << "p:" << controller_->GetPath()[i].x
        //                 << controller_->GetPath()[i].y;
        int startX = c_->GetPath()[i].x * cellWidth + cellWidth / 2 + 10;
        int startY = c_->GetPath()[i].y * cellHeight + cellHeight / 2 + 10;
        int endX = c_->GetPath()[i + 1].x * cellWidth + cellWidth / 2 + 10;
        int endY = c_->GetPath()[i + 1].y * cellHeight + cellHeight / 2 + 10;
        qDebug() << "from:" << startX << startY;
        qDebug() << "to:" << endX << endY;
        painter.drawLine(startX, startY, endX, endY);
      }
    }
  }
}

void view::on_OpenFIle_clicked() {
  QString path = QFileDialog::getOpenFileName(
      this, "Выберите файл", QDir::homePath() + "/Documents", "All Files (*)");

  ui_->file_name->setText(path);

  if (c_->FileProcessing(path.toStdString())) {
    repaintToUpdate_ = true;
  }
}

void view::SetStartPoint(int x, int y) {
  startPoint_.x = x;
  startPoint_.y = y;
}
void view::SetEndPoint(int x, int y) {
  endPoint_.x = x;
  endPoint_.y = y;
}

void view::on_BtnGenerateMaze_clicked() {
  if (repaintToUpdate_) {
    c_->GenerateMaze(ui_->spinBox_cols->text().toInt());
    repaint();
  }
}
