
#include "preference.h"
#include "ui_preference.h"
#include <QSettings>
#include <QDebug>


preference::preference(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::preference)
{
    ui->setupUi(this);

    QSettings settings;
    ui->colorBox->setCurrentIndex(settings.value("Color").toInt());

    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(onAccepted()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(close()));

    radioButtons = new QButtonGroup();
    radioButtons->addButton(ui->radioButton_24);
    radioButtons->addButton(ui->radioButton_12);

}

preference::~preference()
{
    delete ui;
}

void preference::onAccepted()
{
    QSettings settings;
    settings.setValue("Color",ui->colorBox->currentIndex());
    settings.setValue("TimeFormat",radioButtons->checkedButton()->text()); //It will give the format for 24hr or 12hr clock format

}
