#include <iostream>
#include <time.h>

using namespace std;

#if 1
int main()
{
    srand(time(NULL));

    //���� : ���� �Է�, ��ǻ�Ͱ� �Է�
    int user, com;
    com = 0;

    while (true)
    {
        cout << "����(0) ����(1) ��(2) : ";
        cin >> user;
        com = rand() % 3;

        //�̱�
        //�� : 0 1 2
        //�� : 2 0 1

        //��
        //�� : 0 1 2
        //�� : 1 2 0

        //�º�
        if (user == com)
        {
            cout << "�����ϴ�" << endl;
        }
        else if ((user - com) == 1)
        {
            cout << "�̱�" << endl;
        }
        //else if ((user - com) == -2)
        else if ((user == 0) && (com == 2))
        {
            cout << "�̱�" << endl;
        }
        else
        {
            cout << "����" << endl;
        }

        cout << "Player : " << user << endl;
        cout << "Computer : " << com << endl;
        cout << "==========================" << endl;

        /*com++;
        if (com == 3)
        {
            com = 0;
        }*/
    }
}

#endif


#if 1 //���� ����
int main()
{
    srand(time(NULL));

    // ������������ %
    cout << 5 / 2 << endl;; //��

    cout << 5 % 2 << endl;
    cout << 10 % 3 << endl;
    cout << 10 % 2 << endl;
    cout << 1000000 % 2 << endl;
    cout << 1044444444 % 2 << endl;
    cout << 50505050505050 % 2 << endl;
    cout << 111111111111 % 2 << endl;
    cout << 333333333333 % 2 << endl;

    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;

    cout << rand() << endl; //����
    cout << rand() << endl; //����
    cout << rand() << endl; //����
    cout << rand() << endl; //����
    cout << rand() << endl; //����

    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;

    // number % A(��������) -> 0 ~ (A - 1)

    // 0 ~ 10
    cout << rand() % 11 << endl;

    // 10 ~ 20   rand() % 11 -> 0 ~ 10 +10 -> 10 ~ 20
    cout << rand() % 11 + 10 << endl;

    //0 2 4 6   rand() % 4 -> 0 1 2 3 -> 0 2 4 6
    cout << rand() % 4 * 2 << endl;

    //3 6 9         0 1 2 -> 1 2 3
    cout << (rand() % 3 + 1) * 3 << endl;
}
#endif
