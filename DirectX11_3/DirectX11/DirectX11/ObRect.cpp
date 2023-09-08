#include "framework.h"

ObRect::ObRect()
{
}

ObRect::~ObRect()
{
}

void ObRect::Render()
{
    MoveToEx(g_MemDC, position.x + 100 * cosf(0.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(0.0f * ToRadian + ratation) * scale.y, NULL);
    LineTo(g_MemDC, position.x + 100 * cosf(90.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(90.0f * ToRadian + ratation) * scale.y);
    LineTo(g_MemDC, position.x + 100 * cosf(180.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(180.0f * ToRadian + ratation) * scale.y);
    LineTo(g_MemDC, position.x + 100 * cosf(270.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(270.0f * ToRadian + ratation) * scale.y);
    LineTo(g_MemDC, position.x + 100 * cosf(0.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(0.0f * ToRadian + ratation) * scale.y);
}
