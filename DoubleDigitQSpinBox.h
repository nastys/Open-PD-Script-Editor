#ifndef DOUBLEDIGITQSPINBOX_H
#define DOUBLEDIGITQSPINBOX_H

#include <QSpinBox>

class DoubleDigitQSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit DoubleDigitQSpinBox(QWidget* parent) : QSpinBox(parent) {}
protected:
    QString textFromValue(int value) const override
    {
        QString text = QString::number(value);
        if(text.length()<2) text.prepend('0');

        return text;
    }
};

#endif // DOUBLEDIGITQSPINBOX_H
