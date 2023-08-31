#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    123; // 리터럴 상수 ->고정된 값
    const int a = 10; //초기화가 필수
    //const -> 상수화
    //a = 11; XXXXX 상수는 변하지 않는 값

    //변수 : 컴퓨터 수, 내 숫자, 카운트, s b
    int user[3];
    int strike, ball;
    int count = strike = ball = 0;
    int input;

    //배열 초기화 방법
    int deck[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    /*for (int i = 0; i < 9; i++)
    {
        deck[i] = i + 1;
    }*/

    //셔플
    for (int i = 0; i < 1000; i++)
    {
        int sour = rand() % 9;
        int dest = rand() % 9;

        int temp = deck[sour];
        deck[sour] = deck[dest];
        deck[dest] = temp;
    }

    //컴퓨터 숫자 뽑아주기
 /*   com[0] = deck[0];
    com[1] = deck[1];
    com[2] = deck[2];*/

    int com[3] = { deck[0],deck[1], deck[2] };

    while (true)
    {
        strike = ball = 0;
        cout << com[0] << com[1] << com[2] << endl;

        //내 숫자 입력
        //cin >> user[0] >> user[1] >> user[2];
        cout << "세자리 숫자를 입력하세요(한번에) ";
        cin >> input;

        /*user[0] = input / 100;
        user[1] = input % 100 / 10;
        user[2] = input % 10;*/

        for (int i = 0; i < 3; i++)
        {
            user[2 - i] = input % 10;
            input /= 10;
        }

        //cout << user[0] << endl;
        //cout << user[1] << endl;
        //cout << user[2] << endl;

        //스트라이크 볼 체크
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (user[i] == com[j])
                {
                    //스트라이크
                    if (i == j)
                    {
                        strike++;
                    }
                    else
                    {
                        ball++;
                    }
                }
            }
        }

        cout << strike << "S" << ball << "B" << endl;

        //카운트 증가
        count++;

        //정답인가?
        if (strike == 3)
        {
            cout << "맞췄다!!!!" << endl;
            cout << count << "번 만에!!!!" << endl;

            break;

            //게임 계속
            //count = 0;
            //셔플
            /*for (int i = 0; i < 1000; i++)
            {
                int sour = rand() % 9;
                int dest = rand() % 9;

                int temp = deck[sour];
                deck[sour] = deck[dest];
                deck[dest] = temp;
            }

            com[0] = deck[0];
            com[1] = deck[1];
            com[2] = deck[2];*/
        }
    }

    int exit;
    cin >> exit;
}
