#include "mainwindow.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include<QScrollBar>

#include"collection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    collection widgetCollection;
    widgetCollection.show();

    return a.exec();
}
