#ifndef USER_ACCOUNT_HPP
#define USER_ACCOUNT_HPP

#include <ncurses.h>
#include <string>
#include <utility>
#include <vector>


//Type ALiases
using Password = std::pair<std::string, int>;

class User_Account
{
    public:
    User_Account(const Password password, const std::string& name, const std::string& surname, WINDOW* win1);
    //setters
    void setName(const std::string& namei, WINDOW* win1);
    void setSurname(const std::string& surname, WINDOW* win1);
    void setPassword(const Password password);

    //getters
    std::string getName() const;
    std::string getSurname() const;
    
    //other utilities
    void passwordRecovery();
    static bool passwordAuthentication(const std::string&, std::string&, WINDOW*);
    bool name_surname_Authentication(const std::string&, WINDOW*) const;
    //Account
    void showAccount(int&) const;
    void edit_Name_Surname(WINDOW*);
    private:
    Password getPassword() const;
    static void addToPasswordList(const Password);

    private:
    std::string m_name;
    std::string m_surname;
    Password m_password;
    static std::vector<Password> listOfPasswords;
};

#endif
