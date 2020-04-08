#include "MainWindow.h"
#include "MenuPage.h"
#include "NewGamePage.h"
#include "LoadGamePage.h"
#include "GamePage.h"
#include "ScoresPage.h"
#include "QDesktopWidget"

#include <memory>

MainWindow::MainWindow(QWidget *parent)
  : QWidget(parent),
    _stackedLayout(new QStackedLayout(this))
{
  setWindowTitle(tr("Slide a puzzle"));
  setFixedSize(1100, 800);

  NewGamePage  *const newGamePage = new NewGamePage(this, _stackedLayout);
  LoadGamePage  *const loadGamePage = new LoadGamePage(this, _stackedLayout);
  GamePage  *const gamePage = new GamePage(this, _stackedLayout);
  ScoresPage  *const scoresPage = new ScoresPage(this, _stackedLayout);

  _stackedLayout->insertWidget(NEW_GAME_INDEX, newGamePage);
  _stackedLayout->insertWidget(LOAD_GAME_INDEX, loadGamePage);
  _stackedLayout->insertWidget(GAME_INDEX, gamePage);
  _stackedLayout->insertWidget(SCORES_INDEX, scoresPage);

  MenuPage *const menuPage = new MenuPage(this, _stackedLayout);
  _stackedLayout->insertWidget(MENU_INDEX, menuPage);
  _stackedLayout->setCurrentIndex(MENU_INDEX);
}
