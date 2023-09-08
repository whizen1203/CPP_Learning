#pragma once

//객체 만들 수 있음? ㄴㄴ why? 순수가상함수는 정의가 없으니까
class Scene //추상클래스 인터페이스 : 순수가상함수로만 이루어진 클래스
{
public:
	virtual ~Scene() {};

	//가상함수 : 자식이 재정의 할 것이라고 예상 될 때
	//순수 가상 함수

	//씬 초기화
	virtual void Init() = 0;

	//씬 갱신
	virtual void Update() = 0;

	//씬 출력
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
    //만약 단위벡터가 아니라면
    Dir.Normalize();
    return atan2f(Dir.y, Dir.x);
}