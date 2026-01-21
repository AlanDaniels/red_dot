#include "dot_collection.hpp"


// Constructor.
void DotCollection::init()
{
    for (int r = 0; r < DOT_GRID_ROWS; r++) {
        for (int c = 0; c < DOT_GRID_COLS; c++) {
            m_dots[r][c].setColor(RED);
            m_dots[r][c].setPos(500, 500);
        }
    }
}


void DotCollection::render() const
{
    for (int r = 0; r < DOT_GRID_ROWS; r++) {
        for (int c = 0; c < DOT_GRID_COLS; c++) {
            Color color = m_dots[r][c].getColor();
            Vector2 pos = m_dots[r][c].getPos();
            DrawCircle(pos.x, pos.y, DOT_RADIUS, color);
        }
    }
}

