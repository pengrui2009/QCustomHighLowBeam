#include "qcustomhighlowbeam.h"

QCustomHighLowBeam::QCustomHighLowBeam(QWidget *parent) : QWidget(parent)
{
    m_background_color_ = QColor(55,107,154, 30);

    m_active_color_ = Qt::yellow;
    m_unactive_color_ = Qt::gray;

}

QCustomHighLowBeam::~QCustomHighLowBeam()
{

}


void QCustomHighLowBeam::resizeEvent(QResizeEvent *)
{
    this->repaint();
}


QSize QCustomHighLowBeam::sizeHint() const
{
    return QSize(150, 150);
}

QSize QCustomHighLowBeam::minimumSizeHint() const
{
    return QSize(30, 30);
}

void QCustomHighLowBeam::paintEvent(QPaintEvent *)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    //绘制准备工作,启用反锯齿,平移坐标轴中心,等比例缩放
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(width / 2, height / 2);
    painter.scale(side / 200.0, side / 200.0);

    drawBackground(&painter);

    drawHighBeam(&painter);

    drawLowBeam(&painter);

//    drawTitle(&painter);

//    drawTimeCost(&painter);

//    drawSystemTime(&painter);
}

void QCustomHighLowBeam::drawBackground(QPainter *painter)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    painter->save();

    painter->setBrush(m_background_color_);
    painter->drawRect(-width, -height, width * 2, height * 2);

    painter->restore();
}

void QCustomHighLowBeam::drawHighBeam(QPainter *painter)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    QLine lines[] = {
        {-25, -20, -5, -20},
        {-25, -10, -5, -10},
        {-25,   0, -5,   0},
        {-25,  10, -5,  10},
        {-25,  20, -5,  20},
        {-25,  20, -5,  20},
        {  2, -30,  2,  30}
    };


    painter->save();

    if (m_highbeam_active_)
    {
        painter->setPen(QPen(m_active_color_, 4));
    } else {
        painter->setPen(QPen(m_unactive_color_, 4));
    }

    painter->drawLines(lines,  (sizeof(lines)/sizeof (lines[0])));

    QRectF rectangle(-50.0, -30.0, 105.0, 60.0);
    int startAngle = 90 * 16;
    int spanAngle = -180 * 16;
    painter->drawArc(rectangle, startAngle, spanAngle);

    painter->restore();
}

void QCustomHighLowBeam::drawLowBeam(QPainter *painter)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    int offset = 100;

    QLine lines[] = {
        {-25+offset, -15, -5+offset, -25},
        {-25+offset,  -5, -5+offset, -15},
        {-25+offset,   5, -5+offset,  -5},
        {-25+offset,  15, -5+offset,   5},
        {-25+offset,  25, -5+offset,  15},
        {-25+offset,  35, -5+offset,  25},
        {  2+offset, -30,  2+offset,  30}
    };

    painter->save();


    if (m_lowbeam_active_)
    {
        painter->setPen(QPen(m_active_color_, 4));
    } else {
        painter->setPen(QPen(m_unactive_color_, 4));
    }

    painter->drawLines(lines,  (sizeof(lines)/sizeof (lines[0])));

    QRectF rectangle(-50.0+offset, -30.0, 105.0, 60.0);
    int startAngle = 90 * 16;
    int spanAngle = -180 * 16;
    painter->drawArc(rectangle, startAngle, spanAngle);

    painter->restore();
}

void QCustomHighLowBeam::setHighBeamState(bool value)
{
    if (this->m_highbeam_active_ != value)
    {
        this->m_highbeam_active_ = value;
        this->update();
    }
}

void QCustomHighLowBeam::setLowBeamState(bool value)
{
    if (this->m_lowbeam_active_ != value)
    {
        this->m_lowbeam_active_ = value;
        this->update();
    }
}
