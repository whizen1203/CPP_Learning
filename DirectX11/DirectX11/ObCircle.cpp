#include "framework.h"

ObCircle::ObCircle()
{
    for (int i = 0; i < 360; i++)
    {
        vertex[i] = Vector2(0.5f * cosf(i * ToRadian), 
            0.5f * sinf(i * ToRadian));
    }
    
}

ObCircle::~ObCircle()
{
}

void ObCircle::Render()
{
    GameObject::Render();

    Vector2 transf[360];

    for (int i = 0; i < 360; i++)
    {
        transf[i] = Vector2::Transform(vertex[i], W);
    }

    MoveToEx(g_MemDC, transf[0].x, transf[0].y, NULL);

    for (int i = 1; i < 360; i++)
    {
        LineTo(g_MemDC, transf[i].x, transf[i].y);
    }

    LineTo(g_MemDC, transf[0].x, transf[0].y);

}
