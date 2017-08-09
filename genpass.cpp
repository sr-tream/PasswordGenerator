#include "genpass.h"
#include <ctime>
#include <QDebug>

GenPass::GenPass(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    srand(time(NULL));
    sets = new QSettings("Prime-Hack", "PasswordGenerator", this);

    upperCase->setChecked(sets->value("upperCase", true).toBool());
    numbers->setChecked(sets->value("numbers", true).toBool());
    puncts->setChecked(sets->value("puncts", false).toBool());
    length->setValue(sets->value("length", 8).toInt());

    on_generatePassword_clicked();
}

char puncts_mas[] = {
    ',',
    '.',
    '/',
    ';',
    '\'',
    '[',
    ']',
    '\\',
    '<',
    '>',
    '?',
    ':',
    '\"',
    '{',
    '}',
    '|',
    '!',
    '@',
    '#',
    '$',
    '%',
    '^',
    '&',
    '*',
    '(',
    ')',
    '-',
    '=',
    '_',
    '+'
};

char GenPass::randomSymbol()
{
    while (true){
        int  r = rand() % 4;
        if (r == 1 && upperCase->isChecked())
            return char(rand() % ('Z' - 'A') + 'A');
        else if (r == 2 && numbers->isChecked())
            return char(rand() % ('9' - '0') + '0');
        else if (r == 3 && puncts->isChecked())
            return char(puncts_mas[rand() % 30]);
        else return char(rand() % ('z' - 'a') + 'a');
    }
}

void GenPass::on_generatePassword_clicked()
{
    QString password = "";
    for (int i = 0; i < length->value(); ++i){
        password += randomSymbol();
    }
    output->setText(password);
}

void GenPass::on_upperCase_toggled(bool checked)
{
    on_generatePassword_clicked();
    sets->setValue("upperCase", checked);
}

void GenPass::on_numbers_toggled(bool checked)
{
    on_generatePassword_clicked();
    sets->setValue("numbers", checked);
}

void GenPass::on_puncts_toggled(bool checked)
{
    on_generatePassword_clicked();
    sets->setValue("puncts", checked);
}

void GenPass::on_length_valueChanged(int arg1)
{
    on_generatePassword_clicked();
    sets->setValue("length", arg1);
}
