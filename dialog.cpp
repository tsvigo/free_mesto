#include "dialog.h"
#include "ui_dialog.h"
#include "QStorageInfo"
// QStorageInfo storage(qApp->applicationDirPath());
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
  //  QStorageInfo storage(qApp->applicationDirPath());
    ui->setupUi(this);
  //  QStorageInfo storage(qApp->applicationDirPath());
//    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
//        if (storage.isValid() && storage.isReady()) {
//            if (!storage.isReadOnly()) {
                // ...
  //  QStorageInfo::setPath(const QString &path)
    const QString &path="/home";
  //  &path="/home";
             //   QStorageInfo storage =  
                //    QStorageInfo storage(qApp->applicationDirPath());
                        //https://spec-zone.ru/qt~5.9/qstorageinfo
                      //  "/home";
  // QStorageInfo::root(); // правильный https://stackoverflow.com/questions/1732717/how-to-determine-how-much-free-space-on-a-drive-in-qt
              
 //  QStorageInfo::setPath(//"/home"
                       //  path
                        // );
    QStorageInfo storage(qApp->applicationDirPath());
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  Надо сделать таймер
                    tmr = new QTimer(this); // Создаем объект класса QTimer и передаем адрес переменной
                    tmr->setInterval(5000); // Задаем интервал таймера
                    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime())); // Подключаем сигнал таймера к нашему слоту
                    tmr->start(); // Запускаем таймер 
///   
}

Dialog::~Dialog()
{
    delete ui;
    delete tmr;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Dialog::updateTime()
{
   //  ui->textEdit->append ( ".");
  ui->textEdit->clear ();
   //  ui->textEdit->append ( ".");
  //  ui->label->setText(QTime::currentTime().toString());
    // обновим текстовое поле
    QStorageInfo storage(qApp->applicationDirPath());
    ui->textEdit->append (storage.rootPath());
    
    if (storage.isReadOnly())
        ui->textEdit->append ( "isReadOnly:"/* + storage*/);
    
    ui->textEdit->append ( "name: " /*+ storage.name()|*/);
    ui->textEdit->append (  "fileSystemType: " + storage.fileSystemType());
    ui->textEdit->append ("size: " + QString::number(storage.bytesTotal()/1024/1024) + " MB");
    ui->textEdit->append ( "bytesAvailable: " + QString::number(storage.bytesAvailable()/1024/1024) + " MB");   
    ui->textEdit->append ( "bytesFree: " + QString::number(storage.bytesFree()/1024/1024) + " MB");
  //  ui->textEdit->append ( ".");
    //TODO надо посчитать процент доступного места
//    Сколько процентов составляет 24 от числа 248 ?
//            Итог - 9.677 %
//        Как вычислять:
//        Получаем коэффициент - 248 / 24 = 10.333
//            Получаем проценты - 100% / 10.333 = 9.677 %
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //    Сколько процентов составляет доступное пространство от полного пространства ?
    //            Итог - 9.677 %
    //        Как вычислять:
    //        Получаем коэффициент - полное пространство / доступное пространство = 10.333
    //            Получаем проценты - 100% / ( полное пространство / доступное пространство) = 9.677 %
    
/// 
/// 
///     
}










