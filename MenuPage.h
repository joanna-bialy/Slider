#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QStackedLayout>

#include "MainWindow.h"

class MenuPage : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPage(QWidget *parent, QStackedLayout *const stackedLayout);

    void addButton(QString buttonLabel, int indexButton);

signals:
    void buttonPressed(int button_number);

public slots:
    void goToMenu()
    {
        _stackedLayout->setCurrentIndex(MENU_INDEX);
    }

private:
    QStackedLayout *const _stackedLayout;
    QVBoxLayout *const _boxLayout;
    QSignalMapper *const _signalMapper;
};

#endif // MENUPAGE_H
