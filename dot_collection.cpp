#include "dot_collection.hpp"


// Constructor.
// TODO: Our offset logic only works with an odd number of rows or columns. Fix this later.
void DotCollection::init()
{
    // Initialize our dot collection, random between green and blue.
    int x_offset = DOT_SPACING * (DOT_GRID_ROWS / 2);
    int x = (SCREEN_WIDTH / 2) - x_offset;

    for (int r = 0; r < DOT_GRID_ROWS; r++) {
        int y_offset = DOT_SPACING * (DOT_GRID_COLS / 2);
        int y = (SCREEN_HEIGHT / 2) - y_offset;

        for (int c = 0; c < DOT_GRID_COLS; c++) {
            int rand_val = GetRandomValue(0, 1);
            Color color = rand_val == 0 ? GREEN : BLUE;
            m_dots[r][c].setColor(color);
            m_dots[r][c].setPos(x, y);
            y += DOT_SPACING;
        }

        x += DOT_SPACING;
    }

    // Now that we're done, pick a single one to be the red.
    int rand_row = GetRandomValue(0, DOT_GRID_ROWS);
    int rand_col = GetRandomValue(0, DOT_GRID_COLS);
    m_dots[rand_row][rand_col].setColor(RED);
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

