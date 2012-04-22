#include "ui_MainForm.h"
#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QContextMenuEvent>

#include "symbolconverter.h"

#define VERSION_MAJOR 0
#define VERSION_MINOR 2

class QListWidgetItem;

class DlgMain : public QMainWindow, private Ui::MainForm
{
    Q_OBJECT

    public:
        DlgMain (QWidget *parent = 0);
        void init(const char* fileName = NULL);

    private slots:
        void fileNew();
        void fileOpen();
        void fileSave();
        void fileSaveAs();
        void fileClose();
        void fileExit();
        void filePrint();
        void editUndo();
        void openRecentFile();
        void undoEvent (bool status);
        void editRedo();
        void redoEvent (bool status);
        void editCut();
        void editCopy();
        void copyEvent(bool available);
        void editPaste();
        void editChangeTitle();
        void editInsertSymbol(bool status);
        void about();
        void aboutQt();
        void symbolTabChanged();
        void symbolClicked(QListWidgetItem* item);
        void textChangedEvent();
    
    protected:
        void contextMenuEvent(QContextMenuEvent *event);
        void closeEvent (QCloseEvent *event);
//         bool event (QEvent * e );

    private:
        void createActions();
        void createMenus();
        void createToolBars();
        void updateRecentFileActions();
        void setupSymbolTab();
        void enableButtons(bool enable, bool extended = false);
        QString strippedName(const QString &fullFileName);
        bool okToClear();
        bool save();
        void load();
        
        QMenu *fileMenu;
        QMenu *recentFilesMenu;
        QMenu *editMenu;
        QMenu *helpMenu;
        
        QToolBar *fileToolBar;
        QToolBar *editToolBar;
        
        QActionGroup *alignmentGroup;
        QAction *fileNewAct;
        QAction *fileOpenAct;
        QAction *fileSaveAct;
        QAction *fileSaveAsAct;
        QAction *filePrintAct;
        QAction *fileCloseAct;
        QAction *fileExitAct;
        QAction *editUndoAct;
        QAction *editRedoAct;
        QAction *editCutAct;
        QAction *editCopyAct;
        QAction *editPasteAct;
        QAction *editInsertSymbolAct;
        QAction *editChangeTitleAct;
        QAction *aboutAct;
        QAction *aboutQtAct;
        QAction *separatorAct;

        enum { MaxRecentFiles = 5 };
        QAction *recentFileActs[MaxRecentFiles];
        
        QString m_strTitle;
        SymbolConverter m_converter;
        QString m_strFilename;
        
//         int m_iPreviusSelectedTab;
//         int m_iPrevSymbolWidgetWidth;
//         bool m_bSymbolTabReduced;
};
