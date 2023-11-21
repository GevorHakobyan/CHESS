#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <Menu.hpp>

class State {
    public:
    virtual ~State();
    virtual void StartGame() = 0;
    virtual void Exit() = 0;
    void setMenu(Menu&);
    protected:
    std::unique_ptr<Menu> m_myMenu{nullptr};
};

#endif