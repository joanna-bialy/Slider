#include <QVBoxLayout>

#include "ScoresPage.h"

ScoresPage::ScoresPage(QWidget *parent, QStackedLayout *const stackedLayout)
    : QWidget(parent),
      _stackedLayout(stackedLayout),
      _goToMenuButton(new QPushButton(tr("MENU"), this))
{
    QVBoxLayout *const layout = new QVBoxLayout(this);
    QLabel *const message = new QLabel(tr("This is scores page"));
    layout->addWidget(message);
    layout->addWidget(_goToMenuButton);
    connect(_goToMenuButton, &QPushButton::clicked, this, &ScoresPage::goToMenu);
}

