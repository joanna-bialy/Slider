#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <vector>

#include "Position.h"
#include "TileItem.h"
#include "Board.h"
#include "Game.h"

class GameController
{
public:
    GameController(Game* game, int dimension = 0);

    void Start();
    void Mix();
    bool MoveToBlank(Position position);

    std::map<Position, int> GetValues() const;
    std::string GetValuesString() const;
    Position* GetPositionForValue(int value) const;
    int GetMoves() const;

    bool IsFinished() const;

    bool NavigateForward();
    bool NavigateBackward();
    bool CanNavigateBackward() const;
    bool CanNavigateForward() const;

    bool SaveGame();

private:
    std::unique_ptr<Game> _game;
    Board<int> _board;
    int _dimension;
    int _moves;

    std::vector<Position> _blankFieldForwardPositions;
    std::vector<Position> _blankFieldBackwardPositions;

    std::vector<int> CreateValuesVector(int dimension);  
};

#endif // GAMECONTROLLER_H
