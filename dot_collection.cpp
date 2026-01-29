#include <cmath>
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
    int rand_row = GetRandomValue(0, DOT_GRID_ROWS - 1);
    int rand_col = GetRandomValue(0, DOT_GRID_COLS - 1);
    m_dots[rand_row][rand_col].setColor(RED);
    m_which_is_red = Vector2(rand_row, rand_col);

    long now = GetCurrentTimeMsecs();
    m_lerp = std::make_unique<LinearLerp>(now, DOT_GROWTH_TIME_MSECS, DOT_BEGIN_RADIUS, DOT_END_RADIUS);
}


// Render all the dots on the screen.
void DotCollection::render() const
{
    long now = GetCurrentTimeMsecs();
    float radius = m_lerp->get(now);

    for (int r = 0; r < DOT_GRID_ROWS; r++) {
        for (int c = 0; c < DOT_GRID_COLS; c++) {
            Color color = m_dots[r][c].getColor();
            Vector2 pos = m_dots[r][c].getPos();
            DrawCircle(pos.x, pos.y, radius, color);
        }
    }
}


// Hit test against our one true dot.
bool DotCollection::hitTest(const Vector2 &pos) const
{
    long now = GetCurrentTimeMsecs();
    float radius = m_lerp->get(now);

    int row = m_which_is_red.x;
    int col = m_which_is_red.y;
    Vector2 target = m_dots[row][col].getPos();
    int x_diff = pos.x - target.x;
    int y_diff = pos.y - target.y;
    float distance = std::sqrt(std::pow(x_diff, 2) + pow(y_diff, 2));
    bool result = (distance <= radius);
    return result;
}


void DotCollection::pauseDotGrowth(long current_time_msecs) const
{
    m_lerp->pause(current_time_msecs);
}

void DotCollection::resumeDotGrowth(long current_time_msecs) const
{
    m_lerp->resume(current_time_msecs);
}
