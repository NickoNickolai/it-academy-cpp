#ifndef CONVERTERWGT_H
#define CONVERTERWGT_H

#include <QWidget>
#include <memory>
#include "converter.h"
#include "settingswgt.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class ConverterWgt;
}
QT_END_NAMESPACE

class ConverterWgt : public QWidget
{
    Q_OBJECT
public:
    ConverterWgt(QWidget *parent = nullptr);
    ~ConverterWgt();

private:
    void procDataByUser();
    void procDataByApp();
    void updateForm(const CurrencyData &data);

private:
    Ui::ConverterWgt *ui;
    SettingsWgt *_setWgt;
    std::unique_ptr<Converter> _conv;
};

#endif // CONVERTERWGT_H
