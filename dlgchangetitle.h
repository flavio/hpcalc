//
// C++ Interface: dlgchangetitle
//
// Description: 
//
//
// Author: Flavio Castelli <micron@madlab.it>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef DLGCHANGETITLE_H
#define DLGCHANGETITLE_H

/**
@author Flavio Castelli
*/
#include "ui_ChangeTitleForm.h"
#include <QDialog>

class DlgChangeTitle : public QDialog, private Ui::ChangeTitleForm
{
    Q_OBJECT

    public:
        DlgChangeTitle (QString* title, QWidget *parent = 0);
        ~DlgChangeTitle();
        
    private:
        QString* m_pTitle;

    private slots:
        virtual void accept();
};

#endif
