#ifndef JENNYDIGICLOCK_H
#define JENNYDIGICLOCK_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QSettings>
#include <QCloseEvent>

#include <preference.h>

QT_BEGIN_NAMESPACE
namespace Ui { class JennyDigiClock; }
QT_END_NAMESPACE

class JennyDigiClock : public QMainWindow
{
    Q_OBJECT

public:
    JennyDigiClock(QWidget *parent = nullptr);
    ~JennyDigiClock();

private:
    Ui::JennyDigiClock *ui;
    QPoint m_mousePos;
    void setColor();


private slots:
    void updateTime();
    void showContextMenu(const QPoint &pos);
    void showPreference();

protected:
    void mouseReleaseEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *);


};
#endif // JENNYDIGICLOCK_H
