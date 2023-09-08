#include "framework.h"

ObLine::ObLine()
{
    vertex[0] = Vector2(0.0f, 0.0f);
    vertex[1] = Vector2(1.0f, 0.0f);
}

ObLine::~ObLine()
{
}

void ObLine::Render()
{
    Vector2 transF[2];
    for (int i = 0; i < 2; i++)
    {
        transF[i] = Vector2::Transform(vertex[i], W);
    }

    MoveToEx(g_MemDC, transF[0].x, transF[0].y, NULL);
    LineTo(g_MemDC, transF[1].x, transF[1].y);
}
