#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    123; // ���ͷ� ��� ->������ ��
    const int a = 10; //�ʱ�ȭ�� �ʼ�
    //const -> ���ȭ
    //a = 11; XXXXX ����� ������ �ʴ� ��

    //���� : ��ǻ�� ��, �� ����, ī��Ʈ, s b
    int user[3];
    int strike, ball;
    int count = strike = ball = 0;
    int input;

    //�迭 �ʱ�ȭ ���
    int deck[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    /*for (int i = 0; i < 9; i++)
    {
        deck[i] = i + 1;
    }*/

    //����
    for (int i = 0; i < 1000; i++)
    {
        int sour = rand() % 9;
        int dest = rand() % 9;

        int temp = deck[sour];
        deck[sour] = deck[dest];
        deck[dest] = temp;
    }

    //��ǻ�� ���� �̾��ֱ�
 /*   com[0] = deck[0];
    com[1] = deck[1];
    com[2] = deck[2];*/

    int com[3] = { deck[0],deck[1], deck[2] };

    while (true)
    {
        strike = ball = 0;
        cout << com[0] << com[1] << com[2] << endl;

        //�� ���� �Է�
        //cin >> user[0] >> user[1] >> user[2];
        cout << "���ڸ� ���ڸ� �Է��ϼ���(�ѹ���) ";
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

        //��Ʈ����ũ �� üũ
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (user[i] == com[j])
                {
                    //��Ʈ����ũ
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

        //ī��Ʈ ����
        count++;

        //�����ΰ�?
        if (strike == 3)
        {
            cout << "�����!!!!" << endl;
            cout << count << "�� ����!!!!" << endl;

            break;

            //���� ���
            //count = 0;
            //����
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
