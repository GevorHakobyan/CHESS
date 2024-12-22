#include <QApplication>
#include "Controller.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); 

    Controller controller;
    controller.Play(); 

    return app.exec(); 
}
