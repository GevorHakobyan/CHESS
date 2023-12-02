#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <string>
#include <memory>
#include <utility>

using AvailableCoordinates = std::vector<int>;
using CurrentLocation = std::pair<int, int>;
enum class Color{Black, White, Unknown};

class Piece {
    public:
    Piece() = default;
    Piece(std::string, const wchar_t*);
    virtual ~Piece();
    Piece(Piece& other) noexcept; 
    Piece(Piece&&) noexcept;
    Piece& operator=(Piece&) noexcept;
    Piece& operator=(Piece&&) noexcept;

    void setCurrentLocation(int, int);
    CurrentLocation getCurrentLocation() const;
    const wchar_t* getUnicodeCharacter() const;
    void setUnicodeCharacter(const wchar_t*);
    void setColor(const std::string&);
    std::string getColor() const;
    protected:
    //virtual void updateAvailableCoordinates();
    void SwapWithThis(Piece&);
    protected:
    CurrentLocation m_Current_Location{};
    AvailableCoordinates m_Avialble_Coordinates{};
    std::unique_ptr<const wchar_t*> m_unicodeCharacter{nullptr};
    Color m_color{Color::Unknown};
};
#endif