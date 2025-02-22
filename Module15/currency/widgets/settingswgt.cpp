#include "settingswgt.h"
#include "ui_settingswgt.h"

#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include "settings.h"

SettingsWgt::SettingsWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWgt)
{
    ui->setupUi(this);

    setWindowModality(Qt::WindowModal);
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setWindowTitle("Настройки");

    int row = 0;
    for(auto &currency : Settings::currencies())
    {
        auto lbl = new QLabel("Курс " + currency.name + ":", this);
        auto dsb = new QDoubleSpinBox(this);
        dsb->setAlignment(Qt::AlignCenter);
        dsb->setRange(1e-4, INT_MAX);
        dsb->setDecimals(4);
        dsb->setValue(currency.rate);
        dsb->setLocale(QLocale(QLocale::English));

        ui->gridLayout->addWidget(lbl, row, 0);
        ui->gridLayout->addWidget(dsb, row, 1);
        ++row;

        connect(dsb, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
                this, [&currency](double value)
        {
            currency.rate = value;
        });
    }

    auto btn = new QPushButton("OK", this);
    ui->gridLayout->addWidget(btn, row, 0, 1, 2);
    connect(btn, &QPushButton::clicked, this, [this]()
    {
        emit signalRateChanged();
        Settings::save();
        close();
    });

    setMinimumWidth(300);
    adjustSize();
    setFixedSize(size());
}

SettingsWgt::~SettingsWgt()
{
    delete ui;
}
