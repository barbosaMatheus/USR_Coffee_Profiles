#include "directorysettingsdialog.h"
#include "ui_directorysettingsdialog.h"

DirectorySettingsDialog::DirectorySettingsDialog( QComboBox *dir_list, QWidget *parent ) : QDialog( parent ), ui( new Ui::DirectorySettingsDialog ) {
    ui->setupUi( this );
    this->setWindowTitle( "Roaster Directory Names" );
    this->dir_list = dir_list;
    beautify( );
    fill_names( );
}

DirectorySettingsDialog::~DirectorySettingsDialog( ) {
    delete ui;
}

void DirectorySettingsDialog::fill_names( void ) {
    ui->line1->setText( dir_list->itemText( 1 ) );
    ui->line2->setText( dir_list->itemText( 2 ) );
    ui->line3->setText( dir_list->itemText( 3 ) );
}

void DirectorySettingsDialog::beautify( void ) {
    this->setWindowFlags( this->windowFlags( ) & ~Qt::WindowContextHelpButtonHint );
    ui->done_button->setStyleSheet( "color: white; background-color: #7a7940" );
}

void DirectorySettingsDialog::on_done_button_clicked( ) {
    dir_list->clear( );
    dir_list->addItem( "All" );
    dir_list->addItem( ui->line1->text( ) );
    dir_list->addItem( ui->line2->text( ) );
    dir_list->addItem( ui->line3->text( ) );
    this->close( );
}
