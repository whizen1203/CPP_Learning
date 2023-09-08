#include "framework.h"
#include "MainGame.h"

MainGame::~MainGame()
{
    KillTimer(g_hwnd, NULL);
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

    rc.position = Vector2(400.0f, 300.0f);
    st.position = Vector2(200.0f, 300.0f);
    cc.position = Vector2(600.0f, 300.0f);

    //WM_TIMER �޼����� �����ֱ⸶�� �߻�
   //                  10 �и��ʸ���
    SetTimer(g_hwnd, 1, 10, NULL);
}

void MainGame::Update()
{
    //GetAsyncKeyState �޽��� ť�� ��ġ�� �ʰ� Ű�Է� �޾ƿ��� �Լ�
    if (GetAsyncKeyState(VK_UP))
    {
        rc.position.y -= 3;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        rc.position.y += 3;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        rc.position.x -= 3;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        rc.position.x += 3;
    }
    if (GetAsyncKeyState('1'))
    {
        rc.scale.x += 0.1f;
    }
    if (GetAsyncKeyState('2'))
    {
        rc.scale.x -= 0.1f;
    }
    if (GetAsyncKeyState('3'))
    {
        rc.scale.y += 0.1f;
    }
    if (GetAsyncKeyState('4'))
    {
        rc.scale.y -= 0.1f;
    }
    if (GetAsyncKeyState('5'))
    {
        rc.ratation -= 0.1f;
    }
    if (GetAsyncKeyState('6'))
    {
        rc.ratation += 0.1f;
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
 
    rc.Render();
    st.Render();
    cc.Render();

    //��� ���� g_MemDC���� g_hdc��
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}
