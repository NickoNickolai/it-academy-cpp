#ifndef SETTINGS_H
#define SETTINGS_H

#include <QList>
#include <QMap>
#include <QSettings>
#include <memory>

enum class CurrencyType
{
    UNKNOWN = -1,
    BYN,
    USD,
    EUR
};

struct CurrencyItem
{
    QString name;
    double rate;
};

class Settings
{
public:
    // Загрузка настроек из файла
    static void load(const QString &fname);

    // Сохранение настроек в файл
    static void save();

    // Получение списка структур валют
    static auto &currencies() { return _currencies; }

    // Получение списка названий валют
    static QStringList names();

    // Получение списка курсов валют
    static QList<double> rates();

public:
    Settings() = delete;
    Settings(const Settings &) = delete;
    Settings &operator=(const Settings &) = delete;
    Settings(Settings &&) = delete;
    Settings &operator=(Settings &&) = delete;

private:
    // Получение названия валюты по типу
    static QString currencyName(CurrencyType type);

private:
    static inline QMap<CurrencyType, CurrencyItem> _currencies;
    static inline std::unique_ptr<QSettings> _settings;
};

#endif // SETTINGS_H
