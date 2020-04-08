#include "Board.h"

#include <math.h>
#include <algorithm>

template<class T>
Board<T>::Board()
{
}

template<class T>
Board<T>::Board(std::vector<T> values)
{
    InsertValues(values);
}

template<class T>
void Board<T>::InsertValues(std::vector<T> values)
{
    _boardMap.clear();

    _dimension = (int)sqrt(values.size() + 1);

    int x = 0;
    int y = 0;

    for (auto setIterator = values.begin(); setIterator != values.end(); setIterator++)
    {
        _boardMap.insert({ Position(x, y) , *setIterator });

        if (x != _dimension - 1)
        {
            x++;
        }
        else
        {
            y++;
            x = 0;
        }
    }

    _blankPosition = Position(_dimension-1, _dimension-1);
}

template<class T>
std::map<Position, T> Board<T>::GetValues() const
{
    return _boardMap;
}

template<class T>
Position Board<T>::GetBlankPosition() const
{
    return _blankPosition;
}

template<typename T>
bool Board<T>::MoveToBlank(Position position)
{
    if (CanBeMovedToBlank(position))
    {
        auto valueOnBlank = _boardMap[_blankPosition];
        _boardMap[_blankPosition] = _boardMap[position];
        _boardMap[position] = valueOnBlank;
        _blankPosition = position;
        return true;
    }

    return false;
}

template<typename T>
bool Board<T>::CanBeMovedToBlank(Position position)
{
    if (IsPositionCorrect(position))
    {
        auto Xdistance = abs(position.GetX() - _blankPosition.GetX());
        auto Ydistance = abs(position.GetY() - _blankPosition.GetY());

        return Xdistance + Ydistance == 1;
    }

    return false;
}

template<typename T>
bool Board<T>::IsPositionCorrect(Position position)
{
    return position.GetX() >= 0 && position.GetX() < _dimension
            && position.GetY() >= 0 && position.GetY() < _dimension;
}

template<typename T>
Position* Board<T>::GetPositionForValue(T value) const
{
    Position *position;
    for (auto el: _boardMap)
    {
        if (el.second == value)
        {
            position = new Position(el.first);
            return position;
        }
    }

    return nullptr;
}

template<typename T>
std::vector<Position> Board<T>::GetBlankNeighbors() const
{
    std::vector<Position> neighbours;

    if (_blankPosition.GetX() > 0)
        neighbours.push_back(Position(_blankPosition.GetX()-1, _blankPosition.GetY()));

    if (_blankPosition.GetX() < _dimension-1)
        neighbours.push_back(Position(_blankPosition.GetX()+1, _blankPosition.GetY()));

    if (_blankPosition.GetY() > 0)
        neighbours.push_back(Position(_blankPosition.GetX(), _blankPosition.GetY()-1));

    if (_blankPosition.GetY() < _dimension-1)
        neighbours.push_back(Position(_blankPosition.GetX(), _blankPosition.GetY()+1));

    return neighbours;
}

template class Board<int>;
