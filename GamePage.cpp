#include <QHBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

#include "GamePage.h"
#include "TileItem.h"
#include "Position.h"

GamePage::GamePage(QWidget *parent, QStackedLayout *const stackedLayout)
    : QWidget(parent),
      _stackedLayout(stackedLayout),
      _horizonatalLayout(new QHBoxLayout(this)),
      _scene(new QGraphicsScene),
      _view(new QGraphicsView(_scene))
{
    _horizonatalLayout->addWidget(_view);
    InsertRightPanel();
}

void GamePage::SetupGame(std::string playerName, int dimension)
{
    _dimension = dimension;
    _playerName = playerName;

    InsertScene();
}

void GamePage::InsertScene()
{
    int puzzleSideLength = static_cast<int>(700/_dimension);

    TileItem::PuzzleSideLength = puzzleSideLength;
    TileItem::Dimension = _dimension;

    int boardSideLength = puzzleSideLength*_dimension;

    _view->setMinimumSize(boardSideLength + 2, boardSideLength + 2);
    _view->setMaximumSize(boardSideLength + 2, boardSideLength + 2);

    _scene->setSceneRect(0, 0, boardSideLength, boardSideLength);
}

void GamePage::DrawBoard()
{
    ClearBoard();

    auto values = _controller->GetValues();

    for (auto value: values)
    {
        if (value.second != 0)
        {
            TileItem puzzle = TileItem(value.second, _scene, value.first);
            _tiles.push_back(puzzle);
        }
    }
}

void GamePage::InsertRightPanel()
{
    auto* verticalLayout = new QVBoxLayout;
    _horizonatalLayout->addLayout(verticalLayout);

    _startButton = new QPushButton(tr("START"), this);
    _backwardButton = new QPushButton(tr("<-"), this);
    _forwardButton = new QPushButton(tr("->"), this);

    _movesLabel = new QLabel(this);
    _movesLabel->setFont(QFont("Times", 16));
    _movesLabel->setText("MOVES: 0");
    _movesLabel->setFixedSize(QSize(150,30));

    auto* goToMenuButton = new QPushButton(tr("MENU"), this);

    verticalLayout->addWidget(_startButton);
    verticalLayout->addWidget(_backwardButton);
    verticalLayout->addWidget(_forwardButton);
    verticalLayout->addWidget(_movesLabel);
    verticalLayout->addWidget(goToMenuButton);

    _startButton->setFixedSize(QSize(100, 30));
    _backwardButton->setFixedSize(QSize(100, 30));
    _forwardButton->setFixedSize(QSize(100, 30));
    goToMenuButton->setFixedSize(QSize(100, 30));

    verticalLayout->setContentsMargins(0,100,0,100);

    connect(_startButton, &QPushButton::clicked, this, &GamePage::startGame);
    connect(_backwardButton, &QPushButton::clicked, this, &GamePage::moveBackward);
    connect(_forwardButton, &QPushButton::clicked, this, &GamePage::moveForward);
    connect(goToMenuButton, &QPushButton::clicked, this, &GamePage::goToMenu);
}

void GamePage::ClearBoard()
{
    _scene->clear();
    _tiles.clear();
}

void GamePage::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Detect if the click is in the view.
        QPoint remapped =_view->mapFromParent( event->pos() );
        if ( _view->rect().contains( remapped ) )
        {
             QPointF mousePoint = _view->mapToScene(remapped);
             HandleMousePressedOnScene(mousePoint);
        }
    }
}

void GamePage::HandleMousePressedOnScene(QPointF mousePoint)
{
    for (auto& puzzle: _tiles)
    {
        if (puzzle.ContainsMousePosition(mousePoint))
        {
            if (_controller->MoveToBlank(puzzle.GetPosition()))
            {
                ClearBoard();
                DrawBoard();
                ReloadRightPanel();
            }
        }
    }

    if (_controller->IsFinished())
    {
        goToMenu();
    }
}

void GamePage::ReloadRightPanel()
{
    _forwardButton->setEnabled(_controller->CanNavigateForward());
    _backwardButton->setEnabled(_controller->CanNavigateBackward());

    _movesLabel->setText(QString("MOVES: " + QString::number(_controller->GetMoves())));
}

