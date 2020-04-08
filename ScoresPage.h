#ifndef SCORESPAGE_H
#define SCORESPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>

#include "MainWindow.h"

class ScoresPage : public QWidget
{
    Q_OBJECT

public:
    explicit ScoresPage(QWidget *parent, QStackedLayout *const stackedLayout);

public slots:
    void goToMenu()
    {
        _stackedLayout->setCurrentIndex(MENU_INDEX);
    }

private:
    QStackedLayout *const _stackedLayout;
    QPushButton *const _goToMenuButton;
};

#endif // SCORESPAGE_H
