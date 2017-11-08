#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include "dialog.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(647,420);
    setWindowTitle("排哨表生成系统");
    for(int i=0;i<800;i++) holiday[i]=0;
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->StartTime->setMinimumDate(QDate::currentDate());
    ui->EndTime->setMinimumDate(QDate::currentDate());
    QString s=QString("%1").arg(QDate::currentDate().year()+1)+"-12-31";
    QString ss=QString("%1").arg(QDate::currentDate().year())+"-12-31";
    ui->StartTime->setMaximumDate(QDate::fromString(ss,"yyyy-MM-dd"));
    ui->EndTime->setMaximumDate(QDate::fromString(s,"yyyy-MM-dd"));
    createConnection();
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->widget->setVisible(false);

    QSqlQuery sql;
    sql.exec("select * from Time");
    QString tempT;
    QDate ST=ui->StartTime->date();
    int x=ST.year();
    while(sql.next()){
        tempT=sql.value(0).toString();
        int rowindex=ui->tableWidget->rowCount();

        ui->tableWidget->setRowCount(rowindex+1);
        QTableWidgetItem *item=new QTableWidgetItem(tempT);
        ui->tableWidget->setItem(rowindex,0,item);
        QDate d=QDate::fromString(tempT,"yyyy-MM-dd ddd");
        if(d.year()>x)
          holiday[d.dayOfYear()+ST.daysInYear()]=1;
        else
          holiday[d.dayOfYear()]=1;
    }


    QHeaderView *h=ui->tableWidget->verticalHeader();
    h->setHidden(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generate(){


       QString path=ui->lineEdit->text();
       if(path=="请选择值哨名单")
       {
           QMessageBox::warning(this,tr("错误"),tr("未选择值哨名单"));
           return;
       }
       name=new QString[2000];
       int iterator=0;

       HRESULT r=OleInitialize(0);

       QAxObject excel("Excel.Application");
       excel.setProperty("Visible",false);
       QAxObject *work_books = excel.querySubObject("WorkBooks");
       work_books->dynamicCall("Open (const QString&)",path);

       QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
       QAxObject *work_sheets = work_book->querySubObject("Sheets"); //Sheets也可换用WorkSheets

       int sheet_count = work_sheets->property("Count").toInt(); //获取工作表数目
       QAxObject *work_sheet;
       if(sheet_count>1){
           QAxObject *temp_sheet;
           for(int i=2;i<=sheet_count;i++){
              temp_sheet = work_sheets->querySubObject("Item(int)",i);
              temp_sheet->dynamicCall("delete");
           }
       }
       else if(sheet_count==0){
           QMessageBox::warning(this,tr("错误"),tr("值哨名单有误，请重试"));
           return;
       }


       QAxObject *last_sheet = work_sheets->querySubObject("Item(int)",1);
       work_sheet = work_sheets->querySubObject("Add(QVariant)", last_sheet->asVariant());
       last_sheet->dynamicCall("Move(QVariant)", work_sheet->asVariant());


       if(sheet_count > 0)
           {
           work_sheet = work_book->querySubObject("Sheets(int)",1);
           QAxObject *used_range = work_sheet->querySubObject("UsedRange");
           QAxObject *rows = used_range->querySubObject("Rows");
           QAxObject *columns = used_range->querySubObject("Columns");
           int row_start = used_range->property("Row").toInt(); //获取起始行
           int column_start = used_range->property("Column").toInt(); //获取起始列
           int row_count = rows->property("Count").toInt(); //获取行数
           int column_count = columns->property("Count").toInt(); //获取列数

           qDebug()<<row_count<<"++"<<column_count;

           for(int i=row_start;i<=row_count ;i++)
           {
             for(int j=column_start; j<=column_count;j++)
              {
               cell= work_sheet->querySubObject("Cells(int,int)",i,j);
               QString cell_value = cell->property("Value").toString(); //获取单元格内容
               qDebug()<<cell_value;
               if(cell_value!="")
                  name[iterator++]=cell_value;
             }
           }
          }
       if(iterator==0)
       {
           QMessageBox::warning(this,"错误","值哨名单为空请重试");
           return;
       }

       int paiban[7][12]={{2,2,2,1,0,0,1,0,1,1,1,2},
                          {2,2,2,1,0,0,1,0,1,1,1,2},
                          {2,2,2,1,0,0,1,0,1,1,1,2},
                          {2,2,2,1,0,0,1,0,1,1,1,2},
                          {2,2,2,1,0,0,1,1,1,1,1,2},
                          {2,2,2,1,0,0,1,1,1,1,1,2},
                          {2,2,2,1,1,1,1,1,1,1,1,2}};

       int x=ui->StartTime->date().year();
       int y=ui->EndTime->date().year();
       QDate ST=ui->StartTime->date();
       int Startday=ST.dayOfYear();
       QDate iteTime=ST;
       int Endday=ui->EndTime->date().dayOfYear();

       if(y>x) Endday+=ST.daysInYear();
       int CurWeekDay=ui->StartTime->date().dayOfWeek()-1;
       int personiterator=0;
       int linecount=2;
       int personnum;




       work_sheet= work_book->querySubObject("Sheets(int)",2);

       qDebug()<<Startday<<"--"<<Endday;
       for(int i=Startday;i<=Endday;i++)
       {

           QString cellvalue="";
           cell=work_sheet->querySubObject("Cells(int,int)",linecount,1);
           cell->setProperty("Value",iteTime.toString("yyyy-MM-dd ddd"));
           iteTime=iteTime.addDays(1);
           int temp;
           if(holiday[i]==1)
           {
               temp=CurWeekDay;
               CurWeekDay=6;
               cell=work_sheet->querySubObject("Cells(int,int)",linecount,14);
               cell->setProperty("Value","节假日");
           }
           for(int k=0;k<12;k++)
           {
              cellvalue="";
              personnum=paiban[CurWeekDay][k];
              for(int j=0;j<personnum;j++)
              {
                 cellvalue=cellvalue+name[personiterator]+"  ";
                 personiterator=(personiterator+1)%iterator;
              }
              cell=work_sheet->querySubObject("Cells(int,int)",linecount,k+2);
              cell->setProperty("Value",cellvalue);
           }
           linecount++;
           if(holiday[i]==1)
              CurWeekDay=(temp+1)%7;
           else
              CurWeekDay=(CurWeekDay+1)%7;
       }

           cell = work_sheet->querySubObject("Cells(int,int)",1,2);
           cell->setProperty("Value", "0:00-2:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,3);
           cell->setProperty("Value", "2:00-4:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,4);
           cell->setProperty("Value", "4:00-6:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,5);
           cell->setProperty("Value", "6:00-8:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,6);
           cell->setProperty("Value", "8:00-10:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,7);
           cell->setProperty("Value", "10:00-12:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,8);
           cell->setProperty("Value", "12:00-14:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,9);
           cell->setProperty("Value", "14:00-16:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,10);
           cell->setProperty("Value", "16:00-18:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,11);
           cell->setProperty("Value", "18:00-20:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,12);
           cell->setProperty("Value", "20:00-22:00"); //设置单元格值
           cell = work_sheet->querySubObject("Cells(int,int)",1,13);
           cell->setProperty("Value", "22:00-24:00"); //设置单元格值



           work_book->dynamicCall("Save");

           //work_book->dynamicCall("SaveAs(const QString&)",QString("./sss.xls"));
           QMessageBox::information(this,tr("提示"),tr("导出成功！"));

           work_book->dynamicCall("Close(Boolean)", false); //关闭文件
           excel.dynamicCall("Quit(void)"); //退出
}


void MainWindow::on_pushButton_clicked()
{
    generate();
}

void MainWindow::on_pushButton_3_clicked()
{
   //添加
    ui->widget->setVisible(true);
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
}

void MainWindow::on_pushButton_2_clicked()
{
     QString f=QFileDialog::getOpenFileName(this,"打开文件",".",tr("excel文件(*.xls *.xlsx)"));
     ui->lineEdit->setText(f);
}

void MainWindow::on_pushButton_4_clicked()
{
    int rowindex=ui->tableWidget->currentRow();
    qDebug()<<rowindex;
    if(rowindex!=-1){
        QSqlQuery sql;
        QString dele=ui->tableWidget->currentItem()->text();
        sql.exec(QString("delete from Time where h='%1'").arg(dele));
        ui->tableWidget->removeRow(rowindex);
        QDate tddd=QDate::fromString(dele,"yyyy-MM-dd ddd");
        int zzz=tddd.dayOfYear();
        if(tddd.year()>QDate::currentDate().year())
            zzz+=QDate::currentDate().daysInYear();
        holiday[zzz]=0;
    }
    else{
        QMessageBox::warning(this,tr("错误"),tr("请点击选择要删除节假日！"));
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->widget->setVisible(false);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);

    QDate dd=ui->calendarWidget->selectedDate();
    QString TempT=dd.toString("yyyy-MM-dd ddd");
    QSqlQuery sql;
    boolean x=sql.exec(QString("insert into Time values('%1')").arg(TempT));
    int xxxx=dd.dayOfYear();
    if(dd.year()>QDate::currentDate().year())
        xxxx+=QDate::currentDate().daysInYear();
    holiday[xxxx]=1;
    if(x){
    int rowindex=ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rowindex+1);
    QTableWidgetItem *item=new QTableWidgetItem(TempT);
    ui->tableWidget->setItem(rowindex,0,item);
    }

}

void MainWindow::on_pushButton_6_clicked()
{
    ui->widget->setVisible(false);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
}

void MainWindow::on_StartTime_userDateChanged(const QDate &date)
{
    ui->EndTime->setMinimumDate(ui->StartTime->date());
}

void MainWindow::sethaha(){

}
