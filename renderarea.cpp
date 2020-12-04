#include "renderarea.h"
#include <QPainterPath>
#include <QPainter>
#include <queue>
#include<cmath>


//clase para la zona de dibujo
RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    sol=false;
    shape = Rect;
    antialiased = true;
    transformed = false;
    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
void RenderArea::setLab(laberinto* _lab){
    this->lab=_lab;
    update();
}
void RenderArea::setSol(bool _sol){
    this->sol=_sol;
    update();
}

void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}
void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}
//paint event, el dibujo
void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);
    if(lab!=nullptr){
        int labwidth=lab->width;
        int labheight=lab->height;
        QRect testRect(0,0,width()/labwidth,height()/labheight);
        for(int i=0;i<labwidth;i++){
            for(int j=0;j<labheight;j++){
                painter.save();
                painter.translate(i*width()/labwidth,j*height()/labheight);
                if(this->lab->matriz[i][j]==1){
                    painter.setPen(palette().light().color());
                    painter.drawRect(testRect);
                }else{
                painter.drawRect(testRect);
                painter.fillRect(testRect,Qt::blue);
                }
                painter.setPen(palette().dark().color());
                painter.drawText(testRect,Qt::AlignCenter,
                                 tr(std::to_string(this->lab->matriz[i][j]).c_str()));
                painter.restore();
            }
        }
        if(sol){
            while(!lab->sol.empty()){
                lab->sol.pop();
            }
            nodoArbol* nodo=lab->getStart();
            lab->solve(nodo);
            while(!lab->sol.empty()){
                nodo=lab->sol.front();
                lab->sol.pop();
                painter.save();
                painter.setPen(Qt::red);
                painter.translate(nodo->corX*width()/labwidth,nodo->corY*height()/labheight);
                painter.drawRect(testRect);
                painter.setPen(palette().dark().color());
                painter.restore();
            }
        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
    /*
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QRect rect(10, 20, 80, 60);

    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);

    int startAngle = 20 * 16;
    int arcLength = 120 * 16;

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);
    for (int x = 0; x < width(); x += 100) {
        for (int y = 0; y < height(); y += 100) {
            painter.save();
            painter.translate(x, y);
            if (transformed) {
                painter.translate(50, 50);
                painter.rotate(60.0);
                painter.scale(0.6, 0.9);
                painter.translate(-50, -50);
            }
            switch (shape) {
            case Line:
                painter.drawLine(rect.bottomLeft(), rect.topRight());
                break;
            case Points:
                painter.drawPoints(points, 4);
                break;
            case Polyline:
                painter.drawPolyline(points, 4);
                break;
            case Polygon:
                painter.drawPolygon(points, 4);
                break;
            case Rect:
                painter.drawRect(rect);
                break;
            case RoundedRect:
                painter.drawRoundedRect(rect, 25, 25, Qt::RelativeSize);
                break;
            case Ellipse:
                painter.drawEllipse(rect);
                break;
            case Arc:
                painter.drawArc(rect, startAngle, arcLength);
                break;
            case Chord:
                painter.drawChord(rect, startAngle, arcLength);
                break;
            case Pie:
                painter.drawPie(rect, startAngle, arcLength);
                break;
            case Path:
                painter.drawPath(path);
                break;
            case Text:
                painter.drawText(rect,
                                 Qt::AlignCenter,
                                 tr("Qt by\nThe Qt Company"));
                break;
            case Pixmap:
                painter.drawPixmap(10, 10, pixmap);
            }
            painter.restore();
        }
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
    }*/

}
