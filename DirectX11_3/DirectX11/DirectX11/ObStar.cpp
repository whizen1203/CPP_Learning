#include "framework.h"

ObStar::ObStar()
{
}

ObStar::~ObStar()
{
}

void ObStar::Render()
{

    MoveToEx(g_MemDC, position.x + 100 * cosf(0.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(0.0f * ToRadian + ratation) * scale.y, NULL);
    LineTo(g_MemDC, position.x + 100 * cosf(144.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(144.0f * ToRadian + ratation) * scale.y);
    LineTo(g_MemDC, position.x + 100 * cosf(288.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(288.0f * ToRadian + ratation) * scale.y);
    LineTo(g_MemDC, position.x + 100 * cosf(72.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(72.0f * ToRadian + ratation) * scale.y);
    LineTo(g_MemDC, position.x + 100 * cosf(216.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(216.0f * ToRadian + ratation) * scale.y);
    LineTo(g_MemDC, position.x + 100 * cosf(0.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(0.0f * ToRadian + ratation) * scale.y);

}
