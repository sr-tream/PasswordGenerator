#ifndef GENPASS_H
#define GENPASS_H

#include "ui_genpass.h"
#include <QSettings>

class GenPass : public QWidget, private Ui::GenPass
{
    Q_OBJECT

public:
    explicit GenPass(QWidget *parent = 0);

protected:
    char randomSymbol();

private slots:
    void on_generatePassword_clicked();

    void on_upperCase_toggled(bool checked);

    void on_numbers_toggled(bool checked);

    void on_puncts_toggled(bool checked);

    void on_length_valueChanged(int arg1);

private:
    QSettings *sets;
};

#endif // GENPASS_H
