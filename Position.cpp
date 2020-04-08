#include "Position.h"

Position::Position(int x, int y) : _x(x), _y(y)
{
}

void Position::operator=(const Position& p)
{
    _x = p.GetX();
    _y = p.GetY();
}

bool Position::operator<(const Position& p) const
{
    if (_y != p.GetY())
        return _y < p.GetY();
    else
        return _x < p.GetX();
}

bool Position::operator==(const Position& p) const
{

    return _x == p.GetX() && _y == p.GetY();
}

int Position::GetX() const
{
    return _x;
}

int Position::GetY() const
{
    return _y;
}
