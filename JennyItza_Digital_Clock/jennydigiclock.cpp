#include "jennydigiclock.h"
#include "ui_jennydigiclock.h"

JennyDigiClock::JennyDigiClock(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JennyDigiClock)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &JennyDigiClock::updateTime);
    timer->start(1000);

    updateTime();

    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);


    connect(this, &QMainWindow::customContextMenuRequested, this, &JennyDigiClock::showContextMenu);

    QSettings settings;
    restoreGeometry(settings.value("MainGeometry").toByteArray());
    restoreState(settings.value("MainState").toByteArray());
    settings.value("TimeFormat", "12 Hr").toString();
    setColor();

}

JennyDigiClock::~JennyDigiClock()
{
    delete ui;
}

void::JennyDigiClock::updateTime(){
    QSettings sts;
    QString format = sts.value("TimeFormat").toString();

    QTime currentTime = QTime::currentTime();
     QString currentTimeText;

      if (format == "12 Hr") {
          currentTimeText = currentTime.toString("hh:mm");
          if ((currentTime.second() % 2) == 0) {
              currentTimeText[2] = ' ';
          }
      }
      else {
          currentTimeText = currentTime.toString("HH:mm:ss");
          if ((currentTime.second() % 2) == 0) {
              currentTimeText[2] = ' ';
              currentTimeText[5] = ' ';
          }
      }

      ui->lcdNumber->display(currentTimeText);

}

void JennyDigiClock::showContextMenu(const QPoint &pos)
{

    QMenu contextMenu;
    contextMenu.addAction("Preference", this, SLOT(showPreference()));
    contextMenu.addAction("Exit", this, SLOT(close()));
    contextMenu.exec(mapToGlobal(pos));
}

void JennyDigiClock::showPreference()
{
    preference* preference = new class preference(this);
      connect(preference, &preference::accepted, this, &JennyDigiClock::setColor);
      preference->exec();
}

void JennyDigiClock::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton)
    {
        emit customContextMenuRequested(e->pos());
    }
    else{
        QMainWindow::mouseReleaseEvent(e);
    }

}

void JennyDigiClock::mousePressEvent(QMouseEvent *e)
{
    m_mousePos = e->pos();

}

void JennyDigiClock::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e-> globalPosition().toPoint() - m_mousePos);
}

void JennyDigiClock::closeEvent(QCloseEvent *e)
{
    QSettings settings;
    settings.setValue("TimeFormat", "12 Hr");  // Save the time format as "12 Hr"
    settings.setValue("MainGeometry", saveGeometry());
    settings.setValue("MainState", saveState());
    e->accept();

}

void JennyDigiClock::setColor()
{
    QSettings sts;
        int i = sts.value("Color").toInt();
        QPalette c;
        //checks to see what color is being passed and assigns it accordingly
        switch (i) {
        case 0:
            c.setColor(QPalette::WindowText, Qt::black);
            break;
        case 1:
            c.setColor(QPalette::WindowText, Qt::yellow);
            break;
        case 2:
            c.setColor(QPalette::WindowText, Qt::green);
            break;
        case 3:
            c.setColor(QPalette::WindowText, Qt::red);
            break;
        }

        ui->lcdNumber->setPalette(c);
        updateTime();

}
