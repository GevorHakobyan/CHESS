#include <iostream>

int main() {

    // Print the character to the console
    std::string myString{"\u25A0"};
    for (int i = 0; i < 2; ++i) {
        std::cout << myString;
    }
    std::cout << "\n";
     for (int i = 0; i < 2; ++i) {
        std::cout << myString;
    }
    std::cout << "\n";
    return 0;
}
