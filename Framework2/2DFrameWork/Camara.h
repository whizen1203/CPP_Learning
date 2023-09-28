#pragma once
class Camera : public Singleton<Camera>
{
private:
    Viewport            viewport;
    Matrix              V, P, VP;

public:
    //ī�޶���ġ
    Vector2             position;

public:
    Camera();
    void          Set();
    void          ResizeScreen();
    const Matrix& GetP() { return P; };
    const Matrix& GetVP() { return VP; };
};