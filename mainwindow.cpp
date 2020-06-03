#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/figlet.h"
//extern "C"{
//int mainfiglet(int argc, char **argv);
//}

//void test(){

//    char *argv1[]={"appname","testing 12345","-h","test"};
//         int argc1 = sizeof(argv1) / sizeof(char*) - 1;

//      mainfiglet(argc1,argv1);

//}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    char *argv1[]={"appname","-f","./fonts/standard.flf","test","test"};
   //   char *argv1[]={"appname","test"};
         int argc1 = sizeof(argv1) / sizeof(char*) - 1;

//      figlet(argc1,argv1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int figlet_wrapper(char* csv)
{
std::vector<char*> parts;
char* part = strtok(csv, ",");
while (part) {
    parts.push_back(part);
    part = strtok(nullptr, ",");
}
return figlet(parts.size(), parts.data());
}

void MainWindow::on_asciigen_clicked()
{
//test();
//        char *argv1[]={"appname","testing 12345","-f","./fonts/standard.flf","test"};
//             int argc1 = sizeof(argv1) / sizeof(char*) - 1;


          QString fileslist;

           fileslist.append("blank,");

           fileslist.append("-f,");
           fileslist.append("./fonts/standard.flf,");

           fileslist.append("test");

           QByteArray array = fileslist.toLocal8Bit();
           char* buffer = array.data();

           figlet_wrapper(buffer);
}
