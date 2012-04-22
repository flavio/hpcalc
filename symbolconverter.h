#ifndef SYMBOLCONVERTER_H
#define SYMBOLCONVERTER_H

/**
@author Flavio Castelli
*/

#include "symbol.h"
#include <vector>
// #include <QMap>
#include <QStringList>
// #include <QList>

class SymbolConverter
{
    public:
        SymbolConverter();
        ~SymbolConverter();
    
        QStringList getNames (Symbol::SymbolType type = Symbol::ALL);// { return m_conversionMap.keys();}
        
        void encode (QString plain, QString& encoded);
        void decode (QString encoded, QString& plain);
        
    private:
        // conversion map: key = symbol, value = hp39G rapresentation
//         QMap <QString, QString> m_conversionMap;
        
        std::vector<Symbol> m_symbols;
};

#endif
