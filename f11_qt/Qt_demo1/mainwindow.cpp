#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->textBrowser,SIGNAL(textChanged()),SLOT(updateTextCount()));

    //This could have been done through the property inspector in the GUI
    ui->progressBar->setMaximum(maxCount);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//This is the "slot" to which we connect our "signal"
//That means that this function will be called, whenever the connected signal fires (is emitted)
void MainWindow::updateTextCount(){
    //Get the number of characters in the text box
    int size=ui->textBrowser->toPlainText().size();

    //Make a QString out of it
    QString s="Count: "+QString::number(size);

    //Print it to terminal, just for fun
    std::cout<< s.toStdString() << " qstr: " << QString(size).toStdString() << std::endl;

    if(size>=maxCount)
        ui->textBrowser->setTextColor("red");
    else
        ui->textBrowser->setTextColor("black");

    //Put it into the label (it takes QString as argument)
    ui->label->setText(s);

    //Instead of putting it directly into the label, you could emit a signal, with the character-count
    emit textCountChanged(size);

    //Now your label - and anybody else - could be notified
    //with the new character count whenever it changed. That would be done by giving them a slot
    //with an int as parameter, and then connect that slot to the signal we just emitted.
    //This way we don't have to do anything more in this function; if some other elements needs to be
    //updated as well, based on character count, we can just connect them to the signal too,
    //and then let their slot do the additional work.

    //PS:
    // A progress bar has been added and subscribes to this signal.
    // The connection was done in the GUI-editor, by "draggning" a signal from mainWindow to progressBar

}

void MainWindow::on_pushButton_clicked()
{
    std::cout << "Saving text: " << std::endl << ui->textBrowser->toPlainText().toStdString() << std::endl;
}
