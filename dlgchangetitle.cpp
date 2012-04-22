//
// C++ Implementation: dlgchangetitle
//
// Description: 
//
//
// Author: Flavio Castelli <micron@madlab.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "dlgchangetitle.h"
#include <QLineEdit>
#include <QMessageBox>

DlgChangeTitle::DlgChangeTitle(QString* title, QWidget *parent)
    : QDialog(parent)
{
    m_pTitle = title;
    
    setupUi(this);

    lineOldTitle->setText(*m_pTitle);
    
    connect( okButton, SIGNAL(clicked()), this, SLOT(accept()) );
}

DlgChangeTitle::~DlgChangeTitle()
{
}

void DlgChangeTitle::accept()
{
    if (lineNewTitle->text().isEmpty())
    {
        QMessageBox::critical( this, "Error","You've to specify file's title" );
    }
    else
    {
        *m_pTitle = lineNewTitle->text();
        QDialog::accept();
    }
}
