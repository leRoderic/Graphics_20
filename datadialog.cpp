#include "datadialog.h"
#include "ui_datadialog.h"

#include <QFileDialog>
#include <QStandardPaths>

DataDialog::DataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataDialog)
{
    ui->setupUi(this);
}

DataDialog::~DataDialog()
{
    delete ui;
}

void DataDialog::on_browseDataBtn_pressed()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open data file",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.txt");
    ui->dataFileEdit->setText(file);
    //on_dataFileEdit_returnPressed();
}

void DataDialog::on_browseCMBtn_2_pressed()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open color map file",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.gpl");
    ui->cmFileEdit->setText(file);
    //on_cmFileEdit_2_returnPressed();
}

void DataDialog::on_doItBt_pressed()
{
    emit dialogFinished(ui->dataFileEdit->text(), ui->objFileEdit_4->text(), ui->cmFileEdit->text(),
                        ui->minXSpin_2->value(), ui->minYSpin_2->value(), ui->minZSpin_2->value(),
                        ui->maxXSpin_3->value(), ui->maxYSpin_3->value(), ui->maxZSpin_3->value());
    this->close();
}

void DataDialog::on_browseObjBtn_4_pressed()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open color map file",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");
    ui->objFileEdit_4->setText(file);
    //on_cmFileEdit_2_returnPressed();
}
