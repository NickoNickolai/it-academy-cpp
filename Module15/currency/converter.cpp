#include "converter.h"

Converter::Converter(const QList<double> &rates)
    : _rates(rates)
{}

void Converter::setRates(const QList<double> &rates)
{
    _rates = rates;
}

void Converter::process(CurrencyData &data)
{
    if(data.rateIn < 0 || data.rateIn >= _rates.size() || data.rateOut < 0 || data.rateOut >= _rates.size())
    {
        return;
    }
    if(data.focusValueIn || data.focusRateIn || data.focusRateOut)
    {
        data.valueOut = data.valueIn / _rates[data.rateIn] * _rates[data.rateOut];
    }
    if(data.focusValueOut)
    {
        data.valueIn = data.valueOut / _rates[data.rateOut] * _rates[data.rateIn];
    }
}
