#include "dialog.h"
#include "ui_dialog.h"

// location of center
#define X_CENTER (300)
#define Y_CENTER (300)

// scaling constant for rendering bodies on screen
#define SCALE (250 / AU)

// width and height of dialog box
#define DIALOG_WIDTH (600)
#define DIALOG_HEIGHT (600)

// timestep of the simulation
#define TIMESTEP 50000

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_sun(1.98892e30, 0.0, 0.0, 0.0, 0.0),
    m_earth(5.9742e24, -1 * AU, 0.0, 0.0, 2.9783e4),
    m_venus(4.8685e24, 0.723 * AU, 0.0, 0.0, -3.502e4)
{
    ui->setupUi(this);
    this->update();
    this->resize(DIALOG_WIDTH, DIALOG_HEIGHT);
    this->setStyleSheet("background-color: #82CAFF;");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(16);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // set pen
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::black);
    painter.setPen (pen);

    // paint sun
    QBrush sun_brush(Qt::yellow);
    painter.setBrush(sun_brush);
    painter.drawEllipse(X_CENTER-m_sun.getXPosition() * SCALE , Y_CENTER-m_sun.getYPosition() * SCALE, 100, 100);

    // paint earth
    QBrush earth_brush(Qt::blue);
    painter.setBrush(earth_brush);
    painter.drawEllipse(X_CENTER-m_earth.getXPosition() * SCALE, Y_CENTER-m_earth.getYPosition() * SCALE, 10, 10);

    // paint earth
    QBrush venus_brush(Qt::red);
    painter.setBrush(venus_brush);
    painter.drawEllipse(X_CENTER-m_venus.getXPosition() * SCALE, Y_CENTER-m_venus.getYPosition() * SCALE, 9, 9);
}

void Dialog::nextFrame()
{
    // calculate force exerted on sun by earth & venus
    double xTotalForceSun = 0.0,
           yTotalForceSun = 0.0;
    m_sun.addAttraction(m_earth, xTotalForceSun, yTotalForceSun);
    m_sun.addAttraction(m_venus, xTotalForceSun, yTotalForceSun);

    // calculate force exerted on earth by sun & venus
    double xTotalForceEarth = 0.0,
           yTotalForceEarth = 0.0;
    m_earth.addAttraction(m_sun, xTotalForceEarth, yTotalForceEarth);
    m_earth.addAttraction(m_venus, xTotalForceEarth, yTotalForceEarth);

    // calculate force exerted on venus by sun & earth
    double xTotalForceVenus = 0.0,
           yTotalForceVenus = 0.0;
    m_venus.addAttraction(m_sun, xTotalForceVenus, yTotalForceVenus);
    m_venus.addAttraction(m_earth, xTotalForceVenus, yTotalForceVenus);

    // update acceleration vector of all objects
    m_sun.update(xTotalForceSun, yTotalForceSun, TIMESTEP);
    m_earth.update(xTotalForceEarth, yTotalForceEarth, TIMESTEP);
    m_venus.update(xTotalForceVenus, yTotalForceVenus, TIMESTEP);

    update();
}
