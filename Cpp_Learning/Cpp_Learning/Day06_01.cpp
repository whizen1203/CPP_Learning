#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    // 변수 : 내 로또번호, 컴퓨터 로또번호
    int myLotto[6];
    int comLotto[6];
    int count = 0;

    while (true)
    {
        cout << "내 로또 번호 입력 : ";

        //내 로또 번호 입력
        //cin >> myLotto[0] >> myLotto[1];
        for (int i = 0; i < 6; i++)
        {
            cin >> myLotto[i];
        }

        //컴퓨터 번호 추첨
        for (int i = 0; i < 6; i++)
        {
            //              0 ~ 44  -> 1 ~ 45
            comLotto[i] = rand() % 45 + 1;
        }

        //중복검출
        for (int i = 0; i < 6; i++)
        {
            //i 0 j X
            //i 1 j 0
            //i 2 j 0 1
            for (int j = 0; j < i; j++)
            {
                if (comLotto[i] == comLotto[j])
                {
                    cout << comLotto[i] << endl;
                    comLotto[i] = rand() % 45 + 1;
                    i--;
                }
            }
        }

        cout << "컴퓨터 로또 번호 : ";
        for (int i = 0; i < 6; i++)
        {
            cout << comLotto[i] << " ";
        }
        cout << endl;

        //두 개 비교
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (myLotto[i] == comLotto[j])
                {
                    count++;
                }
            }
        }

        //결과 출력
        cout << count << "개 맞췄다!" << endl;
        count = 0;
    }
}
