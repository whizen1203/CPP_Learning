#include <iostream>

using namespace std;


int main()
{
    int count = 5; //선언 정의
    int input = 0;
    int answer = 486;

    cout << "숫자를 맞추십시오" << endl;

    //          1   &&  1
    while (count > 0 && input != answer)
    {
        //증감연산자 ++ --
        //후위증감연산자 X++
        //전위증감연산자 ++X

        cout << "남은횟수 : " << count-- << endl;

        cin >> input;

        if (input > answer)
        {
            cout << "값이 더 큽니다" << endl;
        }
        else if (input < answer)
        {
            cout << "값이 작습니다" << endl;
        }
        else //if (input == answer)
        {
            cout << "값이 같습니다" << endl;
            //count = 0;
        }
        //count = count - 1;
        //count -= 1;
    }

    if (count == 0)
    {
        cout << "Game Over" << endl;
    }

}


