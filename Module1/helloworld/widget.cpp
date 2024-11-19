#include "widget.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <iostream>

Widget::Widget( QWidget * parent )
    : QWidget( parent )
{
    auto greet = QString( "Hello, <i>%1</i>!" );

    auto lbl_text = new QLabel( greet.arg( "World" ), this );
    lbl_text->setPalette( Qt::lightGray );
    lbl_text->setAutoFillBackground( true );
    lbl_text->setFrameStyle( QFrame::StyledPanel );
    lbl_text->setTextFormat( Qt::RichText );
    lbl_text->setAlignment( Qt::AlignCenter );

    auto lbl_name = new QLabel( "Enter your name:", this );
    auto led_name = new QLineEdit( this );
    led_name->setPlaceholderText( "Name" );

    auto btn_clear = new QPushButton( "&Clear", this );
    auto btn_greet = new QPushButton( "&Greet", this );

    auto grid = new QGridLayout( this );
    grid->addWidget( lbl_text, 0, 0, 1, 2 );
    grid->addWidget( lbl_name, 1, 0 );
    grid->addWidget( led_name, 1, 1 );
    grid->addWidget( btn_clear, 2, 0 );
    grid->addWidget( btn_greet, 2, 1 );

    // Отображение строки приветствия на форме
    connect( btn_greet, &QPushButton::clicked, [ = ]()
    {
        auto text = led_name->text();

        if( !text.isEmpty() )
        {
            lbl_text->setText( greet.arg( text ) );

            // Вывод строки приветствия на консоль средствами STL
            std::cout << "Hello, " << text.toStdString() << "!" << std::endl;
        }
        else
        {
            lbl_text->setText( "Enter your name, please" );
        }
    } );

    // Очистка строки приветствия на форме
    connect( btn_clear, &QPushButton::clicked, lbl_text, &QLabel::clear );
}

Widget::~Widget()
{
}
