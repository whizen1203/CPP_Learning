#pragma once
class Light : public Singleton<Light>
{
private:
    struct PointLight
    {
        Vector2 screenPos;      //��ũ����ǥ  //8
        float   radius;         //������ũ��  //12
        float   padding; //16
    };

    struct LightBuffer
    {
        PointLight  lights[10];
        Vector4     select;         //������۴� 16����Ʈ ���
        Color       outColor;       //���� �� ��
        Color       inColor;
    };

    ID3D11Buffer* lightBuffer;

public:
    LightBuffer light;

    Light();
    ~Light();

    void        Set();
    void        SetLightPos(Vector2 Wpos, int idx);
};

