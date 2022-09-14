#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <algorithm>
#include <QTableWidgetItem>
#include <cstdlib>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMessageBox>
#include <QApplication>
#include <QElapsedTimer>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QColor>
#include <QString>
#include <cstring>
#include<QModelIndex>
#include "source/Job.h"
#include "source/Scheduler.h"
#include "source/StatisticsManager.h"

using namespace std;
const int Rectangle_Width = 10;
const int Rectangle_Height = 100;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-60, 0, 200, 100);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() //테이블에 프로세스 아이디 정보 입력
{
    QString str_pid = ui->lineEdit_2->text();
    //int pid=str_pid.toInt(); QString을 int형으로 변환
    QString str_arrival = ui->lineEdit_3->text();
    QString str_service = ui->lineEdit_4->text();
    QString str_priority = ui->lineEdit_5->text();

    //테이블에 입력한 프로세스 정보 출력
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(str_pid));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(str_arrival));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(str_service));
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem(str_priority));

    //입력란 공백으로
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}

void MainWindow::on_pushButton_2_clicked() //스케줄링에 대한 모든 정보 입력 후, 본격적인 스케줄링 함수로 가기 위한 버튼
{
    scene->clear();
    int quantum = ui->lineEdit->text().toInt(); //quantum. default값은 0

    vector<Job> job_vector;
    auto job_table = ui->tableWidget;
    for (int i = 0; i < job_table->rowCount(); i++) {
        int pid = job_table->item(i, 0)->text().toInt();
        int atime = job_table->item(i, 1)->text().toInt();
        int stime = job_table->item(i, 2)->text().toInt();
        int prior = job_table->item(i, 3)->text().toInt();
        job_vector.emplace_back(pid, atime, stime, prior);
    }

    //########백엔드 - 스케줄링 함수에 algo, vector(, quantum) 전송 & 본격적인 스케줄링

    Scheduler scheduler;
    vector<Unit> scheduling_result;

    if (ui->radioButton->isChecked())
        scheduling_result = scheduler.FirstComeFirstServe(job_vector);
    else if (ui->radioButton_2->isChecked())
        scheduling_result = scheduler.ShortestJobFirst(job_vector);
    else if (ui->radioButton_3->isChecked())
        scheduling_result = scheduler.ShortestRemainingTimeFirst(job_vector);
    else if (ui->radioButton_4->isChecked()) {
        if (!quantum) {
            QMessageBox msgBox;
            msgBox.setText("Quantum이 0입니다.");
            msgBox.exec();
            return;
        }
        scheduling_result = scheduler.RoundRobin(job_vector, quantum);
    }
    else if (ui->radioButton_5->isChecked())
        scheduling_result = scheduler.PreemptivePrior(job_vector);
    else if (ui->radioButton_6->isChecked())
        scheduling_result = scheduler.NonpreemptivePrior(job_vector);
    else if (ui->radioButton_7->isChecked()) {
        if (!quantum) {
            QMessageBox msgBox;
            msgBox.setText("Quantum이 0입니다.");
            msgBox.exec();
            return;
        }
        scheduling_result = scheduler.NonpreemptivePriorRR(job_vector, quantum);
    }
    else
        return;

    // 여기 output에다가 스케줄링 결과를 전달받아야 합니다.
    std::vector<Unit> output = scheduling_result;

    //########백엔드 - 프로세스 개수만큼 앞서 계산한 프로세스 별 시간 정보 출력
    StatisticsManager sm;
    vector<Unit> res_rt = sm.calculateReturnTime(output, job_vector);
    vector<Unit> res_wt = sm.calculateWaitingTime(output, job_vector);
    vector<Unit> res_rs = sm.calculateResponseTime(output, job_vector);
    std::sort(res_rt.begin(), res_rt.end());
    std::sort(res_wt.begin(), res_wt.end());
    std::sort(res_rs.begin(), res_rs.end());

    double avg_rt = sm.getAverageReturnTime(res_rt);
    double avg_wt = sm.getAverageReturnTime(res_wt);
    double avg_rs = sm.getAverageReturnTime(res_rs);

    int proc = ui->tableWidget->rowCount();
    ui->tableWidget_2->setRowCount(proc);
    ui->tableWidget_2->setColumnCount(4);
    for (int i = 0; i < proc; i++) {
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(to_string(res_rt[i].first))));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(to_string(res_rt[i].second))));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(to_string(res_wt[i].second))));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(to_string(res_rs[i].second))));
    }

    QString str_rt = QString::fromStdString(to_string(avg_rt));
    QString str_wt = QString::fromStdString(to_string(avg_wt));
    QString str_rs = QString::fromStdString(to_string(avg_rs));

    //########백엔드 - 평균값 출력
    //append(string) or setPlainText(string)average_waiting_timeaverage_return_timeaverage_response_time
    ui->textBrowser->setPlainText(str_rt); //######백엔드 - str형식의 입력값 필요
    ui->textBrowser_2->setPlainText(str_wt); //#######백엔드 - str 형식의 입력값 필요
    ui->textBrowser_3->setPlainText(str_rs); //######백엔드 - str 형식의 입력값 필요

    //    ui->tableWidget_2->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(str_rt)); //입력 인자는 string 형식으로
    //    ui->tableWidget_2->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(str_wt)); //입력 인자는 string 형식으로
    //    ui->tableWidget_2->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(str_rs)); //입력 인자는 string 형식으로

        // 간트 차트 출력 (프론트 엔드)
        // 색상 지정을 위한 RGB queue
    std::vector<int> R_queue = { 255, 240, 100, 255, 220, 255, 230, 255, 173, 240, 250 };
    std::vector<int> G_queue = { 255, 248, 149, 248, 20, 215, 230, 240, 216, 128, 250 };
    std::vector<int> B_queue = { 255, 255, 237, 220, 60, 0, 250, 245, 230, 128, 210 };

    int line = -460;
    int midline = -460;
    int time_sum = 0;
    QString p = "p";

    QBrush color_brush(QColor(R_queue[output[0].first], G_queue[output[0].first], B_queue[output[0].first]));
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);
    QElapsedTimer t;
    t.start();

    QGraphicsRectItem *rectangle = new QGraphicsRectItem();
    rectangle = scene->addRect(line, 0, Rectangle_Width * output[0].second, Rectangle_Height, blackpen, color_brush);
    QGraphicsTextItem *txtitem = new QGraphicsTextItem("0");
    txtitem->setPos(QPointF(line - 8, 100));
    scene->addItem(txtitem);
    QString p_num;
    if (output[0].first != 0){
         auto str = QString::number(output[0].first);
         p_num = p + str;
    }
    else {
         p_num = "empty";
    }
    QGraphicsTextItem *txtitem_mid = new QGraphicsTextItem(p_num);
    txtitem_mid->setPos(QPointF(line + Rectangle_Width * output[0].second / 2 - 13, 40));
    scene->addItem(txtitem_mid);


    while (t.elapsed() < 500) {
        QCoreApplication::processEvents();
    }

    for (int i = 1; i < output.size(); i++) {
        QBrush color_brush(QColor(R_queue[(output[i].first) % 11], G_queue[(output[i].first) % 11], B_queue[(output[i].first) % 11]));
        QPen blackpen(Qt::black);
        blackpen.setWidth(1);
        time_sum += output[i - 1].second;
        line += Rectangle_Width * output[i - 1].second;
        rectangle = scene->addRect(line, 0, Rectangle_Width * output[i].second, Rectangle_Height, blackpen, color_brush);
        QString temp_str = QString::number(time_sum);
        QGraphicsTextItem *txtitem = new QGraphicsTextItem(temp_str);
        txtitem->setPos(QPointF(line - 8, 100));
        scene->addItem(txtitem);
        QString p_num;
        if (output[i].first != 0) {
            auto str = QString::number(output[i].first);
            p_num = p + str;
        }
        else {
            p_num = "empty";
        }
        QGraphicsTextItem *txtitem_mid = new QGraphicsTextItem(p_num);
        txtitem_mid->setPos(QPointF(line + Rectangle_Width * output[i].second / 2 - 13, 40));
        scene->addItem(txtitem_mid);
        QElapsedTimer t;
        t.start();
        while (t.elapsed() < 500) {
            QCoreApplication::processEvents();
        }
    }

    time_sum += output[output.size() - 1].second;
    line += Rectangle_Width * output[output.size() - 1].second;
    QString temp_str_end = QString::number(time_sum);
    QGraphicsTextItem *txtitem_end = new QGraphicsTextItem(temp_str_end);
    txtitem_end->setPos(QPointF(line - 5, 100));
    scene->addItem(txtitem_end);
}

void MainWindow::on_pushButton_3_clicked() {
    //ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);

    // ui->tableWidget_2->clear();
    ui->tableWidget_2->setRowCount(0);

    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_3->clear();
    ui->lineEdit->setText("0");
    scene->clear();
}

void MainWindow::on_pushButton_5_clicked() {
    QModelIndexList indexes = ui->tableWidget->selectionModel()->selectedRows();

    int n = indexes.count();
    for (int i = n - 1; i >= 0; i--) {
        ui->tableWidget->removeRow(indexes.at(i).row());
    }
}
