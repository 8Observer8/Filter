#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_selectFolderButton_clicked();

    void on_filterButton_clicked();

private:
    Ui::Dialog *ui;
    QStringList allFiles;
};

#endif // DIALOG_H
