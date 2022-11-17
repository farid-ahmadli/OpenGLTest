#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionSave_Plot_Image_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Plot as Image"),
                                                    "", tr("Image formats (*.jpg *.png *.bmp)"));

    if ( !fileName.isEmpty() ) {
        ui->widget->savePlotImage( fileName );
    }

}
