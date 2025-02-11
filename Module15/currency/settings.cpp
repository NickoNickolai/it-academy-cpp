#include "settings.h"

#define GROUP "Rates/"

void Settings::load(const QString &fname)
{
    _settings = std::make_unique<QSettings>(fname, QSettings::IniFormat);
    {
        auto type = CurrencyType::BYN;
        auto name = currencyName(type);
        auto rate = 1.0;
        auto value = _settings->value(GROUP + name, rate).toDouble();
        _currencies.insert(type, { name, value });
    }
    {
        auto type = CurrencyType::USD;
        auto name = currencyName(type);
        auto rate = 0.293;
        auto value = _settings->value(GROUP + name, rate).toDouble();
        _currencies.insert(type, { name, value });
    }
    {
        auto type = CurrencyType::EUR;
        auto name = currencyName(type);
        auto rate = 0.2816;
        auto value = _settings->value(GROUP + name, rate).toDouble();
        _currencies.insert(type, { name, value });
    }
    save();
}

void Settings::save()
{
    for(const auto &currency : _currencies)
    {
        _settings->setValue(GROUP + currency.name, currency.rate);
    }
}

QStringList Settings::names()
{
    QStringList result;
    for(const auto &currency : _currencies)
    {
        result << currency.name;
    }
    return result;
}

QList<double> Settings::rates()
{
    QList<double> result;
    for(const auto &currency : _currencies)
    {
        result << currency.rate;
    }
    return result;
}

QString Settings::currencyName(CurrencyType type)
{
    switch(type)
    {
    case CurrencyType::BYN: return "BYN";
    case CurrencyType::USD: return "USD";
    case CurrencyType::EUR: return "EUR";
    default:
        return "unknown";
    }
}
