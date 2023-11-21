#ifndef USER_ACCOUNT_HPP
#define USER_ACCOUNT_HPP

#include <string>
#include <optional>
#include <Menu.hpp>

//Aliases
using Password = std::pair<std::string, int>;

class UserAccount{
    public:
    void setName();
    std::string getname() const;
    void setPassword();
    Password getPassword() const;
    void showAccount();
    /*private:
    std::optional<UserAccount&> doesAccountExist(Password&);*/
    private:
    Password m_password{};
    std::string m_name{};
};
#endif