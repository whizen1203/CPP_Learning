#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    // ���� : �� �ζǹ�ȣ, ��ǻ�� �ζǹ�ȣ
    int myLotto[6];
    int comLotto[6];
    int count = 0;

    while (true)
    {
        cout << "�� �ζ� ��ȣ �Է� : ";

        //�� �ζ� ��ȣ �Է�
        //cin >> myLotto[0] >> myLotto[1];
        for (int i = 0; i < 6; i++)
        {
            cin >> myLotto[i];
        }

        //��ǻ�� ��ȣ ��÷
        for (int i = 0; i < 6; i++)
        {
            //              0 ~ 44  -> 1 ~ 45
            comLotto[i] = rand() % 45 + 1;
        }

        //�ߺ�����
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

        cout << "��ǻ�� �ζ� ��ȣ : ";
        for (int i = 0; i < 6; i++)
        {
            cout << comLotto[i] << " ";
        }
        cout << endl;

        //�� �� ��
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

        //��� ���
        cout << count << "�� �����!" << endl;
        count = 0;
    }
}
