#ifndef RESPONSIVE_LABEL_H
#define RESPONSIVE_LABEL_H

#include <QLabel>

class responsive_label : public QLabel
{
    Q_OBJECT
public:
    explicit responsive_label(QWidget *parent = 0);

signals:

public slots:
    void updateTextCount(int i);
};

#endif // RESPONSIVE_LABEL_H
