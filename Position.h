#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
    int _x;
    int _y;

public:
    Position() : _x(-1), _y(-1){}
    Position(int x, int y);

    void operator=(const Position& p);
    bool operator<(const Position& p) const;
    bool operator==(const Position& p) const;

    int GetX() const;
    int GetY() const;
};

#endif // POSITION_H
