#include "framework.h"
#include "MainGame.h"

MainGame::~MainGame()
{
}

void MainGame::Init()
{
    //MemDc �޸𸮻��� dc�� �ϳ� �� �߰�
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //���� �ڵ�
    g_MemDC = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 800, 600);
    m_hOldBitmap = (HBITMAP)SelectObject(g_MemDC, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);

    rc.SetWorldPos(Vector2(400.0f, 300.0f));
    rc.scale = Vector2(100.0f, 100.0f);
    rc.isAxis = true;
    //rc.Update();

    cc[0].SetWorldPos(Vector2(400.0f, 300.0f));
    cc[0].scale = Vector2(100.0f, 100.0f);
    cc[0].isAxis = true;

    for (int i = 1; i < 5; i++)
    {
        cc[i].SetParentRT(cc[0]);
        cc[i].isAxis = true;
        cc[i].scale = Vector2(i * 10.0f, i * 10.0f);
    }
    cc[1].SetLocalPos(Vector2(70.0f, 70.0f));
    cc[2].SetLocalPos(Vector2(120.0f, 120.0f));
    cc[3].SetLocalPos(Vector2(-200.0f, -150.0f));
    cc[4].SetLocalPos(Vector2(-150.0f, 200.0f));
    
    //cc �θ�� rc ��
    //cc.SetParentRT(rc);
    //
    ////���ð������� �ٽ� �ٲ�
    //cc.SetLocalPos(Vector2(100.0f, 100.0f));
    //cc.scale = Vector2(100.0f, 100.0f);
    //cc.isAxis = true;
}

void MainGame::Update()
{
    // DELTA �� ������!
    if (INPUT->KeyPress(VK_UP))
    {
        //Local ���� world �� �θ�. UP ���� ��? �θ���
        //cc.MoveLocalPos(UP * 200.0f * DELTA);
        //cc.MoveWorldPos(-cc.GetDown() * 200.0f * DELTA);
       // cc.MoveWorldPos(UP * 200.0f * DELTA);
    }
    if (INPUT->KeyPress(VK_DOWN))
    {
        //cc.MoveLocalPos(DOWN * 200.0f * DELTA);
        //cc.MoveWorldPos(DOWN * 200.0f * DELTA);
    }
    if (INPUT->KeyPress(VK_LEFT))
    {
        //cc.MoveLocalPos(LEFT * 200.0f * DELTA);
        //cc.MoveWorldPos(LEFT * 200.0f * DELTA);
    } 
    if (INPUT->KeyPress(VK_RIGHT))
    {
        //cc.MoveLocalPos(RIGHT * 200.0f * DELTA);
        //cc.MoveWorldPos(RIGHT * 200.0f * DELTA);
    }

    /*if (INPUT->KeyPress('F'))
    {
        rc.position += Vector2(cosf(45.0f * ToRadian),
            sinf(45.0f * ToRadian)) * 300.0f * DELTA;
    }*/

    if (INPUT->KeyPress('Q'))
    {
        //rc.position.x += 3;
        cc[0].rotation += 120.0f * ToRadian * DELTA;
    }
    if (INPUT->KeyPress('E'))
    {
        //rc.position.x += 3;
        cc[0].rotation -= 120.0f * ToRadian * DELTA;
    }

    //if (INPUT->KeyPress('A'))
    //{
    //    //rc.position.x += 3;
    //    st.scale.x += 100.0f * DELTA;
    //    st.scale.y += 100.0f * DELTA;
    //}
    //if (INPUT->KeyPress('D'))
    //{
    //    //rc.position.x += 3;
    //    st.scale.x -= 100.0f * DELTA;
    //    st.scale.y -= 100.0f * DELTA;
    //}

    for (int i = 1; i < 5; i++)
    {
        cc[i].rotation += i * 60.0f * ToRadian * DELTA;
        cc[i].revolution += i * 60.0f * ToRadian * DELTA;
    }

    //rc.Update();
    //st.Update();
    for (int i = 0; i < 5; i++)
    {
        cc[i].Update();
    }
    

    //Ű�� ������ �� wm_paint �� �߻� ���Ѷ�
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    PAINTSTRUCT ps;
    //hdc-> ��ȭ��
    g_hdc = BeginPaint(g_hwnd, &ps);

    //������ ���
    PatBlt(g_MemDC, 0, 0, 800, 600, WHITENESS);

    string FPS = "FPS : " + to_string(TIMER->GetFPS());
    TextOutA(g_MemDC, 0, 0, FPS.c_str(), FPS.size());



    //rc.Render();
    //st.Render();
    for (int i = 0; i < 5; i++)
    {
        cc[i].Render();
    }


    //��� ���� g_MemDC���� g_hdc��
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}
