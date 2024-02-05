#include "dialog.h"
#include "ui_dialog.h"
#include "QStorageInfo"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    
//    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
//        if (storage.isValid() && storage.isReady()) {
//            if (!storage.isReadOnly()) {
                // ...
  //  QStorageInfo::setPath(const QString &path)
    const QString &path="/home";
  //  &path="/home";
             //   QStorageInfo storage =  
                        QStorageInfo storage(qApp->applicationDirPath());
                        //https://spec-zone.ru/qt~5.9/qstorageinfo
                      //  "/home";
  // QStorageInfo::root(); // правильный https://stackoverflow.com/questions/1732717/how-to-determine-how-much-free-space-on-a-drive-in-qt
              
 //  QStorageInfo::setPath(//"/home"
                       //  path
                        // );
               ui->textEdit->append (storage.rootPath());
             
                if (storage.isReadOnly())
                   ui->textEdit->append ( "isReadOnly:"/* + storage*/);
                
                  ui->textEdit->append ( "name: " /*+ storage.name()|*/);
                ui->textEdit->append (  "fileSystemType: " + storage.fileSystemType());
                 ui->textEdit->append ("size: " + QString::number(storage.bytesTotal()/1024/1024) + " MB");
                ui->textEdit->append ( "bytesAvailable: " + QString::number(storage.bytesAvailable()/1024/1024) + " MB");   
                    ui->textEdit->append ( "bytesFree: " + QString::number(storage.bytesFree()/1024/1024) + " MB");
//            }
//        }
//    }
  
}

Dialog::~Dialog()
{
    delete ui;
}

