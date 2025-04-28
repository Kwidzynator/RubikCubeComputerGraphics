#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QPainter>
#include <cmath>
#include "drawline.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpSliders();
    setUpImg();
    drawline = new DrawLine(layerBehindImg, width, height);
    setUpCube();


}


MainWindow::~MainWindow()
{
    delete ui;
    delete drawline;
}

void MainWindow::setUpSliders(){
    int minVal = -100;
    int maxVal = 100;

    ui->translationSliderOX->setMinimum(minVal);
    ui->translationSliderOX->setMaximum(maxVal);
    ui->translationSliderOX->setValue(0);

    ui->translationSliderOY->setMinimum(minVal);
    ui->translationSliderOY->setMaximum(maxVal);
    ui->translationSliderOY->setValue(0);

    ui->translationSliderOZ->setMinimum(minVal);
    ui->translationSliderOZ->setMaximum(maxVal);
    ui->translationSliderOZ->setValue(0);

    ui->rotationSliderOX->setMaximum(628);
    ui->rotationSliderOX->setValue(0);

    ui->rotationSliderOY->setMaximum(628);
    ui->rotationSliderOY->setValue(0);

    ui->rotationSliderOZ->setMaximum(628);
    ui->rotationSliderOZ->setValue(0);

    ui->scalingSliderOX->setMinimum(minVal);
    ui->scalingSliderOX->setMaximum(maxVal);
    ui->scalingSliderOX->setValue(0);

    ui->scalingSliderOY->setMinimum(minVal);
    ui->scalingSliderOY->setMaximum(maxVal);
    ui->scalingSliderOY->setValue(0);

    ui->scalingSliderOZ->setMinimum(minVal);
    ui->scalingSliderOZ->setMaximum(maxVal);
    ui->scalingSliderOZ->setValue(0);

    ui->shearingSliderOX->setMinimum(-70);
    ui->shearingSliderOX->setMaximum(70);
    ui->shearingSliderOX->setValue(0);

    ui->shearingSliderOY->setMinimum(-70);
    ui->shearingSliderOY->setMaximum(70);
    ui->shearingSliderOY->setValue(0);

    connect(ui->translationSliderOX, &QSlider::valueChanged, this, &MainWindow::sliderTranslateOX);
    connect(ui->translationSliderOY, &QSlider::valueChanged, this, &MainWindow::sliderTranslateOY);
    connect(ui->translationSliderOZ, &QSlider::valueChanged, this, &MainWindow::sliderTranslateOZ);
    connect(ui->rotationSliderOX, &QSlider::valueChanged, this, &MainWindow::sliderRotateOX);
    connect(ui->rotationSliderOY, &QSlider::valueChanged, this, &MainWindow::sliderRotateOY);
    connect(ui->rotationSliderOZ, &QSlider::valueChanged, this, &MainWindow::sliderRotateOZ);
    connect(ui->scalingSliderOX, &QSlider::valueChanged, this, &MainWindow::sliderScaleOX);
    connect(ui->scalingSliderOY, &QSlider::valueChanged, this, &MainWindow::sliderScaleOY);
    connect(ui->scalingSliderOZ, &QSlider::valueChanged, this, &MainWindow::sliderScaleOZ);
    connect(ui->shearingSliderOX, &QSlider::valueChanged, this, &MainWindow::sliderShearingOX);
    connect(ui->shearingSliderOY, &QSlider::valueChanged, this, &MainWindow::sliderShearingOY);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::resetSliders);
}

void MainWindow::setUpImg(){
    resize(900, 650);
    height = 600;
    width = 600;
    freeSpaceX = 25;
    freeSpaceY = 25;

    layerBehindImg = new QImage(width, height, QImage::Format_RGB32);

    translateMatrix[0] = {1, 0, 0, 0};
    translateMatrix[1] = {0, 1, 0, 0};
    translateMatrix[2] = {0, 0, 1, 0};
    translateMatrix[3] = {0, 0, 0, 1};

    rotateMatrix[0] = {1, 0, 0, 0};
    rotateMatrix[1] = {0, 1, 0, 0};
    rotateMatrix[2] = {0, 0, 1, 0};
    rotateMatrix[3] = {0, 0, 0, 1};

    rotateMatrixY[0] = {1, 0, 0, 0};
    rotateMatrixY[1] = {0, 1, 0, 0};
    rotateMatrixY[2] = {0, 0, 1, 0};
    rotateMatrixY[3] = {0, 0, 0, 1};

    rotateMatrixZ[0] = {1, 0, 0, 0};
    rotateMatrixZ[1] = {0, 1, 0, 0};
    rotateMatrixZ[2] = {0, 0, 1, 0};
    rotateMatrixZ[3] = {0, 0, 0, 1};

    scaleMatrix[0] = {1, 0, 0, 0};
    scaleMatrix[1] = {0, 1, 0, 0};
    scaleMatrix[2] = {0, 0, 1, 0};
    scaleMatrix[3] = {0, 0, 0, 1};

    shearingMatrixOX[0] = {1, 0, 0, 0};
    shearingMatrixOX[1] = {0, 1, 0, 0};
    shearingMatrixOX[2] = {0, 0, 1, 0};
    shearingMatrixOX[3] = {0, 0, 0, 1};

    shearingMatrixOY[0] = {1, 0, 0, 0};
    shearingMatrixOY[1] = {0, 1, 0, 0};
    shearingMatrixOY[2] = {0, 0, 1, 0};
    shearingMatrixOY[3] = {0, 0, 0, 1};



    imgBeginX = width / 2;
    imgBeginY = height / 2;
}


void MainWindow::setUpCube() {
    edgeLength = 200;
    double a = edgeLength / 2;
    double verDis = a / 1.5;
    cx = width / 2;
    cy = height / 2;
    d = 300;

    camera = {cx, cy, d};
    cubeCoordinates3D = {{
        {{-a, -a, -a}}, {{ a, -a, -a}}, {{ a,  a, -a}}, {{-a,  a, -a}},
        {{-a, -a,  a}}, {{ a, -a,  a}}, {{ a,  a,  a}}, {{-a,  a,  a}}
    }};

    newCoordinates3D = cubeCoordinates3D;

    for (const auto& coord : cubeCoordinates3D) {
        std::cout << coord[0] << " " << coord[1] << " " << coord[2] << std::endl;
    }

    for (const auto& coord : cubeCoordinates3D) {
        double x = coord[0];
        double y = coord[1];
        double z = coord[2];

        if (z == -d) {
            std::cout << "breaking" << std::endl;
            continue;
        }

        double x2D = cx + (x * d) / (z + d);
        double y2D = cy + (y * d) / (z + d);

        cubeCoordinates2D.push_back({x2D, y2D});
    }

    rubikVertices3D = {
        {-a + verDis, -a, -a}, {-a + verDis, a, -a},
        {a - verDis, -a, -a}, {a - verDis, a, -a},
        {-a, -a + verDis, -a}, { a, -a + verDis, -a},
        {-a, a - verDis, -a}, { a, a - verDis, -a}, //przód

        {-a, -a, -a + verDis}, {-a, a, -a + verDis},
        {-a, -a, a - verDis}, {-a, a, a - verDis},
        {-a, -a + verDis, -a}, {-a, -a + verDis, a},
        {-a, a - verDis, -a}, {-a, a - verDis, a}, //lewa

        {a, -a, -a + verDis}, {a, a, -a + verDis},
        {a, -a, a - verDis}, {a, a, a - verDis},
        {a, -a + verDis, -a}, {a, -a + verDis, a},
        {a, a - verDis, -a}, {a, a - verDis, a}, //prawa

        {-a + verDis, -a, a}, {-a + verDis, a, a},
        {a - verDis, -a, a}, {a - verDis, a, a},
        {-a, -a + verDis, a}, { a, -a + verDis, a},
        {-a, a - verDis, a}, { a, a - verDis, a}, //tył

        {-a, -a, -a + verDis}, {a, -a, -a + verDis},
        {-a, -a, a - verDis}, {a, -a, a - verDis},
        {-a + verDis, -a, -a}, {-a + verDis, -a, a},
        {a - verDis, -a, -a}, {a - verDis, -a, a}, //góra

        {-a, a, -a + verDis}, {a, a, -a + verDis},
        {-a, a, a - verDis}, {a, a, a - verDis},
        {-a + verDis, a, -a}, {-a + verDis, a, a},
        {a - verDis, a, -a}, {a - verDis, a, a}, //dół

        {-a, -a, -a}, { a, -a, -a},
        { a,  a, -a}, {-a,  a, -a},
        {-a, -a,  a}, { a, -a,  a},
        { a,  a,  a}, {-a,  a,  a},

        {-a, -a, -a}, {-a, -a, a},
        {a, -a, -a}, {a, -a, a},
        {-a, a, -a}, {-a, a, a},
        {a, a, -a}, {a, a, a},

        {-a, -a, -a}, {-a, a, -a},
        {a, -a, -a,}, {a, a, -a},
        {a, -a, a}, {a, a, a},
        {-a, -a, a}, {-a, a, a}


    };


    rubikFaces = {
        {0, {  // Front
                {-a + verDis, -a, -a}, {-a + verDis, a, -a},
                {a - verDis, -a, -a}, {a - verDis, a, -a},
                {-a, -a + verDis, -a}, { a, -a + verDis, -a},
                {-a, a - verDis, -a}, { a, a - verDis, -a},
            }},
        {1, {  // Back
                {-a + verDis, -a, a}, {-a + verDis, a, a},
                {a - verDis, -a, a}, {a - verDis, a, a},
                {-a, -a + verDis, a}, { a, -a + verDis, a},
                {-a, a - verDis, a}, { a, a - verDis, a},
            }},
        {2, {  // Left
                {-a, -a, -a + verDis}, {-a, a, -a + verDis},
                {-a, -a, a - verDis}, {-a, a, a - verDis},
                {-a, -a + verDis, -a}, {-a, -a + verDis, a},
                {-a, a - verDis, -a}, {-a, a - verDis, a},
            }},
        {3, {  // Right
                {a, -a, -a + verDis}, {a, a, -a + verDis},
                {a, -a, a - verDis}, {a, a, a - verDis},
                {a, -a + verDis, -a}, {a, -a + verDis, a},
                {a, a - verDis, -a}, {a, a - verDis, a},
            }},
        {4, {  // Top
                {-a, -a, -a + verDis}, {a, -a, -a + verDis},
                {-a, -a, a - verDis}, {a, -a, a - verDis},
                {-a + verDis, -a, -a}, {-a + verDis, -a, a},
                {a - verDis, -a, -a}, {a - verDis, -a, a},
            }},
        {5, {  // Bottom
                {-a, a, -a + verDis}, {a, a, -a + verDis},
                {-a, a, a - verDis}, {a, a, a - verDis},
                {-a + verDis, a, -a}, {-a + verDis, a, a},
                {a - verDis, a, -a}, {a - verDis, a, a},
            }}
    };

    for (const auto& coord: rubikVertices3D) {
        double x = coord[0];
        double y = coord[1];
        double z = coord[2];

        if (z == -d) {
            std::cout << "breaking" << std::endl;
            continue;
        }

        double x2D = cx + (x * d) / (z + d);
        double y2D = cy + (y * d) / (z + d);

        rubikVertices2D.push_back({x2D, y2D});
    }

    walls = {{
        {0, 1, 2, 3}, // przód
        {4, 5, 6, 7}, // tył
        {0, 3, 7, 4}, //lewo
        {1, 2, 6, 5}, //prawo
        {0, 4, 5, 1}, // góra
        {2, 6, 7, 3},// dół
    }};


    drawCube();
}

void MainWindow::copy(QImage* copied, QImage* edited) {
    unsigned char *ptrCopied = copied->bits();
    unsigned char *ptrEdited = edited->bits();

    int moveY;
    int moveX;

    for (int y = 0; y < copied->height(); y++) {
        for (int x = 0; x < copied->width(); x++) {
            moveY = y + imgBeginX;
            moveX = x + imgBeginY;
            ptrEdited[width * 4 * moveY + 4 * moveX] = ptrCopied[copied->width() * 4 * y + 4 * x];
            ptrEdited[width * 4 * moveY + 4 * moveX + 1] = ptrCopied[copied->width() * 4 * y + 4 * x + 1];
            ptrEdited[width * 4 * moveY + 4 * moveX + 2] = ptrCopied[copied->width() * 4 * y + 4 * x + 2];
        }
    }
    update();
}


void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(freeSpaceX, freeSpaceY, *layerBehindImg);
    //p.drawImage((width - img->width()) / 2 + freeSpaceX, (height - img->height()) / 2 + freeSpaceY, *img);
}

void MainWindow::resetSliders()
{
    ui->translationSliderOX->setValue(0);
    ui->translationSliderOY->setValue(0);
    ui->translationSliderOZ->setValue(0);
    ui->rotationSliderOX->setValue(0);
    ui->rotationSliderOY->setValue(0);
    ui->rotationSliderOZ->setValue(0);
    ui->scalingSliderOX->setValue(0);
    ui->scalingSliderOY->setValue(0);
    ui->scalingSliderOZ->setValue(0);
    ui->shearingSliderOX->setValue(0);
    ui->shearingSliderOY->setValue(0);

    setUpCube();
}

void MainWindow::sliderTranslateOX(int value) {
    ui->translationSliderOX->setValue(value);
    clear(layerBehindImg);

    double valueToDouble = static_cast<double>(value);

    translateMatrix[0][3] = -valueToDouble;
    multiplicateMatrix();


}

void MainWindow::sliderTranslateOY(int value) {
    ui->translationSliderOY->setValue(value);
    clear(layerBehindImg);

    double valueToDouble = static_cast<double>(value);

    translateMatrix[1][3] = -valueToDouble;

    multiplicateMatrix();

}

void MainWindow::sliderTranslateOZ(int value){
    ui->translationSliderOZ->setValue(value);

    clear(layerBehindImg);

    double valueToDouble = static_cast<double>(value);

    translateMatrix[2][3] = -valueToDouble;

    multiplicateMatrix();
}

void MainWindow::sliderRotateOX(int value){
    ui-> rotationSliderOX->setValue(value);
    double valueToDouble = static_cast<double>(value) * M_PI / 180.0f;
    clear(layerBehindImg);


    rotateMatrix[1] = {0, cos(valueToDouble), -sin(valueToDouble), 0};
    rotateMatrix[2] = {0, sin(valueToDouble), cos(valueToDouble), 0};

    multiplicateMatrix();

}

void MainWindow::sliderRotateOY(int value){
    ui-> rotationSliderOY->setValue(value);
    double valueToDouble = static_cast<double>(value) * M_PI / 180.0f;
    clear(layerBehindImg);


    rotateMatrixY[0] = {cos(valueToDouble), 0,  sin(valueToDouble), 0};
    rotateMatrixY[2] = {-sin(valueToDouble), 0,  cos(valueToDouble), 0};

    multiplicateMatrix();
}

void MainWindow::sliderRotateOZ(int value){
    ui-> rotationSliderOZ->setValue(value);
    double valueToDouble = static_cast<double>(value) * M_PI / 180.0f;
    clear(layerBehindImg);


    rotateMatrixZ[0] = {cos(valueToDouble), -sin(valueToDouble), 0, 0};
    rotateMatrixZ[1] = {sin(valueToDouble), cos(valueToDouble), 0, 0};

    multiplicateMatrix();
}

void MainWindow::sliderScaleOX(int value){
    ui->scalingSliderOX->setValue(value);
    double valueToDouble = static_cast<double>(value/ 100.0f);

    clear(layerBehindImg);

    scaleMatrix[0][0] = std::max(valueToDouble + 1.0, 0.1);

    multiplicateMatrix();
}

void MainWindow::sliderScaleOY(int value){
    ui->scalingSliderOY->setValue(value);
    double valueToDouble = static_cast<double>(value / 100.0f);
    clear(layerBehindImg);


    scaleMatrix[1][1] = std::max(valueToDouble + 1.0, 0.1);

    multiplicateMatrix();
}

void MainWindow::sliderScaleOZ(int value){
    ui->scalingSliderOZ->setValue(value);
    double valueToDouble = static_cast<double>(value / 100.0f);
    clear(layerBehindImg);


    scaleMatrix[2][2] = std::max(valueToDouble + 1.0, 0.1);

    multiplicateMatrix();
}

void MainWindow::sliderShearingOX(int value){
    ui->shearingSliderOX->setValue(value);
    double valueToDouble = static_cast<double>(value / 100.0f);
    clear(layerBehindImg);

    shearingMatrixOX[2][0] = -valueToDouble;

    multiplicateMatrix();
}

void MainWindow::sliderShearingOY(int value){
    ui->shearingSliderOY->setValue(value);
    double valueToDouble = static_cast<double>(value / 100.0f);
    clear(layerBehindImg);

    shearingMatrixOX[2][1] = -valueToDouble;


    multiplicateMatrix();
}

void MainWindow::clear(QImage *image){
    unsigned char *ptr;
    ptr = image->bits();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ptr[width * 4 *y + 4 * x] = 0;
            ptr[width * 4 *y + 4 * x + 1] = 0;
            ptr[width * 4 * y + 4 * x+ 2] = 0;
        }
    }

}

void MainWindow::multiplicateMatrix() {
    double resultMatrix[4] = {0, 0, 0, 1};
    std::array<std::array<double, 4>, 4> calculatedMatrix;
    double adjustedZ = 1.0;

    calculatedMatrix[0] = {1, 0, 0, 0};
    calculatedMatrix[1] = {0, 1, 0, 0};
    calculatedMatrix[2] = {0, 0, 1, 0};
    calculatedMatrix[3] = {0, 0, 0, 1};

    cubeCoordinates2D.clear();
    rubikVertices2D.clear();
    std::vector<std::array<double, 3>> vertices3D(rubikVertices3D.size());
    newRubikVertices3D = vertices3D;

    calculatedMatrix = getBiggerMatrix(calculatedMatrix, translateMatrix);
    calculatedMatrix = getBiggerMatrix(calculatedMatrix, rotateMatrix);
    calculatedMatrix = getBiggerMatrix(calculatedMatrix, rotateMatrixY);
    calculatedMatrix = getBiggerMatrix(calculatedMatrix, rotateMatrixZ);
    calculatedMatrix = getBiggerMatrix(calculatedMatrix, scaleMatrix);
    calculatedMatrix = getBiggerMatrix(calculatedMatrix, shearingMatrixOX);
    calculatedMatrix = getBiggerMatrix(calculatedMatrix, shearingMatrixOY);

    for (int i = 0; i < cubeCoordinates3D.size(); i++) {

        double pixelX = cubeCoordinates3D[i][0];
        double pixelY = cubeCoordinates3D[i][1];
        double pixelZ = cubeCoordinates3D[i][2];


        resultMatrix[0] = calculatedMatrix[0][0] * pixelX + calculatedMatrix[0][1] * pixelY + calculatedMatrix[0][2] * pixelZ + calculatedMatrix[0][3];
        resultMatrix[1] = calculatedMatrix[1][0] * pixelX + calculatedMatrix[1][1] * pixelY + calculatedMatrix[1][2] * pixelZ + calculatedMatrix[1][3];
        resultMatrix[2] = calculatedMatrix[2][0] * pixelX + calculatedMatrix[2][1] * pixelY + calculatedMatrix[2][2] * pixelZ + calculatedMatrix[2][3];
        resultMatrix[3] = calculatedMatrix[3][0] * pixelX + calculatedMatrix[3][1] * pixelY + calculatedMatrix[3][2] * pixelZ + calculatedMatrix[3][3];


        newCoordinates3D[i][0] = resultMatrix[0];
        newCoordinates3D[i][1] = resultMatrix[1];
        newCoordinates3D[i][2] = resultMatrix[2];

        movePixel(resultMatrix, &cubeCoordinates2D);
    }

    for (int i = 0; i < rubikVertices3D.size(); i++) {

        double pixelX = rubikVertices3D[i][0];
        double pixelY = rubikVertices3D[i][1];
        double pixelZ = rubikVertices3D[i][2];


        resultMatrix[0] = calculatedMatrix[0][0] * pixelX + calculatedMatrix[0][1] * pixelY + calculatedMatrix[0][2] * pixelZ + calculatedMatrix[0][3];
        resultMatrix[1] = calculatedMatrix[1][0] * pixelX + calculatedMatrix[1][1] * pixelY + calculatedMatrix[1][2] * pixelZ + calculatedMatrix[1][3];
        resultMatrix[2] = calculatedMatrix[2][0] * pixelX + calculatedMatrix[2][1] * pixelY + calculatedMatrix[2][2] * pixelZ + calculatedMatrix[2][3];
        resultMatrix[3] = calculatedMatrix[3][0] * pixelX + calculatedMatrix[3][1] * pixelY + calculatedMatrix[3][2] * pixelZ + calculatedMatrix[3][3];


        newRubikVertices3D[i][0] = resultMatrix[0];
        newRubikVertices3D[i][1] = resultMatrix[1];
        newRubikVertices3D[i][2] = resultMatrix[2];

        movePixel(resultMatrix, &rubikVertices2D);
    }
    drawCube();
    update();
}

std::array<std::array<double, 4>, 4> MainWindow::getBiggerMatrix(std::array<std::array<double, 4>, 4> m1, std::array<std::array<double, 4>, 4> calculatedMatrix){
    std::array<std::array<double, 4>, 4> result;

    result[0][0] = m1[0][0] * calculatedMatrix[0][0] + m1[0][1] * calculatedMatrix[1][0] + m1[0][2] * calculatedMatrix[2][0] + m1[0][3] * calculatedMatrix[3][0];
    result[0][1] = m1[0][0] * calculatedMatrix[0][1] + m1[0][1] * calculatedMatrix[1][1] + m1[0][2] * calculatedMatrix[2][1] + m1[0][3] * calculatedMatrix[3][1];
    result[0][2] = m1[0][0] * calculatedMatrix[0][2] + m1[0][1] * calculatedMatrix[1][2] + m1[0][2] * calculatedMatrix[2][2] + m1[0][3] * calculatedMatrix[3][2];
    result[0][3] = m1[0][0] * calculatedMatrix[0][3] + m1[0][1] * calculatedMatrix[1][3] + m1[0][2] * calculatedMatrix[2][3] + m1[0][3] * calculatedMatrix[3][3];


    result[1][0] = m1[1][0] * calculatedMatrix[0][0] + m1[1][1] * calculatedMatrix[1][0] + m1[1][2] * calculatedMatrix[2][0] + m1[1][3] * calculatedMatrix[3][0];
    result[1][1] = m1[1][0] * calculatedMatrix[0][1] + m1[1][1] * calculatedMatrix[1][1] + m1[1][2] * calculatedMatrix[2][1] + m1[1][3] * calculatedMatrix[3][1];
    result[1][2] = m1[1][0] * calculatedMatrix[0][2] + m1[1][1] * calculatedMatrix[1][2] + m1[1][2] * calculatedMatrix[2][2] + m1[1][3] * calculatedMatrix[3][2];
    result[1][3] = m1[1][0] * calculatedMatrix[0][3] + m1[1][1] * calculatedMatrix[1][3] + m1[1][2] * calculatedMatrix[2][3] + m1[1][3] * calculatedMatrix[3][3];

    result[2][0] = m1[2][0] * calculatedMatrix[0][0] + m1[2][1] * calculatedMatrix[1][0] + m1[2][2] * calculatedMatrix[2][0] + m1[2][3] * calculatedMatrix[3][0];
    result[2][1] = m1[2][0] * calculatedMatrix[0][1] + m1[2][1] * calculatedMatrix[1][1] + m1[2][2] * calculatedMatrix[2][1] + m1[2][3] * calculatedMatrix[3][1];
    result[2][2] = m1[2][0] * calculatedMatrix[0][2] + m1[2][1] * calculatedMatrix[1][2] + m1[2][2] * calculatedMatrix[2][2] + m1[2][3] * calculatedMatrix[3][2];
    result[2][3] = m1[2][0] * calculatedMatrix[0][3] + m1[2][1] * calculatedMatrix[1][3] + m1[2][2] * calculatedMatrix[2][3] + m1[2][3] * calculatedMatrix[3][3];

    result[3][0] = m1[3][0] * calculatedMatrix[0][0] + m1[3][1] * calculatedMatrix[1][0] + m1[3][2] * calculatedMatrix[2][0] + m1[3][3] * calculatedMatrix[3][0];
    result[3][1] = m1[3][0] * calculatedMatrix[0][1] + m1[3][1] * calculatedMatrix[1][1] + m1[3][2] * calculatedMatrix[2][1] + m1[3][3] * calculatedMatrix[3][1];
    result[3][2] = m1[3][0] * calculatedMatrix[0][2] + m1[3][1] * calculatedMatrix[1][2] + m1[3][2] * calculatedMatrix[2][2] + m1[3][3] * calculatedMatrix[3][2];
    result[3][3] = m1[3][0] * calculatedMatrix[0][3] + m1[3][1] * calculatedMatrix[1][3] + m1[3][2] * calculatedMatrix[2][3] + m1[3][3] * calculatedMatrix[3][3];

    return result;
}

void MainWindow::movePixel(double m[4], std::vector<std::array<double, 3>>* coords) {
    double x2D = cx + (m[0] * d) / (m[2] + d);
    double y2D = cy + (m[1] * d) / (m[2] + d);

    coords->push_back({x2D, y2D});
}

void MainWindow::drawCube() {
    double cameraX = 0;
    double cameraY = 0;
    double cameraZ = -500;

    double objCenterX = 0;
    double objCenterY = 0;
    double objCenterZ = 0;

    for (const auto &vt : newCoordinates3D) {
        objCenterX += vt[0];
        objCenterY += vt[1];
        objCenterZ += vt[2];
    }

    if (!newCoordinates3D.empty()) {
        objCenterX /= newCoordinates3D.size();
        objCenterY /= newCoordinates3D.size();
        objCenterZ /= newCoordinates3D.size();
    }


    for (int i = 0; i < walls.size(); i++) {
        std::array<double, 3> wallCenter = {
            (newCoordinates3D[walls[i][0]][0] + newCoordinates3D[walls[i][1]][0] +
             newCoordinates3D[walls[i][2]][0] + newCoordinates3D[walls[i][3]][0]) / 4.0,
            (newCoordinates3D[walls[i][0]][1] + newCoordinates3D[walls[i][1]][1] +
             newCoordinates3D[walls[i][2]][1] + newCoordinates3D[walls[i][3]][1]) / 4.0,
            (newCoordinates3D[walls[i][0]][2] + newCoordinates3D[walls[i][1]][2] +
             newCoordinates3D[walls[i][2]][2] + newCoordinates3D[walls[i][3]][2]) / 4.0
        };

        double vxOut = wallCenter[0] - objCenterX;
        double vyOut = wallCenter[1] - objCenterY;
        double vzOut = wallCenter[2] - objCenterZ;

        double vx_cam = cameraX - wallCenter[0];
        double vy_cam = cameraY - wallCenter[1];
        double vz_cam = cameraZ - wallCenter[2];

        double dot = vxOut * vx_cam + vyOut * vy_cam + vzOut * vz_cam;

        if(dot > 1e-3) {
            std::cout << "znaleziono widoczną ściane" << std::endl;
            for (int j = 0; j < 4; ++j) {
                int startIdx = walls[i][j];
                int endIdx = walls[i][(j + 1) % 4];
                QPoint startPoint(cubeCoordinates2D[startIdx][0], cubeCoordinates2D[startIdx][1]);
                QPoint endPoint(cubeCoordinates2D[endIdx][0], cubeCoordinates2D[endIdx][1]);
                drawline->paintLine(startPoint, endPoint, 255, 255, 255);
            }


            if (rubikFaces.find(i) != rubikFaces.end()) {
                std::cout << "wywolano rubik, faces" << std::endl;
                const auto& rubikVerts = rubikFaces[i];

                std::vector<QPoint> points2D;
                for (const auto& vert3D : rubikVerts) {
                    for (size_t idx = 0; idx < rubikVertices3D.size(); ++idx) {
                        if (rubikVertices3D[idx][0] == vert3D[0] &&
                            rubikVertices3D[idx][1] == vert3D[1] &&
                            rubikVertices3D[idx][2] == vert3D[2]) {
                            points2D.push_back(QPoint(rubikVertices2D[idx][0], rubikVertices2D[idx][1]));
                            break;
                        }
                    }
                }

                // Define connections for a grid pattern
                // This will depend on how your vertices are arranged
                // For example, if the vertices are arranged in a specific pattern:
                if (points2D.size() >= 8) {
                    // Example connections (adjust based on your vertex arrangement)
                    // Horizontal lines
                    drawline->paintLine(points2D[0], points2D[2], 0, 0, 0);
                    drawline->paintLine(points2D[1], points2D[3], 0, 0, 0);
                    drawline->paintLine(points2D[4], points2D[5], 0, 0, 0);
                    drawline->paintLine(points2D[6], points2D[7], 0, 0, 0);

                    // Vertical lines
                    drawline->paintLine(points2D[0], points2D[1], 0, 0, 0);
                    drawline->paintLine(points2D[2], points2D[3], 0, 0, 0);
                    drawline->paintLine(points2D[4], points2D[6], 0, 0, 0);
                    drawline->paintLine(points2D[5], points2D[7], 0, 0, 0);
                }
            }

        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

}



