#include <iostream>

using namespace std;

int main()
{
    //변수 <-> 상수

    int input;
    int init = 100;

    cout << "계산기" << endl;
    cout << "현재 숫자는 " << init << endl;

    cout << "더할 숫자를 입력해주세요 : ";
    cin >> input;
    //init = init + input;
    //init += input;
    cout << "현재 숫자는 " << (init += input) << endl;

    cout << "뺄 숫자를 입력해주세요 : ";
    cin >> input;
    //init = init - input;
    //init -= input;
    cout << "현재 숫자는 " << (init -= input) << endl;

    cout << "곱할 숫자를 입력해주세요 : ";
    cin >> input;
    //init = init * input;
    //init *= input;
    cout << "현재 숫자는 " << (init *= input) << endl;

    cout << "나눌 숫자를 입력해주세요 : ";
    cin >> input;
    //init = init / input;
    //init /= input;
    cout << "현재 숫자는 " << (init /= input) << endl;

    int exit;
    cin >> exit;
}
