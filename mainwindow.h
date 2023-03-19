#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cbx_highbeam_stateChanged(int arg1);

    void on_cbx_lowbeam_stateChanged(int arg1);

    void on_cbx_highbeam_view_stateChanged(int arg1);

    void on_cbx_lowbeam_view_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    bool m_highbeam_view_{false};
    bool m_lowbeam_view_{false};
};

#endif // MAINWINDOW_H
