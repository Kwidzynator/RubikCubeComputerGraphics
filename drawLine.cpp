#include "drawline.h"
#include <iostream>
#include <cmath>
#include <QPoint>

DrawLine::DrawLine(QImage* image, int width, int height) {
    img = image;
    imgWidth = width;
    imgHeight = height;
}

bool DrawLine::checkIfInFrame(QPoint point) {
    return (point.rx() >= 0) && (point.ry() >= 0) && (point.rx() < imgWidth) && (point.ry() < imgHeight);
}

void DrawLine::paintingPixel(QPoint point) {
    if (!checkIfInFrame(point)) return;

    if(colour == 1){
        paintingGreen(point);
    }
    else if(colour == 2){
        paintingBlue(point);
    }
    else{
        unsigned char* ptr = img->bits();
        int index = imgWidth * 4 * point.ry() + 4 * point.rx();
        ptr[index] = 0;
        ptr[index + 1] = 0;
        ptr[index + 2] = 255;
    }
}

void DrawLine::paintingGreen(QPoint point) {
    if (!checkIfInFrame(point)) return;

    unsigned char* ptr = img->bits();


    int index = imgWidth * 4 * point.ry() + 4 * point.rx();
    ptr[index] = 0;
    ptr[index + 1] = 255;
    ptr[index + 2] = 0;

}

void DrawLine::paintingBlue(QPoint point){
    if (!checkIfInFrame(point)) return;

    unsigned char* ptr = img->bits();


    int index = imgWidth * 4 * point.ry() + 4 * point.rx();
    ptr[index] = 255;
    ptr[index + 1] = 0;
    ptr[index + 2] = 0;
}

void DrawLine::paintLine(QPoint startPoint, QPoint endPoint, int rd, int gr, int bl) {
    r = rd;
    g = gr;
    b = bl;

    int dx = endPoint.rx() - startPoint.rx();
    int dy = endPoint.ry() - startPoint.ry();

    if (dy == 0) {
        drawHorizontally(startPoint, endPoint);
    } else if (dx == 0) {
        drawVertically(startPoint, endPoint);
    } else if (abs(dx) >= abs(dy)) {
        drawDiagonallyX(startPoint, endPoint);
    } else {
        drawDiagonallyY(startPoint, endPoint);
    }
}

void DrawLine::drawHorizontally(QPoint start, QPoint end) {
    int direction = chooseDirectionX(start, end);
    for (int x = start.rx(); x != end.rx(); x += direction) {
        paintingPixel(QPoint(x, start.ry()));
    }
    paintingPixel(end);
}

void DrawLine::drawVertically(QPoint start, QPoint end) {
    int direction = chooseDirectionY(start, end);
    for (int y = start.ry(); y != end.ry(); y += direction) {
        paintingPixel(QPoint(start.rx(), y));
    }
    paintingPixel(end);
}

void DrawLine::drawDiagonallyX(QPoint start, QPoint end) {
    float a = calculateA(start, end);
    float b = calculateB(start, a);
    int direction = chooseDirectionX(start, end);

    for (int x = start.rx(); x != end.rx(); x += direction) {
        float y = a * x + b;
        paintingPixel(QPoint(x, static_cast<int>(y)));
    }
    paintingPixel(end);
}

void DrawLine::drawDiagonallyY(QPoint start, QPoint end) {
    float a = calculateA(start, end);
    float b = calculateB(start, a);
    int direction = chooseDirectionY(start, end);

    for (int y = start.ry(); y != end.ry(); y += direction) {
        float x = (y - b) / a;
        paintingPixel(QPoint(static_cast<int>(x), y));
    }
    paintingPixel(end);
}

float DrawLine::calculateA(QPoint startPoint, QPoint endPoint) {
    if (startPoint.rx() == endPoint.rx()) {
        return std::numeric_limits<float>::infinity();
    }
    return static_cast<float>(endPoint.ry() - startPoint.ry()) / (endPoint.rx() - startPoint.rx());
}

float DrawLine::calculateB(QPoint startPoint, float a) {
    return startPoint.ry() - a * startPoint.rx();
}

int DrawLine::chooseDirectionX(QPoint start, QPoint end) {
    return start.rx() < end.rx() ? 1 : -1;
}

int DrawLine::chooseDirectionY(QPoint start, QPoint end) {
    return start.ry() < end.ry() ? 1 : -1;
}

QPoint lerpa(QPoint a, QPoint b, float t) {
    return QPoint(
        static_cast<int>(a.x() * (1 - t) + b.x() * t),
        static_cast<int>(a.y() * (1 - t) + b.y() * t)
        );
}

void DrawLine::fillQuad(QPoint p1, QPoint p2, QPoint p3, QPoint p4, int rd, int gr, int bl) {
    r = rd;
    g = gr;
    b = bl;

    std::vector<QPoint> vertices = { p1, p2, p3, p4 };

    // Znajdź min i max Y
    int minY = std::min({p1.y(), p2.y(), p3.y(), p4.y()});
    int maxY = std::max({p1.y(), p2.y(), p3.y(), p4.y()});

    colour = (colour + 1) % 2;

    for (int y = minY; y <= maxY; ++y) {
        std::vector<int> xIntersections;

        for (int i = 0; i < 4; ++i) {
            QPoint a = vertices[i];
            QPoint b = vertices[(i + 1) % 4];

            if ((y >= a.y() && y < b.y()) || (y >= b.y() && y < a.y())) {
                float t = float(y - a.y()) / float(b.y() - a.y());
                int x = static_cast<int>(a.x() + t * (b.x() - a.x()));
                xIntersections.push_back(x);
            }
        }

        if (xIntersections.size() >= 2) {
            std::sort(xIntersections.begin(), xIntersections.end());
            for (int x = xIntersections[0]; x <= xIntersections[1]; ++x) {
                paintingPixel(QPoint(x, y));
            }
        }
    }
}
