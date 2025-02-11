#ifndef CONVERTER_H
#define CONVERTER_H

#include <QList>
#include <cstring>

struct CurrencyData
{
    bool focusValueIn;
    bool focusValueOut;
    double valueIn;
    double valueOut;
    bool focusRateIn;
    bool focusRateOut;
    int rateIn;
    int rateOut;

    CurrencyData()
    {
        memset(static_cast<void *>(this), 0, sizeof(*this));
    }
};

class Converter
{
public:
    Converter(const QList<double> &rates);

    // Установка курсов валют
    void setRates(const QList<double> &rates);

    // Конвертация валют
    void process(CurrencyData &data);

private:
    QList<double> _rates;
};

#endif // CONVERTER_H
