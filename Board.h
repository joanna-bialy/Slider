#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <set>
#include <vector>

#include "Position.h"

template<class T>
class Board
{
public:
    Board();
    Board(std::vector<T> values);

    void InsertValues(std::vector<T> values);
    bool MoveToBlank(Position position);
    bool CanBeMovedToBlank(Position position);
    bool IsPositionCorrect(Position position);

    std::map<Position, T> GetValues() const;
    Position GetBlankPosition() const;
    std::vector<Position> GetBlankNeighbors() const;
    Position* GetPositionForValue(T value) const;

private:
    typename std::map<Position, T> _boardMap;
    Position _blankPosition;
    int _dimension;
};

#endif // BOARD_H
