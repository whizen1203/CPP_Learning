#include <iostream>

using namespace std;

int main()
{
    //���� <-> ���

    int input;
    int init = 100;

    cout << "����" << endl;
    cout << "���� ���ڴ� " << init << endl;

    cout << "���� ���ڸ� �Է����ּ��� : ";
    cin >> input;
    //init = init + input;
    //init += input;
    cout << "���� ���ڴ� " << (init += input) << endl;

    cout << "�� ���ڸ� �Է����ּ��� : ";
    cin >> input;
    //init = init - input;
    //init -= input;
    cout << "���� ���ڴ� " << (init -= input) << endl;

    cout << "���� ���ڸ� �Է����ּ��� : ";
    cin >> input;
    //init = init * input;
    //init *= input;
    cout << "���� ���ڴ� " << (init *= input) << endl;

    cout << "���� ���ڸ� �Է����ּ��� : ";
    cin >> input;
    //init = init / input;
    //init /= input;
    cout << "���� ���ڴ� " << (init /= input) << endl;

    int exit;
    cin >> exit;
}
