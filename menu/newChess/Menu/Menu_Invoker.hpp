#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <memory>
#include "Controller.hpp"

using Options = std::vector<std::string>;
using MyController = std::unique_ptr<Controller>;

class MenuInvoker{
    public:
    MenuInvoker(Options& options, Controller&);
    Options m_options{nullptr};
    private:
    MyController m_controller{nullptr};
};
#endif