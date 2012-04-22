//
// C++ Interface: DlgNew
//
// Description: 
//
//
// Author: Flavio Castelli <micron@madlab.it>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "ui_NewForm.h"
#include <QDialog>

class DlgNew : public QDialog, private Ui::NewForm
{
    Q_OBJECT

    public:
        DlgNew (QString* title, QWidget *parent = 0);

    private:
        QString* m_pTitle;

    private slots:
        virtual void accept();
};
