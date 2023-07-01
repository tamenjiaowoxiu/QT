#ifndef SUCCESSSCENE_H
#define SUCCESSSCENE_H

#include <QMainWindow>

class successscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit successscene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

};

#endif // SUCCESSSCENE_H
