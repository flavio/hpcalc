//
// C++ Interface: symbol
//
// Description: 
//
//
// Author: Flavio Castelli <micron@madlab.it>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef SYMBOL_H
#define SYMBOL_H

#include <QString>

/**
@author Flavio Castelli
*/

class Symbol{
    public:
        enum SymbolType {GREEK, MATH, OTHER, FONT, ALL};
        
        Symbol() {};
        Symbol (QString name, QString encoding);
        
        QString getName() { return m_strName;}
        QString getEncoding() { return m_strEncoding;}
        SymbolType getType() { return m_type;}
        
        void setName(QString name)         { m_strName = name;}
        void setEncoding(QString encoding) { m_strEncoding = encoding;}
        void setType (SymbolType type)     { m_type = type;}
        
    private:
        QString m_strName;
        QString m_strEncoding;
        SymbolType m_type;
        
};

#endif
