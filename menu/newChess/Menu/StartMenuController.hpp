#ifndef START_MENU_HPP
#define START_MENU_HPP

#include "Controller.hpp"
#include "UserAccount.hpp"
#include <string>

class StartMenu : public Controller {
    public:
    void startGame();
    void signUp(const std::string& name, const std::string& surname, const Password& password);//optional
    void signIn(const Password& password);//optional
    void blackOrWhite(std::string& color);
};
#endif