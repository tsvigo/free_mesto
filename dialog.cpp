#include "dialog.h"
#include "ui_dialog.h"
#include "QStorageInfo"
#include "QThread"
#include <QProcess>

//#include <QMediaPlayer>
// QStorageInfo storage(qApp->applicationDirPath());
int peremennaya_polnoe_prostranstvo;
int peremennaya_dostupnoe_prostranstvo;
int protsent_dostupnogo_prostranstva;
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief path звук
//    QMediaPlayer player; 

//        player.setMedia(QUrl::fromLocalFile("/home/viktor/Загрузки/signal-elektronnogo-budilnika-33304.mp3")); //this seems to be default alert
//    player.setVolume(50); 

//        player.play();

   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const QString &path="/home";
  //  &path="/home";
          // QStorageInfo storage =  
                //    QStorageInfo storage(qApp->applicationDirPath());
                        //https://spec-zone.ru/qt~5.9/qstorageinfo
                      //  "/home";
 // QStorageInfo storage = QStorageInfo::root(); // правильный https://stackoverflow.com/questions/1732717/how-to-determine-how-much-free-space-on-a-drive-in-qt
              
 //  QStorageInfo::setPath(//"/home"
                       //  path
                        // );
    QStorageInfo storage(qApp->applicationDirPath()); // правильный 2-/home
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
  
   QStorageInfo storage(qApp->applicationDirPath()); // /home
 // QStorageInfo storage = QStorageInfo::root(); // корень - /
    // правильный https://stackoverflow.com/questions/1732717/how-to-determine-how-much-free-space-on-a-drive-in-qt
    ui->textEdit->append (storage.rootPath());
    
    if (storage.isReadOnly())
        ui->textEdit->append ( "isReadOnly:"/* + storage*/);
    
    ui->textEdit->append ( "name: " /*+ storage.name()|*/);
    ui->textEdit->append (  "fileSystemType: " + storage.fileSystemType());
    ui->textEdit->append ("size: " + QString::number(storage.bytesTotal()/1024/1024) + " MB");
    ui->textEdit->append ( "bytesAvailable: " + QString::number(storage.bytesAvailable()/1024/1024) + " MB");   
    ui->textEdit->append ( "bytesFree: " + QString::number(storage.bytesFree()/1024/1024) + " MB");
  //  ui->textEdit->append ( ".");
    // надо посчитать процент доступного места
//    Сколько процентов составляет 24 от числа 248 ?
//            Итог - 9.677 %
//        Как вычислять:
//        Получаем коэффициент - 248 / 24 = 10.333
//            Получаем проценты - 100% / 10.333 = 9.677 %
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //    Сколько процентов составляет доступное пространство от полного пространства ?
    //            Итог - 9.677 %
    //        Как вычислять:;
    //        Получаем коэффициент - полное пространство / доступное пространство = 10.333
    //            Получаем проценты - 100% / ( полное пространство / доступное пространство) = 9.677 %
//    int peremennaya_polnoe_prostranstvo;
//    int peremennaya_dostupnoe_prostranstvo;
//    int protsent_dostupnogo_prostranstva;
    peremennaya_polnoe_prostranstvo=storage.bytesTotal()/1024/1024;
    peremennaya_dostupnoe_prostranstvo=storage.bytesAvailable()/1024/1024;
    int x =peremennaya_polnoe_prostranstvo/peremennaya_dostupnoe_prostranstvo;
    protsent_dostupnogo_prostranstva=100/(x);
    ui->textEdit->append ( "Процент доступного пространства: " + QString::number(protsent_dostupnogo_prostranstva) + " %");
/// 
/// проверка величины:
    if (protsent_dostupnogo_prostranstva<=15)
    {
      //  ;; // TODO beep
         ui->textEdit->append ( "Тревога - доступное пространство равно 15%!");
         tmr->stop(); // остановим таймер
//    a:
//        QThread::sleep (2);
        QApplication:: beep () ;
    a:
        //        QThread::sleep (2);
        // звуковой сигнал:
        QProcess().execute("/home/viktor/my_scripts_2/sound.sh");
      //  Вам просто нужно установить утилиту SoX.
        // https://forum.qt.io/topic/54162/solved-qapplication-beep-no-sound-on-linux/15
            // QThread::sleep (2);
        goto a;
//        QThread::sleep (2);
//        goto a;
    }
///     
}










