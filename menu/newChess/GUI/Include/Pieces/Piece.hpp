#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <string>
#include <memory>
#include <utility>

using AvailableCoordinates = std::vector<int>;
using CurrentCoordinates = std::pair<int, int>;

class Piece {
    public:
    Piece() = default;
    Piece(std::string, const wchar_t*);
    Piece(Piece& other);
    virtual ~Piece();
    virtual Piece& operator=(Piece&) = default;
    //virtual void move() = 0;
    void setCoordinates(int, int);
    const wchar_t* getUnicodeCharacter() const;
    void setUnicodeCharacter(std::string, const wchar_t*);
    protected:
    CurrentCoordinates m_Current_Coordinates;
    AvailableCoordinates m_Avialble_Coordinates{};
    std::unique_ptr<const wchar_t*> m_unicodeCharacter{nullptr};
};

#endif