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
using Properties = std::vector<std::string>;

class User_Account
{
    public:
    User_Account(const Password& password, const std::string& name, const std::string& surname);

    //setters
    void setName(const std::string& name, WINDOW* win = nullptr);
    void setSurname(const std::string& surnamey, WINDOW* win = nullptr);
    void setPassword(const Password password);

    //getters
    std::string getName() const;
    std::string getSurname() const;
    
    void showAccount();
    void Edit();
    //helper methods
    public:
    void passwordRecovery();
    static bool passwordAuthentication(const std::string&, std::string&, WINDOW*);
    bool name_surname_Authentication(const std::string&, WINDOW*) const;
    void edit_Name_Surname(); 
    static void addToAccountList(const User_Account&);
    Password getPassword() const;
    static void findAccount(const Password&);
    void detectChoice(int);

    private:
    WINDOW* m_accountWindow{nullptr};
    std::string m_name;
    std::string m_surname;
    Password m_password {"", 0};
    Properties m_accountProperties{nullptr};
    static std::vector<std::pair<User_Account, Password>> m_listOfAccounts;
};

#endif
