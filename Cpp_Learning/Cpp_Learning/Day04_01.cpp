#include <iostream>

using namespace std;


int main()
{
    int count = 5; //���� ����
    int input = 0;
    int answer = 486;

    cout << "���ڸ� ���߽ʽÿ�" << endl;

    //          1   &&  1
    while (count > 0 && input != answer)
    {
        //���������� ++ --
        //�������������� X++
        //�������������� ++X

        cout << "����Ƚ�� : " << count-- << endl;

        cin >> input;

        if (input > answer)
        {
            cout << "���� �� Ů�ϴ�" << endl;
        }
        else if (input < answer)
        {
            cout << "���� �۽��ϴ�" << endl;
        }
        else //if (input == answer)
        {
            cout << "���� �����ϴ�" << endl;
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


