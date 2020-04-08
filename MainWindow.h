#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedLayout>

enum PageIndex
{
    MENU_INDEX = 0,
    NEW_GAME_INDEX = 1,
    LOAD_GAME_INDEX = 2,
    GAME_INDEX = 3,
    SCORES_INDEX = 4
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QStackedLayout *const _stackedLayout;

};

#endif // MAINWINDOW_H
