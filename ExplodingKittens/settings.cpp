#include "settings.h"

void Settings::load(const QString &fname)
{
    _settings = std::make_unique<QSettings>(fname, QSettings::IniFormat);
    _host = _settings->value("Network/host", "127.0.0.1").toString();
    _port = _settings->value("Network/port", 12345).toInt();
    _test = _settings->value("Game/test", false).toBool();
    save();
}

void Settings::save()
{
    _settings->setValue("Network/host", _host);
    _settings->setValue("Network/port", _port);
    _settings->sync();
}
