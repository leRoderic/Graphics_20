#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QDialog>

namespace Ui {
class DataDialog;
}

class DataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DataDialog(QWidget *parent = nullptr);
    ~DataDialog();

private slots:
    void on_browseDataBtn_pressed();

    void on_browseCMBtn_2_pressed();

    void on_doItBt_pressed();

    void on_browseObjBtn_4_pressed();

    void on_btLoad_pressed();

signals:
    void dialogFinished (QString data, QString obj, QString colormap,
                         float xmin, float xmax, float ymin, float ymax,
                         float zmin, float zmax);
private:
    Ui::DataDialog *ui;
};

#endif // DATADIALOG_H
