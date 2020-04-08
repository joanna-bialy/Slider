#include "NewGamePage.h"
#include "GamePage.h"

#include <QSignalMapper>
#include <QComboBox>
#include <QStringListModel>

NewGamePage::NewGamePage(QWidget *parent, QStackedLayout *const stackedLayout)
    : QWidget(parent),
      _stackedLayout(stackedLayout),
      _vboxLayout(new QVBoxLayout),
      _gridLayout(new QGridLayout),
      _playerNameLineEdit(new QLineEdit),
      _dimensionComboBox(new QComboBox),
      _playButton(new QPushButton(tr("PLAY"))),
      _goToMenuButton(new QPushButton(tr("MENU")))
{
    InsertNewGameFormLayout();
    InsertPlayButton();
    InsertGoToMenuButton();

    _vboxLayout->setContentsMargins(400, 200, 400, 200);
    setLayout(_vboxLayout);
}

void NewGamePage::InsertNewGameFormLayout()
{
    QLabel *playerNameLabel = new QLabel(tr("Player name:"));
    QLabel *dimensionLabel = new QLabel(tr("Dimension:"));

    playerNameLabel->setBuddy(_playerNameLineEdit);
    dimensionLabel->setBuddy(_dimensionComboBox);

    QStringList items;
    items << tr("3") << tr("4") << tr("5") << tr("6") << tr("7") << tr("8") << tr("9") << tr("10") ;
    QStringListModel *dimensionModel = new QStringListModel(items);

    _dimensionComboBox->setModel(dimensionModel);
    _dimensionComboBox->setFixedHeight(30);

    playerNameLabel->setFont(QFont("Times", 18));
    _playerNameLineEdit->setFont(QFont("Times", 18));

    dimensionLabel->setFont(QFont("Times", 18));
    _dimensionComboBox->setFont(QFont("Times", 18));

    _gridLayout->addWidget(playerNameLabel, 0, 0, 1, 1);
    _gridLayout->addWidget(_playerNameLineEdit, 0, 1, 1, 1);

    _gridLayout->addWidget(dimensionLabel, 2, 0, 1, 1);
    _gridLayout->addWidget(_dimensionComboBox, 2, 1, 1, 1);

    _vboxLayout->insertLayout(0, _gridLayout);
}

void NewGamePage::InsertPlayButton()
{
    _vboxLayout->insertWidget(1, _playButton);
    _playButton->setMinimumHeight(60);
    _playButton->setFont(QFont("Times", 20, QFont::Bold));
    connect(_playButton, &QPushButton::clicked, this, &NewGamePage::goToGame);
}

void NewGamePage::InsertGoToMenuButton()
{
    _vboxLayout->insertWidget(2, _goToMenuButton);
    _goToMenuButton->setMinimumHeight(60);
    _goToMenuButton->setFont(QFont("Times", 20, QFont::Bold));
    connect(_goToMenuButton, &QPushButton::clicked, this, &NewGamePage::goToMenu);
}
