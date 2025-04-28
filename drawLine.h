#ifndef DRAWLINE_H
#define DRAWLINE_H

#include <QPoint>
#include <QImage>
#include <vector>
#include <limits>

class DrawLine {
public:

    DrawLine(QImage* image, int width, int height);

    void paintLine(QPoint startPoint, QPoint endPoint, int r, int g, int b);
    void drawHorizontally(QPoint start, QPoint end);
    void drawVertically(QPoint start, QPoint end);
    void drawDiagonallyX(QPoint start, QPoint end);
    void drawDiagonallyY(QPoint start, QPoint end);

    bool checkIfInFrame(QPoint point);
    void paintingPixel(QPoint point);
    void paintingGreen(QPoint point);

private:
    QImage* img;
    int imgWidth;
    int imgHeight;
    int colour;

    int r, g, b;
    float calculateA(QPoint startPoint, QPoint endPoint);
    float calculateB(QPoint startPoint, float a);
    int chooseDirectionX(QPoint start, QPoint end);
    int chooseDirectionY(QPoint start, QPoint end);

};

#endif
