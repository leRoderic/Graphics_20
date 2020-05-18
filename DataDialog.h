#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QtWidgets>
#include "GLWidget.h"
#include "Builder.h"


QT_BEGIN_NAMESPACE
class QSlider;
class GLWidget;
QT_END_NAMESPACE

namespace Ui {
   class DataDialog;
}

class DataDialog : public QMainWindow
{
    Q_OBJECT
public:
    explicit DataDialog(QWidget *parent = 0);
    ~DataDialog();
    bool changes; // Variable de control d
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::DataDialog *ui;
    Builder        *builder;
    GLWidget       *glWidget;
    // TO DO Fase 1: Afegir els diàlegs o finestres per obrir les escenes VIRTUALS i les de DATA
    // des dels menús Obre Escena i Obre Dades

private slots:

};

#endif // DATADIALOG_H
