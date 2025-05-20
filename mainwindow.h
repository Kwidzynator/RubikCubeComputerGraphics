#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "drawline.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DrawLine* drawline;

    int imgMatrix[4];
    std::vector<std::pair<int, int>> edges;
    std::array<std::array<double, 4>, 4> translateMatrix;
    std::array<std::array<double, 4>, 4> rotateMatrix;
    std::array<std::array<double, 4>, 4> rotateMatrixY;
    std::array<std::array<double, 4>, 4> rotateMatrixZ;
    std::array<std::array<double, 4>, 4> scaleMatrix;
    std::array<std::array<double, 4>, 4> shearingMatrixOX;
    std::array<std::array<double, 4>, 4> shearingMatrixOY;
    double cx;
    double cy;
    double d;
    double a;
    int freeSpaceX;
    int freeSpaceY;
    int height;
    int width;
    int imgBeginX;
    int imgBeginY;
    QImage* layerBehindImg;

    int edgeLength;
    std::array<std::array<double, 3>, 8> cubeCoordinates3D;
    std::vector<std::array<double, 3>> cubeCoordinates2D;
    std::array<std::array<double, 3>, 8> newCoordinates3D;

    std::vector<std::array<double, 3>> rubikVertices3D;
    std::vector<std::array<double, 3>> rubikVertices2D;
    std::vector<std::array<double, 3>> newRubikVertices3D;
    std::array<std::array<int, 4>, 6> walls;
    std::array<double, 3> camera;

    //std::map<int, std::vector<std::array<double, 4>>> walls;
    std::map<int, std::vector<std::array<double, 8>>> rubikFaces;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUpSliders();
    void setUpImg();
    void setUpCube();
    void resetSliders();
    void onSliderValueChanged(int);
    void sliderTranslateOX(int);
    void sliderTranslateOY(int);
    void sliderTranslateOZ(int);
    void sliderRotateOX(int);
    void sliderRotateOY(int);
    void sliderRotateOZ(int);

    void changeBottomLeft();
    void changeBottomRight();
    void changeTopLeft();
    void changeTopRight();

    void changeLeftDown();
    void changeRightDown();
    void changeLeftUp();
    void changeRightUp();

    void changeLeftDown_2();
    void changeRightDown_2();
    void changeLeftUp_2();
    void changeRightUp_2();

    enum class RubikMove{
        BottomLeft,
        BottomRight,
        TopLeft,
        TopRight,
        LeftDown,
        RightDown,
        LeftUp,
        RightUp,
        LeftDown_2,
        RightDown_2,
        LeftUp_2,
        RightUp_2
    };

    enum class Direction {
        Clockwise,
        CounterClockwise
    };

    void moveRubik(RubikMove move, Direction direction);
    void rotateRow(Direction direction, std::pair<int, int> excluded, int looked);
    void rotateCol(Direction direction, std::pair<int, int> excluded, int looked);
    void rotateCol_2(Direction direction, std::pair<int, int> excluded, int looked);

    void rotateBottomLeft(Direction direction);
    void rotateBottomRight(Direction direction);
    void rotateTopLeft(Direction direction);
    void rotateTopRight(Direction direction);
    void rotateLeftDown(Direction direction);
    void rotateRightDown(Direction direction);
    void rotateLeftUp(Direction direction);
    void rotateRightUp(Direction direction);

    void drawCube();
    void multiplicateMatrix();
    std::array<std::array<double, 4>, 4> getBiggerMatrix(std::array<std::array<double, 4>, 4>, std::array<std::array<double, 4>, 4>);
    void movePixel(double[4], std::vector<std::array<double, 3>> *);
    void copy(QImage *, QImage *);
    void clear(QImage *);
    std::array<double, 3> getCubeSection(std::array<double, 3>, std::array<double, 3>);
    std::array<double, 3> normalSection(std::array<double, 3>, std::array<double, 3>);
    std::array<double, 3> getViewSection(std::array<double, 3>, std::array<double, 3>);
    double getScalar(std::array<double, 3>, std::array<double, 3>);

    bool shouldConnect(int, int);
    void drawRubikFace(int);
    bool shouldConnectRubikVertices(int, int);

    struct Sticker{
        int faceId;
        int row;
        int col;
        int r;
        int g;
        int b;
    };

    Sticker* findSticker(int faceId, int row, int col);
    std::vector<Sticker> stickers;
    void setColour(MainWindow::Sticker* sticker, int faceId);
    void drawSticker(const Sticker& sticker, const QPoint& startPoint);

    std::array<int, 4> positionsOXOY;
    std::array<int, 4> positionsOXOZ;
    std::array<int, 4> positionsOYOZ;
private:
    Ui::MainWindow *ui;

private slots:
    void paintEvent(QPaintEvent*);

};

#endif // MAINWINDOW_H
