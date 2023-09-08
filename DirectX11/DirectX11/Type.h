#pragma once

//��ü ���� �� ����? ���� why? ���������Լ��� ���ǰ� �����ϱ�
class Scene //�߻�Ŭ���� �������̽� : ���������Լ��θ� �̷���� Ŭ����
{
public:
	virtual ~Scene() {};

	//�����Լ� : �ڽ��� ������ �� ���̶�� ���� �� ��
	//���� ���� �Լ�

	//�� �ʱ�ȭ
	virtual void Init() = 0;

	//�� ����
	virtual void Update() = 0;

	//�� ���
	virtual void Render() = 0;
};

template <typename T>
class Singleton
{
public:
    virtual ~Singleton() {};
    static T* GetInstance()
    {
        static T* Instance = new T;
        return Instance;
    };
    void DeleteSingleton()
    {
        delete GetInstance();
    };
};

static float DirToRadian(Vector2 Dir)
{
    //���� �������Ͱ� �ƴ϶��
    Dir.Normalize();
    return atan2f(Dir.y, Dir.x);
}