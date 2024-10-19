#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->num0 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));
    connect(ui->num1 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));
    connect(ui->num2 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));
    connect(ui->num3 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));
    connect(ui->num4 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));
    connect(ui->num5 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));
    connect(ui->num6 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));
    connect(ui->num7 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));
    connect(ui->num8 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));
    connect(ui->num9 ,SIGNAL(clicked()) ,this ,SLOT(btnNumberClicked()));

    connect(ui->plus ,SIGNAL(clicked()) ,this ,SLOT(btnBinaryOperatorClicked()));
    connect(ui->minus ,SIGNAL(clicked()) ,this ,SLOT(btnBinaryOperatorClicked()));
    connect(ui->multiple ,SIGNAL(clicked()) ,this ,SLOT(btnBinaryOperatorClicked()));
    connect(ui->divide ,SIGNAL(clicked()) ,this ,SLOT(btnBinaryOperatorClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    if(operands.size() == 2 && opcodes.size() > 0){
        //取操作数
        double operand1 = operands.front().toDouble();
        operands.pop_front();
        double operand2 = operands.front().toDouble();
        operands.pop_front();

        //取操作符
        QString op = opcodes.front();
        opcodes.pop_front();

        if(op == "+"){
            result = operand1 + operand2;
        }else if(op == "-"){
            result = operand1 - operand2;
        }else if(op == "*"){
            result = operand1 * operand2;
        }else if(op == "/"){
            result = operand1 / operand2;
        }
    }
    return QString::number(result);
}

void MainWindow::btnNumberClicked()
{
    QString oriStr = ui->lineEdit->text();
    QString str = qobject_cast<QPushButton*>(sender())->text();
    ui->lineEdit->setText(oriStr + str);
}

void MainWindow::btnBinaryOperatorClicked()
{
    QString oriStr = ui->lineEdit->text();
    operands.push(oriStr);
    

}


void MainWindow::on_point_clicked()
{
    QString oriStr = ui->lineEdit->text();
    QString str = qobject_cast<QPushButton*>(sender())->text();
    if(!oriStr.contains("."))
        ui->lineEdit->setText(oriStr + str);
}


void MainWindow::on_del_clicked()
{
    QString oriStr = ui->lineEdit->text();
    if(!oriStr.isEmpty())
        ui->lineEdit->setText(oriStr.left(oriStr.length() - 1));
}

