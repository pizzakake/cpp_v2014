#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
     void updateTextCount();

signals:
     void textCountChanged(int i);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
     void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    //Maximum number of characters in the textBrowser
    const int maxCount=160;
};

#endif // MAINWINDOW_H
