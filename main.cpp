#include "Labyrinth.h"
#include "Matrix.h"
#include <QtWidgets/QApplication>
#include <fstream>


int main(int argc, char *argv[])
{
    Matrix myMat;
    std::ifstream f("input.txt");
    f >> myMat;
    myMat.GenerateAdjacencyList();

    QApplication a(argc, argv);
    Labyrinth w;
    w.show();
    return a.exec();
    
}
