#ifndef DOT_COLLECTION_HPP
#define DOT_COLLECTION_HPP

#include <array>
#include "raylib.h"
#include "constants.hpp"


class Dot {
public:
    Dot() : m_color(DARKGRAY), m_pos(0.0f, 0.0f) {};
    ~Dot() = default;

    void setColor(const Color &val) { m_color = val; }
    void setPos(int x, int y) { m_pos = Vector2(x, y); }

    Color getColor() const { return m_color; }
    Vector2 getPos() const { return m_pos; }

    // Disable coping and moving.
    Dot(const Dot &that) = delete;
    Dot(const Dot &&that) = delete;
    Dot& operator=(Dot const &that) = delete;
    Dot&& operator=(Dot const &&that) = delete;

private:
    Color m_color;
    Vector2 m_pos;
};


class DotCollection {
public:
    DotCollection() {};
    ~DotCollection() = default;
    void init();
    void render() const;

    // Disable copying.
    DotCollection(const DotCollection &that) = delete;
    DotCollection& operator=(const DotCollection& that) = delete;

private:
    std::array<std::array<Dot, DOT_GRID_ROWS>, DOT_GRID_COLS> m_dots;
};

#endif
