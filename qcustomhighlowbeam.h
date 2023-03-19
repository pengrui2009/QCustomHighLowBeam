#ifndef QCUSTOMHIGHLOWBEAM_H
#define QCUSTOMHIGHLOWBEAM_H

#include <QWidget>
#include <QPainter>

/**
 * @brief Feature:
 * Support
 * Support
 * Support
 * Support
 */

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT QCustomMobileSignal : public QWidget
#else
class QCustomHighLowBeam : public QWidget
#endif
{
    Q_OBJECT
//    Q_PROPERTY()
public:
    explicit QCustomHighLowBeam(QWidget *parent = nullptr);
    ~QCustomHighLowBeam();

protected:
    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

    void drawBackground(QPainter *painter);
    void drawHighBeam(QPainter *painter);
    void drawLowBeam(QPainter *painter);
private:
    QColor m_active_color_;
    QColor m_unactive_color_;
    // false:unactive true:active
    bool m_highbeam_active_{false};
    bool m_lowbeam_active_{false};
    QColor m_background_color_;
signals:

public slots:
    void setHighBeamState(bool value);
    void setLowBeamState(bool value);
};

#endif // QCUSTOMHIGHLOWBEAM_H
