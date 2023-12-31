#pragma once
class Input : public Singleton<Input>
{
private:
    unsigned char keyState[256];//현재상태
    unsigned char keyOldState[256];//저번업데이트상태
    unsigned char keyMap[256];

    //익명 enum문
    enum
    {
        KEY_INPUT_STATUS_DOWN,
        KEY_INPUT_STATUS_PRESS,
        KEY_INPUT_STATUS_NONE,
        KEY_INPUT_STATUS_UP
    };

public:
    Input();
    ~Input();

    bool KeyDown(int KeyCode); //눌렀을때 최초1회
    bool KeyPress(int KeyCode);//누르고있을때
    bool KeyUp(int KeyCode); //눌렀다가 떼었을때 최초1회

    void Update();
};

