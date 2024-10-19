#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString operand;
    QString opcode;
    QStack<QString> operands;
    QStack<QString> opcodes;

    QString calculation(bool *ok = NULL);

private slots:
    void btnNumberClicked();

    void btnBinaryOperatorClicked();

    void on_point_clicked();

    void on_del_clicked();

    void btnEqualClicked();

private:
    Ui::MainWindow *ui;

    QLabel *statusMesLabel;
};
#endif // MAINWINDOW_H
