#include "DlgMain.h"
#include "DlgNew.h"
#include "dlgchangetitle.h"

#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QIcon>
#include <QRegExp>
#include <QString>

#include <QTextEdit>
#include <QGroupBox>
#include <QFileDialog>
#include <QFile>
#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSettings>

DlgMain::DlgMain(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    
    QCoreApplication::setOrganizationName("Flavio Castelli");
    QCoreApplication::setOrganizationDomain("www.flavio.castelli.name");
    QCoreApplication::setApplicationName("HpCalc");
    
    createActions();
    createMenus();
    createToolBars();
    setupSymbolTab();
    
    enableButtons (false, true);
    editorBox->hide();
    symbolBox->hide();

    connect(textEditor, SIGNAL(undoAvailable(bool)), this, SLOT(undoEvent(bool)));
    
    connect(textEditor, SIGNAL(redoAvailable(bool)), this, SLOT(redoEvent(bool)));
    
    connect(textEditor, SIGNAL(copyAvailable(bool)), this, SLOT(copyEvent(bool)));
    
    connect(textEditor, SIGNAL(textChanged()), this, SLOT(textChangedEvent()));
    
    // create status bar
    statusBar();
}

// bool DlgMain::event(QEvent *e)
// {
//     if (e->type() == QEvent::Polish)
//     {
//         e->accept();
//         
//         QCoreApplication *app = QCoreApplication::instance();
//         QStringList args = app->arguments();
//         QString message = args.join("\n");
//     
//         QMessageBox::information (this, "Info", message);
//     }
//     
//     return QMainWindow::event(e);
// }

void DlgMain::init(const char* fileName)
{
    if (fileName == NULL)
        fileNew();
    else
    {
        m_strFilename = fileName;
        try
        {
        
            if (!QFile::exists( m_strFilename ))
                throw (QString ("Selected filename doesn't exist!"));
        
            load();
        }
        catch (QString &msg)
        {
            msg = "File Open abandoned\n" + msg;
            QMessageBox::critical (this, "Error", msg);
            
            fileNewAct->setEnabled(true);
            fileOpenAct->setEnabled(true);
        }
        catch (...)
        {
            QMessageBox::critical (this, "Error", "General error");
        }
    }
}
void DlgMain::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(editCutAct);
    menu.addAction(editCopyAct);
    menu.addAction(editPasteAct);
    menu.exec(event->globalPos());
}

void DlgMain::createActions()
{
    fileNewAct = new QAction(QIcon(":/images/filenew.png"),tr("&New"), this);
    fileNewAct->setShortcut(tr("Ctrl+N"));
    fileNewAct->setStatusTip(tr("Create a new file"));
    connect(fileNewAct, SIGNAL(triggered()), this, SLOT(fileNew()));

    fileOpenAct = new QAction(QIcon(":/images/fileopen.png"),tr("&Open..."), this);
    fileOpenAct->setShortcut(tr("Ctrl+O"));
    fileOpenAct->setStatusTip(tr("Open an existing file"));
    connect(fileOpenAct, SIGNAL(triggered()), this, SLOT(fileOpen()));

    fileSaveAct = new QAction(QIcon(":/images/filesave.png"),tr("&Save"), this);
    fileSaveAct->setShortcut(tr("Ctrl+S"));
    fileSaveAct->setStatusTip(tr("Save the document to disk"));
    connect(fileSaveAct, SIGNAL(triggered()), this, SLOT(fileSave()));
    
    fileSaveAsAct = new QAction(QIcon(":/images/filesaveas.png"),tr("Save &As"), this);
    fileSaveAsAct->setStatusTip(tr("Save the document to disk with another name"));
    connect(fileSaveAsAct, SIGNAL(triggered()), this, SLOT(fileSaveAs()));

    //fileExitAct = new QAction(QIcon(":/images/filesave.png"),tr("&Exit"), this);
    
    fileCloseAct = new QAction(tr("&Close"), this);
    fileCloseAct->setShortcut(tr("Ctrl+W"));
    fileCloseAct->setStatusTip(tr("Close this document"));
    connect(fileCloseAct, SIGNAL(triggered()), this, SLOT(fileClose()));
    
    fileExitAct = new QAction(tr("&Exit"), this);
    fileExitAct->setShortcut(tr("Ctrl+Q"));
    fileExitAct->setStatusTip(tr("Quit the program"));
    connect(fileExitAct, SIGNAL(triggered()), this, SLOT(fileExit()));
    
    filePrintAct = new QAction(tr("&Print..."), this);
    filePrintAct->setShortcut(tr("Ctrl+P"));
    filePrintAct->setStatusTip(tr("Print the document"));
    connect(filePrintAct, SIGNAL(triggered()), this, SLOT(filePrint()));

    editUndoAct = new QAction(QIcon(":/images/undo.png"),tr("&Undo"), this);
    editUndoAct->setShortcut(tr("Ctrl+Z"));
    editUndoAct->setStatusTip(tr("Undo the last operation"));
    connect(editUndoAct, SIGNAL(triggered()), this, SLOT(editUndo()));

    editRedoAct = new QAction(QIcon(":/images/redo.png"),tr("&Redo"), this);
    editRedoAct->setShortcut(tr("Ctrl+Y"));
    editRedoAct->setStatusTip(tr("Redo the last operation"));
    connect(editRedoAct, SIGNAL(triggered()), this, SLOT(editRedo()));

    editCutAct = new QAction(QIcon(":/images/editcut.png"),tr("Cu&t"), this);
    editCutAct->setShortcut(tr("Ctrl+X"));
    editCutAct->setStatusTip(tr("Cut the current selection's contents to the "
            "clipboard"));
    connect(editCutAct, SIGNAL(triggered()), this, SLOT(editCut()));

    editCopyAct = new QAction(QIcon(":/images/editcopy.png"),tr("&Copy"), this);
    editCopyAct->setShortcut(tr("Ctrl+C"));
    editCopyAct->setStatusTip(tr("Copy the current selection's contents to the "
            "clipboard"));
    connect(editCopyAct, SIGNAL(triggered()), this, SLOT(editCopy()));

    editPasteAct = new QAction(QIcon(":/images/editpaste.png"),tr("&Paste"), this);
    editPasteAct->setShortcut(tr("Ctrl+V"));
    editPasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
            "selection"));
    connect(editPasteAct, SIGNAL(triggered()), this, SLOT(editPaste()));
    
    editChangeTitleAct = new QAction(tr("Change title"), this);
    editChangeTitleAct->setStatusTip(tr("Change file title"));
    connect(editChangeTitleAct, SIGNAL(triggered()), this, SLOT(editChangeTitle()));
    
    editInsertSymbolAct = new QAction(QIcon(":/images/kcharselect.png"),tr("&Insert Symbol"), this);
    editInsertSymbolAct->setCheckable(true);
    //editInsertSymbolAct->setShortcut(tr("Ctrl+V"));
    editInsertSymbolAct->setStatusTip(tr("Insert a special symbol"));
    connect(editInsertSymbolAct, SIGNAL(toggled(bool)), this, SLOT(editInsertSymbol(bool)));
    

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    
    connect(aboutQtAct, SIGNAL(triggered()), this, SLOT(aboutQt()));
    
    for (unsigned int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(recentFileActs[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
    }
}

void DlgMain::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(fileNewAct);
    fileMenu->addAction(fileOpenAct);
    fileMenu->addAction(fileSaveAct);
    fileMenu->addAction(fileSaveAsAct);
    //fileMenu->addAction(filePrintAct);
    
    separatorAct = fileMenu->addSeparator();
    for (int i = 0; i < MaxRecentFiles; ++i)
        fileMenu->addAction(recentFileActs[i]);
    
    updateRecentFileActions();
    
    fileMenu->addSeparator();
    fileMenu->addAction(fileCloseAct);
    fileMenu->addAction(fileExitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(editUndoAct);
    editMenu->addAction(editRedoAct);
    editMenu->addSeparator();
    editMenu->addAction(editCutAct);
    editMenu->addAction(editCopyAct);
    editMenu->addAction(editPasteAct);
    editMenu->addSeparator();
    editMenu->addAction(editChangeTitleAct);
    editMenu->addAction(editInsertSymbolAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void DlgMain::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(fileNewAct);
    fileToolBar->addAction(fileOpenAct);
    fileToolBar->addAction(fileSaveAct);
    fileToolBar->addAction(fileSaveAsAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(editCutAct);
    editToolBar->addAction(editCopyAct);
    editToolBar->addAction(editPasteAct);
    editToolBar->addSeparator();
    editToolBar->addAction(editUndoAct);
    editToolBar->addAction(editRedoAct);
    editToolBar->addSeparator();
    editToolBar->addAction(editInsertSymbolAct);
}

void DlgMain::updateRecentFileActions()
{
    QSettings settings;
    QStringList files = settings.value("recentFileList").toStringList();

    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1 %2").arg(i + 1).arg(strippedName(files[i]));
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
        text = tr("Open \"%1\"").arg(files[i]);
        recentFileActs[i]->setStatusTip(text);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActs[j]->setVisible(false);

    separatorAct->setVisible(numRecentFiles > 0);
}

void DlgMain::enableButtons(bool enable, bool extended)
{
    // enable/disable main toolbar buttons
    fileSaveAct->setEnabled (enable);
    fileSaveAsAct->setEnabled (enable);
    fileCloseAct->setEnabled (enable);
    editInsertSymbolAct->setEnabled (enable);
    editChangeTitleAct->setEnabled(enable);
    
    if (extended)
    {
        editUndoAct->setEnabled (enable);
        editRedoAct->setEnabled (enable);
        editCutAct->setEnabled (enable);
        editCopyAct->setEnabled (enable);
        editPasteAct->setEnabled (enable);
    }
}

void DlgMain::setupSymbolTab()
{
    // clear all tabs
    while (symbolTab->count() > 0)
        symbolTab->removeTab(0);
    
    for (int i = 0; i < 5; i++)
    {
        QListWidget * symbolList;
        Symbol::SymbolType sType = Symbol::ALL;
        QString tabName;
        
        symbolList = new QListWidget ();
        
        symbolList->setViewMode (QListView::IconMode);
        symbolList->setSpacing (10);
        symbolList->setMovement(QListView::Static);
        symbolList->setResizeMode(QListView::Adjust);
        symbolList->setFlow(QListView::LeftToRight);
        symbolList->setWrapping (true);
        
        connect( symbolList, SIGNAL(itemClicked (QListWidgetItem*)), this, SLOT(symbolClicked(QListWidgetItem*)) );
        
        switch (i)
        {//GREEK, MATH, OTHER, FONT, ALL
            case 0:
                tabName = "Greek";
                sType = Symbol::GREEK;
                break;
            case 1:
                tabName = "Math";
                sType = Symbol::MATH;
                break;
            case 2:
                tabName = "Other";
                sType = Symbol::OTHER;
                break;
            case 3:
                tabName = "Font";
                sType = Symbol::FONT;
                break;
            case 4:
                tabName = "All";
                sType = Symbol::ALL;
                break;
        }
        
        QStringList names = m_converter.getNames(sType);
        
        symbolList->addItems(names);
        
        symbolTab->addTab (symbolList, tabName);
    }
    
    // setup connections
    
    connect( symbolTab, SIGNAL(currentChanged (int)), this, SLOT(symbolTabChanged()) );
    
//     m_iPreviusSelectedTab = 0;
    
//     m_bSymbolTabReduced = false;
    
}

void DlgMain::symbolTabChanged()
{
//     printf ("symbolTabChanged: %i\n", symbolTab->currentIndex());
    
    QListWidget *symbolList = NULL;
    
    symbolList = (QListWidget*)symbolTab->currentWidget();
    
    symbolList->setViewMode (QListView::IconMode);
    symbolList->setSpacing (10);
    symbolList->setMovement(QListView::Static);
    symbolList->setResizeMode(QListView::Adjust);
    symbolList->setFlow(QListView::LeftToRight);
    symbolList->setWrapping (true);

/*    
    if (symbolTab->currentIndex() != m_iPreviusSelectedTab)
    {
        printf ("changed\n");
        
        symbolList->setViewMode (QListView::IconMode);
        symbolList->setSpacing (10);
        symbolList->setMovement(QListView::Static);
        symbolList->setResizeMode(QListView::Adjust);
        symbolList->setFlow(QListView::LeftToRight);
        symbolList->setWrapping (true);
    }
    else
    {
        symbolTab->setUpdatesEnabled(false);
        
        printf ("always the same\n");
        
        QSize tabWidgetSize;
        
        if (m_bSymbolTabReduced)
        {
            printf ("//hidden -> show\n");
            
            tabWidgetSize = symbolTab->size();
            printf ("tabWidgetSiz before = %i\n",tabWidgetSize.width());
            
            tabWidgetSize.rwidth() += m_iPrevSymbolWidgetWidth;
            
            printf ("tabWidgetSiz after = %i\n",tabWidgetSize.width());
            
            symbolTab->resize(tabWidgetSize);
            
            symbolBox->setTitle (QString("Symbol Table"));
            
            symbolList->show();
            
            symbolList->setViewMode (QListView::IconMode);
            symbolList->setSpacing (10);
            symbolList->setMovement(QListView::Static);
            symbolList->setResizeMode(QListView::Adjust);
            symbolList->setFlow(QListView::LeftToRight);
            symbolList->setWrapping (true);
            
            m_bSymbolTabReduced = false;
        }
        else
        {
            printf ("// show --> hidden\n");
            
            tabWidgetSize = symbolTab->size();
            
            m_iPrevSymbolWidgetWidth = tabWidgetSize.width();
            
            printf ("tabWidgetSiz before = %i\n",tabWidgetSize.width());
            
            tabWidgetSize.rwidth() -= symbolList->width();
            printf ("tabWidgetSiz after = %i\n",tabWidgetSize.width());
            
            symbolList->hide();
            
            symbolBox->setTitle (QString(""));
            
            symbolBox->setMinimumSize(tabWidgetSize);
            
            symbolTab->resize(tabWidgetSize);
            
            m_bSymbolTabReduced = true;
        }
        
        symbolTab->setUpdatesEnabled(true);
        
        printf ("LAST: tabWidgetSiz after = %i\n",symbolTab->width());
    }
    
    m_iPreviusSelectedTab = symbolTab->currentIndex();*/
}

void DlgMain::symbolClicked(QListWidgetItem* item)
{
    // user didn't click on an item
    if (item == 0)
        return;
    
    textEditor->insertPlainText(item->text());
}

void DlgMain::textChangedEvent()
{
    QString title;
    
    title = windowTitle();
    
    if (!title.contains(QString(" [modified]")))
        title += " [modified]";
    
    setWindowTitle(title);
}

bool DlgMain::okToClear ()
{
    if (textEditor->document()->isModified())
    {
        if (QMessageBox::warning (this, "Attenction1","Your document has been modified\n" "Are you sure to close this file?",QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton) == QMessageBox::Yes)
            return true;
        
        return false;
    }
        
    //nothing changed, we can clear all
    return true;
}

void DlgMain::fileNew()
{
    if (!okToClear())
        return;
    
    // cleanup procedure
    enableButtons (false);
    fileNewAct->setEnabled(false);
    fileOpenAct->setEnabled(false);
    
    editorBox->hide();
    symbolBox->hide();
    m_strTitle = "";
    
    QString caption ("New file");
    
    DlgNew* dlg = new DlgNew (&m_strTitle, this);
    dlg->setModal(true);
    dlg->exec();
    
    delete dlg;
    
    if (!m_strTitle.isEmpty())
    {
        editorBox->show();
        
        if (editInsertSymbolAct->isChecked())
            symbolBox->show();
        
        editorBox->setTitle(m_strTitle);
        
        textEditor->document()->clear();
        
        enableButtons (true);
    }
    
    fileNewAct->setEnabled(true);
    fileOpenAct->setEnabled(true);
    setWindowTitle(" HpCalc - Untitled");
}

void DlgMain::editChangeTitle()
{
    DlgChangeTitle* dlg = new DlgChangeTitle (&m_strTitle, this);
    dlg->setModal(true);
    dlg->exec();
    
    editorBox->setTitle(m_strTitle);
}

void DlgMain::load ()
{
    QString plainText, encodedText;
    char *dataBlock;
    QFile file (m_strFilename);
    
    dataBlock = new char[500];
    
    m_strTitle = "";
    
    try
    {
        
        
        file.open (QIODevice::ReadOnly);
        
        while (!file.atEnd())
        {
            //readData = file.readBlock (dataBlock, sizeof (char) * 500);
            if (file.readLine(dataBlock, sizeof(char)*500) == -1)
                throw QString ("Error while reading file");
            
            encodedText += QString(dataBlock);
        }
        
        delete dataBlock;
        dataBlock = NULL;
        
        file.close();

        // header structure: "|HP39AscC |title length| "
        QRegExp exp ( "^(HP39AscC \\d+ )");
        
        if (exp.indexIn(encodedText) == -1)
            throw QString ("Corrupted or invalid file");
        
        unsigned int titleLength;
        QString temp;
        
        //remove |HP39AscC |
        encodedText.remove (0,9);
        
        // read title's length
        while (encodedText[0] != QChar(' '))
        {
            temp += encodedText[0];
            encodedText.remove(0,1);
        }
        
        //remove last space before title
        encodedText.remove(0,1);
        
        titleLength = temp.toUInt();
        
        for (unsigned int i = 0; i < titleLength; i++)
            m_strTitle += encodedText[i];
        
        encodedText.remove(0,titleLength);
        
        m_converter.decode(encodedText, plainText);
        
        //printf ("decoded = |%s|\n", plainText.toAscii());
        
        editorBox->show();
        
        enableButtons (true);
        fileNewAct->setEnabled(true);
        fileOpenAct->setEnabled(true);
        
        if (editInsertSymbolAct->isChecked())
            symbolBox->show();
        
        // updates file's calculator title
        editorBox->setTitle(m_strTitle);
        
        // update recent file list
        QSettings settings;
        QStringList files = settings.value("recentFileList").toStringList();
        files.removeAll(m_strFilename);
        files.prepend(m_strFilename);
        while (files.size() > MaxRecentFiles)
            files.removeLast();

        settings.setValue("recentFileList", files);

        foreach (QWidget *widget, QApplication::topLevelWidgets()) {
            DlgMain*mainWin = qobject_cast<DlgMain *>(widget);
            if (mainWin)
                mainWin->updateRecentFileActions();
        }
        
        // update window title
        QString title;
        title = "HpCalc - ";
        title += strippedName(m_strFilename);
        setWindowTitle (title);
        
        QTextDocument* doc = new QTextDocument (plainText);
        textEditor->setDocument(doc);
        
        // update last dir
        QFileInfo fileInfo (m_strFilename);
        settings.setValue("lastDir", fileInfo.dir().path());
    }
    catch (QString& e)
    {
        if (dataBlock != NULL)
            delete dataBlock;
        
        file.close();
        
        throw e;
    }
    catch (...)
    {
        if (dataBlock != NULL)
            delete dataBlock;

        file.close();

        throw;
    }
}

void DlgMain::openRecentFile()
{
    if (!okToClear())
        return;

    try
    {
        QAction *action = qobject_cast<QAction *>(sender());
        if (action)
        {
            m_strFilename = action->data().toString();
            load();
        }
    }
    catch(QString &msg)
    {
        msg = "File Open abandoned\n" + msg;

        fileNewAct->setEnabled(true);
        fileOpenAct->setEnabled(true);
    }
    catch (...)
    {
        QMessageBox::critical (this, "Error", "General error");
    }
}

void DlgMain::fileOpen()
{
    if (!okToClear())
        return;
    
    // cleanup procedure
    enableButtons (false);
    fileNewAct->setEnabled(false);
    fileOpenAct->setEnabled(false);
    
    editorBox->hide();
    symbolBox->hide();
    m_strTitle = "";
    m_strFilename = "";
    
    QSettings settings;
    QString lastDir = settings.value("lastDir","").toString();
    
    QString filename = QFileDialog::getOpenFileName(
            this,
            "HpCalc -- File Open",
            lastDir,
            "Hp 39G Note (*.not *.NOT *.000);;All files (*.*)");
    try
    {
        if (filename.isEmpty())
            throw (QString ("You've specified an invalid filename"));
            
        if (!QFile::exists( filename ))
            throw (QString ("Selected filename doesn't exist!"));
        
        m_strFilename = filename;
        load();
    }
    catch (QString &msg)
    {
        msg = "File Open abandoned\n" + msg;
        QMessageBox::critical (this, "Error", msg);
        
        fileNewAct->setEnabled(true);
        fileOpenAct->setEnabled(true);
    }
    catch (...)
    {
        QMessageBox::critical (this, "Error", "General error");
    }
}

bool DlgMain::save()
{
    QString plainText, encodedText;
    
    QTextDocument *doc;
    
    doc = textEditor->document();
    
    if (doc == NULL)
        return false;
    
    plainText = doc->toPlainText();
    
    // hp39G file header
    encodedText  = "HP39AscC ";
    encodedText += QString::number(m_strTitle.length());
    encodedText += " ";
    encodedText += m_strTitle;

    m_converter.encode(plainText, encodedText);
    
    QFile file (m_strFilename);

    file.open (QIODevice::WriteOnly | QIODevice::Truncate);

    file.write (encodedText.toAscii(), encodedText.length());
    // TODO check write status

    file.close();

    //QMessageBox::information (this, "Encoded text", encodedText);
    
    return true;
}

void DlgMain::fileSave()
{
    if (m_strFilename.isEmpty())
        fileSaveAs();
    
    textEditor->document()->setModified(false);
    
    QString title;
    
    title = "HpCalc - ";
    title += strippedName(m_strFilename);
    
    setWindowTitle (title);
    
    save();
}

void DlgMain::fileSaveAs()
{
//     QString filename = QFileDialog::getSaveFileName(
//             QString::null, "Hp 39G (*.not *.NOT)", this,
//     "file save as", "HpCalc -- File Save As" );
    
    QString filename = QFileDialog::getSaveFileName(
            this,
            "HpCalc -- File Save As",
            QString(),
            "Hp 39G Note (*.not *.NOT)");

    
    if ( ! filename.isEmpty() ) {
        int ans = 0;

        //if needed adds .not extension
        QRegExp ext ( "(\\.not)$" );
        ext.setCaseSensitivity (Qt::CaseInsensitive);
        
        if (ext.indexIn(filename) == -1)
            filename+=".not"; // add extension

        if ( QFile::exists( filename ) )
            ans = QMessageBox::warning(
                    this, "HpCalc -- Overwrite File",
        QString( "Overwrite\n'%1'?" ).
                arg( filename ),
        "&Yes", "&No", QString::null, 1, 1 );
        if ( ans == 0 ) {
            m_strFilename = filename;
            fileSave();

            textEditor->document()->setModified(false);

            return;
        }
    }
}

void DlgMain::fileClose()
{
    if (! okToClear())
        return;
    
    enableButtons(false, true);
    textEditor->document()->clear();
    symbolBox->hide();
    editorBox->hide();
    m_strTitle = "";
    m_strFilename = "";
    
    setWindowTitle ("HpCalc");
}

void DlgMain::closeEvent (QCloseEvent *event)
{
    if (! okToClear())
        event->ignore();
    else
        event->accept();
}

void DlgMain::fileExit()
{
    if (! okToClear())
        return;
    
    close();
}

void DlgMain::filePrint()
{

}

void DlgMain::editUndo()
{
    QTextDocument *doc = NULL;
    
    doc = textEditor->document();
    
    if (doc!= NULL)
        doc->undo();
}

void DlgMain::undoEvent(bool status)
{
    editUndoAct->setEnabled(status);
}

void DlgMain::redoEvent(bool status)
{
    editRedoAct->setEnabled(status);
}

void DlgMain::copyEvent(bool available)
{
    editCopyAct->setEnabled(available);
    editCutAct->setEnabled(available);
}

void DlgMain::editRedo()
{
    QTextDocument *doc = NULL;
    
    doc = textEditor->document();
    
    if (doc!= NULL)
        doc->redo();
}

void DlgMain::editCut()
{
    textEditor->cut();
    editPasteAct->setEnabled(true);
}

void DlgMain::editCopy()
{
    textEditor->copy();
    editPasteAct->setEnabled(true);
}

void DlgMain::editPaste()
{
    textEditor->paste();
}

void DlgMain::editInsertSymbol(bool status)
{
    if (!status)
        symbolBox->hide();
    else
        symbolBox->show();
}

void DlgMain::about()
{
    QString message;

    message.sprintf("HpCalc version %i.%i<br><br>Created just for fun by Flavio Castelli: <a href=\"http://www.flavio.castelli.name\">http://www.flavio.castelli.name</a><br><br><hr>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.<br><br>You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.",VERSION_MAJOR, VERSION_MINOR);

    QMessageBox::about(this, tr("About HpCalc"), message);
}

void DlgMain::aboutQt()
{

}

QString DlgMain::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
