#ifndef TILEITEM_H
#define TILEITEM_H

#include <QString>
#include <QGraphicsScene>

#include "Position.h"

class TileItem
{
public:
    TileItem(int value, QGraphicsScene *scene, Position position);

    bool ContainsMousePosition(QPointF mousePoint);
    void MoveToPosition(Position position);
    Position GetPosition() const;
    int GetValue() const;

    static int PuzzleSideLength;
    static int Dimension;

private:
    QGraphicsTextItem* _textItem;
    QGraphicsRectItem* _rectItem;

    QGraphicsScene *_scene;
    Position _position;
    int _value;

    void AddToScene();
};

#endif // TILEITEM_H
