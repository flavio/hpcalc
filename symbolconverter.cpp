#include "symbolconverter.h"

SymbolConverter::SymbolConverter()
{
    // init the conversion map
    Symbol specialSymbol;
    
    specialSymbol.setName(QString ("\\"));
    specialSymbol.setEncoding(QString("\\\\"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
    
    specialSymbol.setName(QString::fromUtf8  ("°"));
    specialSymbol.setEncoding(QString("\\^o"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
     
    
    specialSymbol.setName(QString::fromUtf8 ("£"));
    specialSymbol.setEncoding(QString ("\\163"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
//     
//     specialSymbol.setName(QString::fromUtf8 ("ì")); = QString ("\\236");
//     specialSymbol.setName(QString::fromUtf8 ("è")); = QString ("\\232");
//     specialSymbol.setName(QString::fromUtf8 ("ò")); = QString ("\\242");
    
    specialSymbol.setName(QString::fromUtf8 ("§"));
    specialSymbol.setEncoding(QString ("\\167"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
//     specialSymbol.setName(QString::fromUtf8 ("à")); = QString ("\\224");
//     specialSymbol.setName(QString::fromUtf8 ("ù")); = QString ("\\167");
    
    specialSymbol.setName(QString::fromUtf8 ("∫"));
    specialSymbol.setEncoding( QString ("\\.S"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName("<");
    specialSymbol.setEncoding(QString ("<"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(">");
    specialSymbol.setEncoding( QString (">"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName("=");
    specialSymbol.setEncoding(QString ("="));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("≤"));
    specialSymbol.setEncoding(QString ("\\<="));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("≥"));
    specialSymbol.setEncoding(QString ("\\>="));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("≠"));
    specialSymbol.setEncoding(QString ("\\=/"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("±"));
    specialSymbol.setEncoding( QString ("\\177"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("■"));
    specialSymbol.setEncoding( QString ("\\[);"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("α"));
    specialSymbol.setEncoding( QString ("\\Ga"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("β"));
    specialSymbol.setEncoding( QString ("\\Gb"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("γ"));
    specialSymbol.setEncoding( QString ("\\Gg"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("δ"));
    specialSymbol.setEncoding( QString ("\\Gd"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Δ"));
    specialSymbol.setEncoding( QString ("\\GD"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ε"));
    specialSymbol.setEncoding( QString ("\\Ge"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("η"));
    specialSymbol.setEncoding( QString ("\\Gn"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("θ"));
    specialSymbol.setEncoding( QString ("\\Gh"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("λ"));
    specialSymbol.setEncoding( QString ("\\Gl"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("μ"));
    specialSymbol.setEncoding( QString ("\\Gm"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("π"));
    specialSymbol.setEncoding( QString ("\\PI"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ρ"));
    specialSymbol.setEncoding( QString ("\\Gr"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("σ"));
    specialSymbol.setEncoding( QString ("\\Gs"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("τ"));
    specialSymbol.setEncoding( QString ("\\Gt"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    //specialSymbol.setName(QString::fromUtf8 ("φ")); = QString ("\\O/");
    
    specialSymbol.setName(QString::fromUtf8 ("∞"));
    specialSymbol.setEncoding( QString ("\\oo"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ω"));
    specialSymbol.setEncoding( QString ("\\Gw"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ω"));
    specialSymbol.setEncoding( QString ("\\GW"));
    specialSymbol.setType (Symbol::GREEK);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ì"));
    specialSymbol.setEncoding( QString ("\\236"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("è"));
    specialSymbol.setEncoding( QString ("\\232"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("é"));
    specialSymbol.setEncoding( QString ("\\233"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("à"));
    specialSymbol.setEncoding( QString ("\\224"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ù"));
    specialSymbol.setEncoding( QString ("\\249"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ò"));
    specialSymbol.setEncoding( QString ("\\242"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ç"));
    specialSymbol.setEncoding( QString ("\\231"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Á"));
    specialSymbol.setEncoding( QString ("\\193"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Â"));
    specialSymbol.setEncoding( QString ("\\194"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ã"));
    specialSymbol.setEncoding( QString ("\\195"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ä"));
    specialSymbol.setEncoding( QString ("\\196"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Å"));
    specialSymbol.setEncoding( QString ("\\197"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Æ"));
    specialSymbol.setEncoding( QString ("\\198"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("À"));
    specialSymbol.setEncoding( QString ("\\192"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ç"));
    specialSymbol.setEncoding( QString ("\\199"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("È"));
    specialSymbol.setEncoding( QString ("\\200"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("É"));
    specialSymbol.setEncoding( QString ("\\201"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ê"));
    specialSymbol.setEncoding( QString ("\\202"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ë"));
    specialSymbol.setEncoding( QString ("\\203"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ì"));
    specialSymbol.setEncoding( QString ("\\204"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Í"));
    specialSymbol.setEncoding( QString ("\\205"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Î"));
    specialSymbol.setEncoding( QString ("\\206"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ï"));
    specialSymbol.setEncoding( QString ("\\207"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ð"));
    specialSymbol.setEncoding( QString ("\\208"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ñ"));
    specialSymbol.setEncoding( QString ("\\209"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ò"));
    specialSymbol.setEncoding( QString ("\\210"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ó"));
    specialSymbol.setEncoding( QString ("\\211"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ô"));
    specialSymbol.setEncoding( QString ("\\212"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Õ"));
    specialSymbol.setEncoding( QString ("\\213"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ö"));
    specialSymbol.setEncoding( QString ("\\214"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("×"));
    specialSymbol.setEncoding( QString ("\\.x"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ø"));
    specialSymbol.setEncoding( QString ("\\O/"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ù"));
    specialSymbol.setEncoding( QString ("\\217"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ú"));
    specialSymbol.setEncoding( QString ("\\218"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Û"));
    specialSymbol.setEncoding( QString ("\\219"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ü"));
    specialSymbol.setEncoding( QString ("\\220"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Ý")); 
    specialSymbol.setEncoding( QString ("\\221"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("Þ"));
    specialSymbol.setEncoding( QString ("\\222"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("à"));
    specialSymbol.setEncoding( QString ("\\224"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("á"));
    specialSymbol.setEncoding( QString ("\\225"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("â"));
    specialSymbol.setEncoding( QString ("\\226"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ã"));
    specialSymbol.setEncoding( QString ("\\227"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ä"));
    specialSymbol.setEncoding( QString ("\\228"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("å"));
    specialSymbol.setEncoding( QString ("\\229"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("æ"));
    specialSymbol.setEncoding( QString ("\\230"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ç"));
    specialSymbol.setEncoding( QString ("\\231"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("è")); 
    specialSymbol.setEncoding( QString ("\\232"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("é")); 
    specialSymbol.setEncoding( QString ("\\233"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ê"));
    specialSymbol.setEncoding( QString ("\\234"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ë"));
    specialSymbol.setEncoding( QString ("\\235"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ì"));
    specialSymbol.setEncoding( QString ("\\236"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("í"));
    specialSymbol.setEncoding( QString ("\\237"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("î"));
    specialSymbol.setEncoding( QString ("\\238"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ï"));
    specialSymbol.setEncoding( QString ("\\239"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ð"));
    specialSymbol.setEncoding( QString ("\\240"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ñ"));
    specialSymbol.setEncoding( QString ("\\241"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ò"));
    specialSymbol.setEncoding( QString ("\\242"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ó"));
    specialSymbol.setEncoding( QString ("\\243"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ô"));
    specialSymbol.setEncoding( QString ("\\244"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("õ"));
    specialSymbol.setEncoding( QString ("\\245"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ö"));
    specialSymbol.setEncoding( QString ("\\246"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("÷"));
    specialSymbol.setEncoding( QString ("\\:-"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ø"));
    specialSymbol.setEncoding( QString ("\\248"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ù"));
    specialSymbol.setEncoding( QString ("\\249"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ú"));
    specialSymbol.setEncoding( QString ("\\250"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("û"));
    specialSymbol.setEncoding( QString ("\\251"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ü"));
    specialSymbol.setEncoding( QString ("\\252"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ý"));
    specialSymbol.setEncoding( QString ("\\253"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("þ"));
    specialSymbol.setEncoding( QString ("\\254"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("ÿ"));
    specialSymbol.setEncoding( QString ("\\255"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¹"));
    specialSymbol.setEncoding( QString ("\\185"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("²"));
    specialSymbol.setEncoding( QString ("\\178"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("³"));
    specialSymbol.setEncoding( QString ("\\179"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¼"));
    specialSymbol.setEncoding( QString ("\\188"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¾"));
    specialSymbol.setEncoding( QString ("\\190"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("½"));
    specialSymbol.setEncoding( QString ("\\189"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¢"));
    specialSymbol.setEncoding( QString ("\\162"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¤"));
    specialSymbol.setEncoding( QString ("\\164"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¥"));
    specialSymbol.setEncoding( QString ("\\165"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("«"));
    specialSymbol.setEncoding( QString ("\\<<"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("»"));
    specialSymbol.setEncoding( QString ("\\>>"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¿"));
    specialSymbol.setEncoding( QString ("\\191"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¡"));
    specialSymbol.setEncoding( QString ("\\161"));
    specialSymbol.setType (Symbol::FONT);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("∑"));
    specialSymbol.setEncoding( QString ("\\GS"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("√"));
    specialSymbol.setEncoding( QString ("\\v/"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¬"));
    specialSymbol.setEncoding( QString ("\\172"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("`"));
    specialSymbol.setEncoding( QString ("`"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("…"));
    specialSymbol.setEncoding( QString (QChar(0x1f)));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¸"));
    specialSymbol.setEncoding( QString ("\\184"));
    specialSymbol.setType (Symbol::OTHER);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("¯"));
    specialSymbol.setEncoding( QString ("\\175"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
    specialSymbol.setName(QString::fromUtf8 ("∂"));
    specialSymbol.setEncoding( QString ("\\.d"));
    specialSymbol.setType (Symbol::MATH);
    m_symbols.push_back(specialSymbol);
    
}


SymbolConverter::~SymbolConverter()
{
}

QStringList SymbolConverter::getNames (Symbol::SymbolType type)
{
    QStringList symbols;
    
    for (unsigned int i = 0; i < m_symbols.size(); i++)
        if ((m_symbols[i].getType() == type) || (type == Symbol::ALL))
            symbols.append(m_symbols[i].getName());
    
    return symbols;
}

void SymbolConverter::encode (QString plain, QString& encoded)
{
    //QList <QString> keys;
    //QList <QString>::iterator iter;
    std::vector<Symbol>::iterator iter;
    
    //keys = m_conversionMap.keys();
    
    for (iter = m_symbols.begin(); iter != m_symbols.end(); iter++)
        plain.replace((*iter).getName(), (*iter).getEncoding());
    
//     for (iter = keys.begin(); iter != keys.end(); iter++)
//         plain.replace(*iter, m_conversionMap[*iter]);
    
    encoded += plain;
}

void SymbolConverter::decode (QString encoded, QString& plain)
{
//     QList <QString> keys;
//     QList <QString>::iterator iter;
//     
//     keys = m_conversionMap.keys();
//     
//     for (iter = keys.begin(); iter != keys.end(); iter++)
//         encoded.replace(m_conversionMap[*iter],*iter);
    
    std::vector<Symbol>::iterator iter;
    for (iter = m_symbols.begin(); iter != m_symbols.end(); iter++)
        encoded.replace((*iter).getEncoding(),(*iter).getName());
    plain = encoded;
    
}
