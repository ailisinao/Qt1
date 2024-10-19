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
    connect(ui->equal ,SIGNAL(clicked()) ,this ,SLOT(btnEqualClicked()));

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
    QString op = qobject_cast<QPushButton*>(sender())->text();
    opcodes.push(op);
    ui->lineEdit->clear();

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

void MainWindow::btnEqualClicked()
{
    QString oriStr = ui->lineEdit->text();
    operands.push(oriStr);
    QString result = calculation();
    ui->lineEdit->setText(result);
    // 检查计算结果是否为0
    if (result == "0") {
        // 打印调试信息
        qDebug() << "警告：计算结果为0";
        qDebug() << "操作数1: " << operands.size() > 1 ? operands[operands.size() - 2] : "未知";
        qDebug() << "操作数2: " << operands.size() > 0 ? operands.top() : "未知";
        qDebug() << "操作符: " << opcodes.size() > 0 ? opcodes.top() : "未知";
        
        // 检查除数是否为0
        if (opcodes.size() > 0 && opcodes.top() == "/" && operands.size() > 0 && operands.top() == "0") {
            ui->lineEdit->setText("错误：除数不能为0");
        }
    }
    
    // 清空操作数和操作符栈
    operands.clear();
    opcodes.clear();
    qDebug() << "计算结果: " << result;
    qDebug() << "操作数栈: " << operands;
    qDebug() << "操作符栈: " << opcodes;
}   

