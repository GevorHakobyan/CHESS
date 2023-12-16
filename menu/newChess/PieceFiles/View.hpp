#ifndef VIEW_HPP
#define VIEW_HPP

#include "BoardPrinter.hpp"
#include "MouseHandler.hpp"

using UserInput = std::pair<Location, Location>;

class View{  
    public: 
    static View* getInstance(const PieceList&);
    View& operator=(const View&) = delete;
    View(const View&) = delete;
    void Play(); 
    void moveMapTo_Controller(Map&);
    void printBoardView();
    void updateBoardView(const wchar_t*, const wchar_t*, Location&, Location&);
    UserInput GetInput() const;
  
    private:    
    View(const PieceList&);
    private:
    MouseHandler* m_Mouse{nullptr};
    const PieceList& m_PieceList;
    static View* m_View;
    Map m_pieceMap{nullptr};
    UserInput m_UserInput;
};

#endif
