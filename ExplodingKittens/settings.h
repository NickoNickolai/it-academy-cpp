#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <memory>

class Settings
{
public:
    // Загрузка настроек из файла
    static void load(const QString &fname);

    // Сохранение настроек в файл
    static void save();

    // Геттеры для значений настроек
    static auto host() { return _host; }
    static auto port() { return _port; }
    static auto test() { return _test; }

public:
    Settings() = delete;
    Settings(const Settings &) = delete;
    Settings &operator=(const Settings &) = delete;
    Settings(Settings &&) = delete;
    Settings &operator=(Settings &&) = delete;

private:
    static inline std::unique_ptr<QSettings> _settings = nullptr;
    static inline QString _host = "";
    static inline qint16 _port = 0;
    static inline bool _test = false;
};

#endif // SETTINGS_H
