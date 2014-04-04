#include "responsive_label.h"

responsive_label::responsive_label(QWidget *parent) : QLabel(parent)
{
}

void responsive_label::updateTextCount(int i){
   this->setText(QString(i));
}
