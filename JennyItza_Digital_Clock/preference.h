

//#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class preference;   //preference dialog to change color and time format
}

class preference : public QDialog
{
    Q_OBJECT

public:
    explicit preference(QWidget *parent = 0);
    ~preference();

private:
    Ui::preference *ui; //pointer to the ui
    QButtonGroup *radioButtons; //time format radio buttons

private slots:
    void onAccepted();
};
