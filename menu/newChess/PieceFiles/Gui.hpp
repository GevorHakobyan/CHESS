#ifndef GUI_HPP
#define GUI_HPP

#include "BoardPrinter.hpp"
#include "PiecesPrinter.hpp"
//#include "MouseHandler.hpp"

class Gui{  
    public: 
    static Gui* getInstance();
    Gui& operator=(const Gui&) = delete;
    Gui(const Gui&) = delete;
    void Play(); 
    void drawBoard();
    private:
    Gui();
    private:
    static Gui* m_Gui;
};

#endif
