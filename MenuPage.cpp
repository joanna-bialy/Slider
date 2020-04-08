#include <QPushButton>

#include "MenuPage.h"
#include "NewGamePage.h"
#include "LoadGamePage.h"
#include "GamePage.h"
#include "MainWindow.h"
#include "ScoresPage.h"

MenuPage::MenuPage(QWidget *parent, QStackedLayout *const stackedLayout)
  : QWidget(parent),
    _stackedLayout(stackedLayout),
    _boxLayout(new QVBoxLayout(this)),
    _signalMapper(new QSignalMapper(this))
{
  void(QSignalMapper::*signal)(int) = &QSignalMapper::mapped;
  connect(_signalMapper, signal, this, &MenuPage::buttonPressed);

  _boxLayout->setContentsMargins(400, 0, 400, 0);

  addButton("NEW GAME", NEW_GAME_INDEX);
  addButton("LOAD GAME", LOAD_GAME_INDEX);
  addButton("RESUME", GAME_INDEX);
  addButton("SCORES", SCORES_INDEX);

  connect(this, &MenuPage::buttonPressed, stackedLayout, &QStackedLayout::setCurrentIndex);
}

void MenuPage::addButton(QString buttonLabel, int indexButton)
{

  QString label = QString(buttonLabel);
  QPushButton *button = new QPushButton(label, this);
   button->setMinimumHeight(60);
   button->setFont(QFont("Times", 20, QFont::Bold));
  _boxLayout->addWidget(button);

  _signalMapper->setMapping(button, indexButton);
  connect(button, SIGNAL(clicked()), _signalMapper, SLOT(map()));
}
