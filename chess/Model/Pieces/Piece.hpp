#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <string>
#include <memory>
#include <utility>

using Location = std::pair<int, int>;
using AvailableCoordinates = std::vector<Location>;

enum class Color{Black, White, Unknown};

class Piece {
    public:
    Piece() = default;
    Piece(const std::string&, const wchar_t*, Location);
    virtual ~Piece();
    Piece(Piece& other) noexcept; 
    Piece(Piece&&) noexcept;
    Piece& operator=(Piece&) noexcept;
    Piece& operator=(Piece&&) noexcept;  
    bool operator==(const Piece&);

    void setCurrentLocation(Location);
    Location getCurrentLocation() const;

    const wchar_t* getUnicodeCharacter() const;
    void setUnicodeCharacter(const wchar_t*);

    void setColor(const std::string&);
    Color getColor() const;
    virtual void updateAvailableCoordinates();
    virtual AvailableCoordinates getAvailableCoordinates() const; 
    protected:
   
    virtual void setAvailableCoordinates();
    void SwapWithThis(Piece&);
  

    protected:
    Location m_Current_Location{};
    AvailableCoordinates m_Avialble_Coordinates{};
    std::unique_ptr<const wchar_t*> m_unicodeCharacter{nullptr};
    Color m_color{Color::Unknown};
    //int a{0};
};
#endif