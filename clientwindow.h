#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>

namespace Ui {
class clientwindow;
}

class clientwindow : public QDialog
{
    Q_OBJECT

public:
    explicit clientwindow(QWidget *parent = nullptr);
    ~clientwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

public:

    void SetAll();

private:
    Ui::clientwindow *ui;
};

#endif // CLIENTWINDOW_H
