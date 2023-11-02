#ifndef USER_ACCOUNT_HPP
#define USER_ACCOUNT_HPP

#include <memory>
#include <ncurses.h>
#include <string>
#include <utility>
#include <vector>

//define standard size of Window
#define Y 18
#define X 82

//Type ALiases
using Password = std::pair<std::string, int>;
using Passwords = std::vector<Password>;

class User_Account
{
    public:
    User_Account(const Password password, const std::string& name, const std::string& surname);

    //setters
    void setName(const std::string& name, WINDOW* win = nullptr);
    void setSurname(const std::string& surnamey, WINDOW* win = nullptr);
    void setPassword(const Password password);

    //getters
    std::string getName() const;
    std::string getSurname() const;
    
    void showAccount(int&) const;
    void Edit();
    //helper methods
    public:
    void passwordRecovery();
    static bool passwordAuthentication(const std::string&, std::string&, WINDOW*);
    bool name_surname_Authentication(const std::string&, WINDOW*) const;
    void edit_Name_Surname();
    private:
    Password getPassword() const;
    static void addToPasswordList(const Password);

    private:
    WINDOW* m_accountWindow{nullptr};
    std::string m_name;
    std::string m_surname;
    Password m_password {"", 0};;
    static Passwords listOfPasswords;
};

#endif
