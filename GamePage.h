#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QMouseEvent>
#include <QGraphicsView>

#include "MainWindow.h"
#include "TileItem.h"
#include "GameController.h"

class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent, QStackedLayout *const stackedLayout);
    void SetupGame(std::string playerName, int dimension);

public slots:
    void goToMenu()
    {
        ClearBoard();
        _controller.reset();
        _stackedLayout->setCurrentIndex(MENU_INDEX);
        _startButton->setEnabled(true);
    }

    void startGame()
    {
        _controller = std::make_unique<GameController>(_dimension);
        _controller->Start();
        DrawBoard();
        _startButton->setEnabled(false);
        ReloadRightPanel();
    }

    void moveBackward()
    {
        if (_controller->NavigateBackward())
        {
            DrawBoard();
            ReloadRightPanel();
        }
    }

    void moveForward()
    {
        if (_controller->NavigateForward())
        {
            DrawBoard();
            ReloadRightPanel();
        }
    }

private:
    QStackedLayout *const _stackedLayout;
    QHBoxLayout *const _horizonatalLayout;

    QPushButton* _startButton;
    QPushButton* _backwardButton;
    QPushButton* _forwardButton;

    QLabel* _movesLabel;

    int _dimension;
    std::string _playerName;

    std::unique_ptr<GameController> _controller;

    QGraphicsScene* _scene;
    QGraphicsView* _view;
    std::vector<TileItem> _tiles;

    void InsertScene();
    void DrawBoard();
    void ClearBoard();
    void InsertRightPanel();
    void ReloadRightPanel();

    void HandleMousePressedOnScene(QPointF mousePoint);

    virtual void mousePressEvent(QMouseEvent *event) override;
};

#endif // GAMEPAGE_H
