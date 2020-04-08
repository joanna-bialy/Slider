#include <QGraphicsTextItem>

#include "TileItem.h"

int TileItem::PuzzleSideLength;
int TileItem::Dimension;

TileItem::TileItem(int value, QGraphicsScene *scene, Position position) :
    _textItem(new QGraphicsTextItem(QString::number(value))),
    _scene(scene),
    _value(value)
{
    QRectF rect;
    rect.setSize(QSize(PuzzleSideLength,PuzzleSideLength));
    _rectItem = _scene->addRect(rect, QPen(Qt::NoBrush), QBrush(QColor("gray")));

    _textItem->setFont(QFont("Times", 55-Dimension*4, QFont::Bold));
    _textItem->setZValue(1);
    _scene->addItem(_textItem);

    MoveToPosition(position);
}

bool TileItem::ContainsMousePosition(QPointF mousePoint)
{
    return (mousePoint.rx() >= _rectItem->pos().rx() && mousePoint.rx()< _rectItem->pos().rx()+PuzzleSideLength
            && mousePoint.ry() >= _rectItem->pos().ry() && mousePoint.ry()< _rectItem->pos().ry()+PuzzleSideLength);
}

void TileItem::MoveToPosition(Position position)
{
    _position = position;

    _rectItem->setPos(QPointF(_position.GetX()*PuzzleSideLength, _position.GetY()*PuzzleSideLength));

    if (position.GetX()+1 + _position.GetY()*Dimension < 10)
    {
        _textItem->setPos((_position.GetX()+0.4)*PuzzleSideLength, (_position.GetY()+0.3)*PuzzleSideLength);
    }
    else
    {
        _textItem->setPos((_position.GetX()+0.3)*PuzzleSideLength, (_position.GetY()+0.3)*PuzzleSideLength);
    }
}

Position TileItem::GetPosition() const
{
    return _position;
}

int TileItem::GetValue() const
{
    return _value;
}
