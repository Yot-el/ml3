#ifndef RECT_H
#define RECT_H


class QPainter;
class Rect

{
public:
    Rect();
    Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

    virtual void draw(QPainter *painter);

    int getX1() const;
    void setX1(int newX1);

    int getY1() const;
    void setY1(int newY1);

    int getX2() const;
    void setX2(int newX2);

    int getY2() const;
    void setY2(int newY2);

private:
    int x1, y1, x2, y2;
};

#endif // RECT_H
