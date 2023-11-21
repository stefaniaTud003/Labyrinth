#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Labyrinth.h"

class Labyrinth : public QMainWindow
{
    Q_OBJECT

public:
    Labyrinth(QWidget *parent = nullptr);
    ~Labyrinth();

private:
    Ui::LabyrinthClass ui;
};
