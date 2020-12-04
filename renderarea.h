#ifndef RENDERAREA_H
#define RENDERAREA_H
#include <QWidget>
#include <QPen>
#include "laberinto.h"

/*
 * clase de zona de dibujo, el codigo proviene del tutorial oficial de qt
 * (https://doc.qt.io/qt-5/qtwidgets-painting-basicdrawing-example.html)
 * se le agrega un apuntador al arbol, y un booleano para ver si estamos testeando o no.
 * ademas el paint event fue rehecho por completo para que dibujara el arbol
*/
class RenderArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
                 Chord, Pie, Path, Text, Pixmap };
    explicit RenderArea(QWidget *parent = nullptr);
    laberinto* lab;
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    bool sol;

public slots:
    void setSol(bool _set);
    void setLab(laberinto* _lab);
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
};

#endif // RENDERAREA_H
