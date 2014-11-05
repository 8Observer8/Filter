#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_selectFolderButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory( this, tr("Open Directory"),
                                                     QDir::currentPath(),
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if ( dir.isEmpty() ) {
        return;
    }

    ui->selectFolderLineEdit->setText( dir );

    QDir recoredDir( dir );

    allFiles = recoredDir.entryList( QDir::NoDotAndDotDot | QDir::Files );

    for ( int i = 0; i < allFiles.size(); ++i ) {
        ui->filterTextEdit->append( allFiles[i] );
    }
}

void Dialog::on_filterButton_clicked()
{
    ui->filterTextEdit->clear();

    QString filter1 = ui->filter1LineEdit->text();
    QString filter2 = ui->filter2LineEdit->text();
    QString filter3 = ui->filter3LineEdit->text();
    QString filter4 = ui->filter4LineEdit->text();
    QString filter5 = ui->filter5LineEdit->text();

    QStringList newList = allFiles;

    if( !filter1.isEmpty() ) {
        newList = newList.filter( filter1 );
    }

    if( !filter2.isEmpty() ) {
        newList = newList.filter( filter2 );
    }

    if( !filter3.isEmpty() ) {
        newList = newList.filter( filter3 );
    }

    if( !filter4.isEmpty() ) {
        newList = newList.filter( filter4 );
    }

    if( !filter5.isEmpty() ) {
        newList = newList.filter( filter5 );
    }

    for ( int i = 0; i < newList.size(); ++i ) {
        ui->filterTextEdit->append( newList[i] );
    }
}
