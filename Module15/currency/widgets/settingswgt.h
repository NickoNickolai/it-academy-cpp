#ifndef SETTINGSWGT_H
#define SETTINGSWGT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class SettingsWgt;
}
QT_END_NAMESPACE

class SettingsWgt : public QWidget
{
    Q_OBJECT
public:
    SettingsWgt(QWidget *parent = nullptr);
    ~SettingsWgt();

signals:
    // Сигнал о изменении курсов валют
    void signalRateChanged();

private:
    Ui::SettingsWgt *ui;
};

#endif // SETTINGSWGT_H
