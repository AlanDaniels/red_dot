#include "dot_collection.hpp"


// Constructor.
// TODO: Our offset logic only works with an odd number of rows or columns. Fix this later.
void DotCollection::init()
{
    int x_offset = DOT_SPACING * (DOT_GRID_ROWS / 2);
    int x = (SCREEN_WIDTH / 2) - x_offset;

    for (int r = 0; r < DOT_GRID_ROWS; r++) {
        int y_offset = DOT_SPACING * (DOT_GRID_COLS / 2);
        int y = (SCREEN_HEIGHT / 2) - y_offset;

        for (int c = 0; c < DOT_GRID_COLS; c++) {
            m_dots[r][c].setColor(RED);
            m_dots[r][c].setPos(x, y);
            y += DOT_SPACING;
        }

        x += DOT_SPACING;
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

