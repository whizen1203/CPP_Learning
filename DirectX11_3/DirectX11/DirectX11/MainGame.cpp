#include "framework.h"
#include "MainGame.h"

MainGame::~MainGame()
{
    KillTimer(g_hwnd, NULL);
}

void MainGame::Init()
{
    //MemDc 메모리상의 dc를 하나 더 추가
    HBITMAP	 m_hOldBitmap, m_hBitmap;
    HDC	hdc = GetDC(g_hwnd); //기존 핸들
    g_MemDC = CreateCompatibleDC(hdc);
    m_hBitmap = CreateCompatibleBitmap(hdc, 800, 600);
    m_hOldBitmap = (HBITMAP)SelectObject(g_MemDC, m_hBitmap);
    ReleaseDC(g_hwnd, hdc);

    rc.position = Vector2(400.0f, 300.0f);
    st.position = Vector2(200.0f, 300.0f);
    cc.position = Vector2(600.0f, 300.0f);

    //WM_TIMER 메세지를 일정주기마다 발생
   //                  10 밀리초마다
    SetTimer(g_hwnd, 1, 10, NULL);
}

void MainGame::Update()
{
    //GetAsyncKeyState 메시지 큐를 거치지 않고 키입력 받아오는 함수
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


    //키가 눌렸을 때 wm_paint 를 발생 시켜라
    InvalidateRect(g_hwnd, NULL, false);
}

void MainGame::Render()
{
    PAINTSTRUCT ps;
    //hdc-> 도화지
    g_hdc = BeginPaint(g_hwnd, &ps);

    //바탕색 깔기
    PatBlt(g_MemDC, 0, 0, 800, 600, WHITENESS);
 
    rc.Render();
    st.Render();
    cc.Render();

    //고속 복사 g_MemDC에서 g_hdc로
    BitBlt(g_hdc, 0, 0, 800, 600, g_MemDC, 0, 0, SRCCOPY);

    EndPaint(g_hwnd, &ps);
}
