#include "mainwindow.h"
#include <QApplication>

int main( int argc, char *argv[] ) {
    QApplication a( argc, argv );
    QPixmap pixmap( "C:/USRoasterStudio/images/splash.jpg" );
    QSplashScreen splash( pixmap );
    splash.setCursor( Qt::BusyCursor );
    splash.show( );
    a.processEvents( );
    MainWindow w;
    w.show( );
    splash.finish( &w );
    return a.exec( );
}
