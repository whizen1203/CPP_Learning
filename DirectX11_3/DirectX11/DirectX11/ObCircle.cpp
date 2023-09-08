#include "framework.h"

ObCircle::ObCircle()
{
}

ObCircle::~ObCircle()
{
}

void ObCircle::Render()
{

    MoveToEx(g_MemDC, position.x + 100 * cosf(0.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(0.0f * ToRadian + ratation) * scale.y, NULL);

    for (int i = 1; i < 360; i++)
    {
        LineTo(g_MemDC, position.x + 100 * cosf(i * ToRadian + ratation) * scale.x,
            position.y + 100 * sinf(i * ToRadian + ratation) * scale.y);
    }
    LineTo(g_MemDC, position.x + 100 * cosf(0.0f * ToRadian + ratation) * scale.x,
        position.y + 100 * sinf(0.0f * ToRadian + ratation) * scale.y);

}
