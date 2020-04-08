#ifndef LOADGAMEPAGE_H
#define LOADGAMEPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>

#include "MainWindow.h"

class LoadGamePage : public QWidget
{
    Q_OBJECT

public:
    explicit LoadGamePage(QWidget *parent, QStackedLayout *const stackedLayout);

public slots:
    void goToMenu()
    {
        _stackedLayout->setCurrentIndex(MENU_INDEX);
    }

private:
    QStackedLayout *const _stackedLayout;
    QPushButton *const _goToMenuButton;
};

#endif // LOADGAMEPAGE_H
