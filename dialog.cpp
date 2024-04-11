// Отправление всех репозиториев GIT в Интернет.
#include "dialog.h"
#include "ui_dialog.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include <QProcess>
#include <QTextStream>
#include <QFile>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
///
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//QString  comanda_spiska_katalogov=

        QProcess::execute("/home/viktor/my_scripts_4/catalogi_v_file.sh");
        // создали свежий список каталогов в файле /home/viktor/my_projects_qt_2/Avtokopirovaniye_GIT_TSIKL/spisok.txt
//      QString  directory;
//        QString  comanda_vsia="cd "+directory +
//" && git init && git add --all && git commit -m \"Описание коммита \" && hub create && hub push origin";
//          system (comanda_vsia.toStdString().c_str() );
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QFile inputFile("/home/viktor/my_projects_qt_2/Avtokopirovaniye_GIT_TSIKL/spisok.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
    
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          QString  comanda_vsia="cd /home/viktor/my_projects_qt_2/"+line +
//" && git init && git add --all && git commit -m \"Описание коммита \" && hub create && hub push origin";
" && /usr/bin/git init && /usr/bin/git add --all && /usr/bin/git commit -m \"Описание коммита \" && cd /home/viktor/my_projects_qt_2/"+line
// +" && /usr/bin/hub create && cd /home/viktor/my_projects_qt_2/"+line 
+"&& git remote add origin https://github.com/tsvigo/"+line
+ "&& git push origin master";
// +" && /usr/bin/hub push origin";
// "git remote add origin https://github.com/tsvigo/"+line
// which git; /usr/bin/git
// cd /home/viktor/my_projects_qt_2/"+line +
            system (comanda_vsia.toStdString().c_str() );
       //   ...
       }
       inputFile.close();
    }          
          
}

Dialog::~Dialog()
{
    delete ui;
}

