#include "widget.h"

#include <QApplication>

int main( int argc, char * argv[] )
{
    QApplication a( argc, argv );
    a.setStyle( "fusion" );

    Widget w;
    w.setWindowTitle( "Hello World" );
    w.show();

    return a.exec();
}
