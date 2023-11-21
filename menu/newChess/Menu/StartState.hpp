#ifndef START_MENU_HPP
#define START_MENU_HPP

#include "State.hpp"
#include "UserAccount.hpp"
#include <string>

class StartState : public State {
    public:
    void signUp(const std::string& name, const std::string& surname, const Password& password);//optional
    void signIn(const Password& password);//optional
    bool blackOrWhite();
};
#endif