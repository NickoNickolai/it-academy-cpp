#include "converterwgt.h"
#include "ui_converterwgt.h"
#include "settings.h"

ConverterWgt::ConverterWgt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConverterWgt)
{
    ui->setupUi(this);

    _setWgt = new SettingsWgt(this);
    connect(_setWgt, &SettingsWgt::signalRateChanged,
            this, &ConverterWgt::procDataByApp);

    QLocale locale(QLocale::C);
    locale.setNumberOptions(QLocale::RejectGroupSeparator);
    auto validator = new QDoubleValidator(0, 1e9, 2, this);
    validator->setNotation(QDoubleValidator::StandardNotation);
    validator->setLocale(locale);

    ui->ledValueIn->setText("0");
    ui->ledValueIn->setAlignment(Qt::AlignCenter);
    ui->ledValueIn->setValidator(validator);

    ui->ledValueOut->setText("0");
    ui->ledValueOut->setAlignment(Qt::AlignCenter);
    ui->ledValueOut->setValidator(validator);

    connect(ui->ledValueIn, &QLineEdit::textChanged,
            this, &ConverterWgt::procDataByUser);
    connect(ui->ledValueOut, &QLineEdit::textChanged,
            this, &ConverterWgt::procDataByUser);

    ui->cmbCurrencyIn->addItems(Settings::names());
    ui->cmbCurrencyOut->addItems(Settings::names());

    connect(ui->cmbCurrencyIn, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ConverterWgt::procDataByUser);
    connect(ui->cmbCurrencyOut, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ConverterWgt::procDataByUser);

    ui->btnSet->setText("Настройки");
    ui->btnClose->setText("Закрыть");

    connect(ui->btnSet, &QPushButton::clicked,
            _setWgt, &SettingsWgt::show);
    connect(ui->btnClose, &QPushButton::clicked,
            this, &ConverterWgt::close);

    _conv = std::make_unique<Converter>(Settings::rates());

    setMinimumWidth(300);
    adjustSize();
    setFixedSize(size());
}

ConverterWgt::~ConverterWgt()
{
    delete ui;
}

void ConverterWgt::procDataByUser()
{
    CurrencyData data;
    data.focusValueIn = ui->ledValueIn->hasFocus() ? true : false;
    data.focusValueOut = ui->ledValueOut->hasFocus() ? true : false;
    data.valueIn = ui->ledValueIn->text().toDouble();
    data.valueOut = ui->ledValueOut->text().toDouble();

    data.focusRateIn = ui->cmbCurrencyIn->hasFocus() ? true : false;
    data.focusRateOut = ui->cmbCurrencyOut->hasFocus() ? true : false;
    data.rateIn = ui->cmbCurrencyIn->currentIndex();
    data.rateOut = ui->cmbCurrencyOut->currentIndex();

    _conv->process(data);
    updateForm(data);
}

void ConverterWgt::procDataByApp()
{
    _conv->setRates(Settings::rates());

    CurrencyData data;
    data.focusValueIn = true;
    data.valueIn = ui->ledValueIn->text().toDouble();
    data.rateIn = ui->cmbCurrencyIn->currentIndex();
    data.rateOut = ui->cmbCurrencyOut->currentIndex();

    _conv->process(data);
    updateForm(data);
}

void ConverterWgt::updateForm(const CurrencyData &data)
{
    if(data.focusValueIn || data.focusRateIn || data.focusRateOut)
    {
        ui->ledValueOut->setText(QString::number(data.valueOut, 'f', 2));
    }
    if(data.focusValueOut)
    {
        ui->ledValueIn->setText(QString::number(data.valueIn, 'f', 2));
    }
}
