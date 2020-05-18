
#include "DataDialog.h"
#include "ui_dataDialog.h"


DataDialog::DataDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataDialog)
{

    ui->setupUi(this);

    // Codi necessari per adaptar el projecte a la versio 330 de gl
    QGLFormat glfModern=QGLFormat::defaultFormat();
    glfModern.setVersion(3,3);
    glfModern.setProfile(QGLFormat::CoreProfile);
    glfModern.setSampleBuffers(true);
    glfModern.setSwapInterval(0);
    glfModern.setDefaultFormat(glfModern);
    glWidget = new GLWidget(glfModern);
}

DataDialog::~DataDialog()
{
    delete ui;
}


