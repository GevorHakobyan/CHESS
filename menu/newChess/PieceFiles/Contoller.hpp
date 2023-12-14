#ifndef CHESS_CONTROLLER_HPP
#define CHESS_CONTROLLER_HPP

#include <Gui.hpp>
#include "Model.hpp"

class Controller {
    public:
    Controller();
    static void getInputFrom_User(Location&, Location&);

    private:
    static void UpdateBoard_Data(Location&, Location&);
    static void UpdateBoard_View();
    bool HasSucced();
    static Gui* m_Gui;
    static Model* m_Model;
};

#endif //CHESS_CONTROLLER_HPP