#include "framework.h"

ObRect::ObRect()
{
    vertex[0] = Vector2(-0.5f, 0.5f);
    vertex[1] = Vector2(-0.5f, -0.5f);
    vertex[2] = Vector2(0.5f, -0.5f);
    vertex[3] = Vector2(0.5f, 0.5f);
}

ObRect::~ObRect()
{
}

void ObRect::Render()
{
    GameObject::Render();

    Vector2 TransFvertex[4];
    for (int i = 0; i < 4; i++)
    {
        TransFvertex[i] = Vector2::Transform(vertex[i] , W);
    }

    MoveToEx(g_MemDC, TransFvertex[0].x, TransFvertex[0].y, NULL);

    LineTo(g_MemDC, TransFvertex[1].x, TransFvertex[1].y);

    LineTo(g_MemDC, TransFvertex[2].x, TransFvertex[2].y);
    
    LineTo(g_MemDC, TransFvertex[3].x, TransFvertex[3].y);
    
    LineTo(g_MemDC, TransFvertex[0].x, TransFvertex[0].y);
}
