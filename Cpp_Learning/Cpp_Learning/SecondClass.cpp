//컴퓨터구조

/*
메모리? 데이터를 기억(저장) -> RAM

-속도차이-

주기억장치 -> 임의접근메모리
RAM(램) - 휘발성메모리
ROM(롬) - 비휘발성메모리

보조기억장치 -> 순차접근메모리
hdd ssd
*/

//컴파일과정
/*
-전처리기
주석제거, #지시자 처리
필요없는 애들은 삭제하고 필요한 애들은 넣고

컴파일러
중간단계 언어로 변역 - 어셈블리어

어셈블리어
어셈블리어 언어를 기계어로 변역

링커 링킹
묶어주는 거 - 여러 파일을 묶어서 연결하여 exe 로 만듬
*/

//오류
//컴파일 오류 에러 : 컴파일타임 오류. 번역중 오류
//런타임 오류 에러 : 번역은 되었지만 실행 중 오류

//x86 32bit
//x64 64bit

#include <iostream>

using namespace std;

int main()
{
    //선언 정의 호출

    //자료형(type) callname;
    int a; //변수 선언
    //int 4byte 정수형

    a = 10; //변수 정의
    a = 5; //값 변화

    cout << a << endl; //호출

    float b; //실수형 4byte
    b = 3.14f;
    cout << b << endl; //호출

    char c; //문자형 1byte
    c = 'a';

    bool d; //논리형 
    d = true; //true(1) false(0) 

    // = 대입연산자 L = R 
    //변수 <-> 상수 변하지 않는 값
    //0 1 2 3 4 5 6 ... 리터럴상수
    // ㅁ ㄱ ㄴ ... a b i d... 리터럴 문자
    //3 = a; XXXXXXXXXX

    a = 3 + 7;
    cout << a << endl; //호출
    cout << (a = 6 + 7) << endl;
    //연산자 우선순위

    cout << "Hello World!\n";

    int exit;
    cin >> exit;
    cout << exit << endl;
}

//변수 : 데이터를 저장할 수 있는 공간, 그릇
//할당 : 저장공간을 나눠서 내어주는 거

//bit < byte < kb < mb < gb < tb
//8bit -> 1byte
//byte -> 메모리 주소 단위
//주소 값이 있으려면 byte 단위

