#include <windows.h>
#include <math.h>
#include <chrono>
#include <string>

#include "SimpleMath.h"
using namespace DirectX;
using namespace SimpleMath;

using namespace std;

#include "Type.h"
#include "Input.h"
#include "Timer.h"

#define ToRadian	0.0174533f
#define PI			3.1415926f
#define DIV2PI		1.5707963f
#define UP			Vector2(0, -1)
#define DOWN		Vector2(0, 1)
#define RIGHT		Vector2(1, 0)
#define LEFT		Vector2(-1, 0)

#define INPUT Input::GetInstance()
#define TIMER Timer::GetInstance()
#define DELTA Timer::GetInstance()->GetDeltaTime()

#include "GameObject.h"
#include "ObRect.h"
#include "ObCircle.h"
#include "ObStar.h"
#include "ObLine.h"

extern HDC g_hdc;
extern HDC g_MemDC;
extern HWND g_hwnd;