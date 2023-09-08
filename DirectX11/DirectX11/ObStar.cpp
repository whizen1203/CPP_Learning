#include "framework.h"

ObStar::ObStar()
{
    vertex[0] = Vector2(0.5f * cosf(0.0f), 0.5f * sinf(0.0f));
    vertex[1] = Vector2(0.5f * cosf(72.0f * ToRadian), 
        0.5f * sinf(72.0f * ToRadian));
    vertex[2] = Vector2(0.5f * cosf(144.0f * ToRadian),
        0.5f * sinf(144.0f * ToRadian));
    vertex[3] = Vector2(0.5f * cosf(216.0f * ToRadian),
        0.5f * sinf(216.0f * ToRadian));
    vertex[4] = Vector2(0.5f * cosf(288.0f * ToRadian),
        0.5f * sinf(288.0f * ToRadian));
}

ObStar::~ObStar()
{
}

void ObStar::Render()
{
    GameObject::Render();

    Vector2 transf[5];
    for (int i = 0; i < 5; i++)
    {
        transf[i] = Vector2::Transform(vertex[i], W);
    }

    MoveToEx(g_MemDC, transf[0].x, transf[0].y, NULL);
    LineTo(g_MemDC, transf[2].x, transf[2].y);
    LineTo(g_MemDC, transf[4].x, transf[4].y);
    LineTo(g_MemDC, transf[1].x, transf[1].y);
    LineTo(g_MemDC, transf[3].x, transf[3].y);
    LineTo(g_MemDC, transf[0].x, transf[0].y);

}
