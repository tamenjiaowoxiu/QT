#ifndef OTHERSCENE_H
#define OTHERSCENE_H

#include <QMainWindow>
#include "heroplane.h"

class OtherScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit OtherScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);


signals:

};

#endif // OTHERSCENE_H
