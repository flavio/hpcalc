//
// C++ Implementation: DlgNew
//
// Description: 
//
//
// Author: Flavio Castelli <micron@madlab.it>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "DlgNew.h"
#include <QLineEdit>
#include <QMessageBox>

DlgNew::DlgNew(QString* title, QWidget *parent)
    : QDialog(parent)
{
    m_pTitle = title;
    
    setupUi(this);

    connect( BtnOk, SIGNAL(clicked()), this, SLOT(accept()) );
}

void DlgNew::accept()
{
    if (titleEdit->text().isEmpty())
    {
        QMessageBox::critical( this, "Error","You've to specify file's title" );
    }
    else
    {
        *m_pTitle = titleEdit->text();
        QDialog::accept();
    }
}
