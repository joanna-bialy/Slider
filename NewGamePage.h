#ifndef NEWGAMEPAGE_H
#define NEWGAMEPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>

#include "MainWindow.h"
#include "GamePage.h"

class NewGamePage : public QWidget
{
    Q_OBJECT

public:
    explicit NewGamePage(QWidget *parent, QStackedLayout *const stackedLayout);

public slots:
    void goToMenu()
    {
        _stackedLayout->setCurrentIndex(MENU_INDEX);
    }

    void goToGame()
    {
        int dimension = _dimensionComboBox->currentText().toInt();
        std::string playerName = _playerNameLineEdit->text().toUtf8().constData();

        auto* gameWidget =(GamePage*)(_stackedLayout->widget(GAME_INDEX));
        gameWidget->SetupGame(playerName, dimension);

        _stackedLayout->setCurrentIndex(GAME_INDEX);
    }

private:
    QStackedLayout *const _stackedLayout;
    QVBoxLayout *const _vboxLayout;

    QGridLayout* const _gridLayout;
    QLineEdit* const _playerNameLineEdit;
    QComboBox* const _dimensionComboBox;

    QPushButton *const _playButton;
    QPushButton *const _goToMenuButton;

    void InsertNewGameFormLayout();
    void InsertPlayButton();
    void InsertGoToMenuButton();
    void setEqualRowHeight(QFormLayout *formLayout, int height);
};
#endif // NEWGAMEPAGE_H
