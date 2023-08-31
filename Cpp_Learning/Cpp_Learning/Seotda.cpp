#include <iostream>
#include <time.h>
#include <string>
#include "Seotda.h"

using namespace std;

enum Jokbo
{
    KK_0,
    KK_9 = 9,
    SR,
    JS,
    JB,
    GB,
    DS,
    AL,
    DD_1 = 21,
    DD_10 = 30,
    KD
};

struct Card
{
    int     month;
    string  shape;
};

struct Player
{
    int     money;
    string  name;
    Card    card[2];
    int     jokbo;
};

void MakeJokbo(int size, Player* player)
{
    for (int i = 0; i < size; i++)
    {
        //��
        if (player[i].card[0].month == player[i].card[1].month)
        {
            player[i].jokbo = player[i].card[0].month + (DD_1 - 1);
        }
        else if (player[i].card[0].shape == "��" &&
            player[i].card[1].shape == "��") //����
        {
            player[i].jokbo = KD;
        }
        else //��, �߰�����
        {
            player[i].jokbo = KK_0 + (player[i].card[0].month + player[i].card[1].month) % 10;

            if (player[i].card[0].month == 1)
            {
                if (player[i].card[1].month == 2)
                {
                    player[i].jokbo = AL;
                }
                else if (player[i].card[1].month == 4)
                {
                    player[i].jokbo = DS;
                }
                else if (player[i].card[1].month == 9)
                {
                    player[i].jokbo = GB;
                }
                else if (player[i].card[1].month == 10)
                {
                    player[i].jokbo = JB;
                }
            }
            else if (player[i].card[0].month == 4)
            {
                if (player[i].card[1].month == 6)
                {
                    player[i].jokbo = SR;
                }
                else if (player[i].card[1].month == 10)
                {
                    player[i].jokbo = JS;
                }
            }
        }
    }
}

void Print(int size, Player* player)
{
    for (int i = 0; i < size; i++)
    {
        cout << player[i].name << "\t" <<
            player[i].card[0].month << player[i].card[0].shape << "\t" <<
            player[i].card[1].month << player[i].card[1].shape << "\t" <<
            player[i].money << "\t";

        if (player[i].jokbo == KD) //����
        {
            cout << player[i].card[0].month << player[i].card[1].month << "����" << endl;
        }
        else if (player[i].jokbo < DD_1) //��, �߰�����
        {
            if (player[i].jokbo == AL)
            {
                cout << "�˸�" << endl;
            }
            else if (player[i].jokbo == DS)
            {
                cout << "����" << endl;
            }
            else if (player[i].jokbo == GB)
            {
                cout << "����" << endl;
            }
            else if (player[i].jokbo == JB)
            {
                cout << "���" << endl;
            }
            else if (player[i].jokbo == JS)
            {
                cout << "���" << endl;
            }
            else if (player[i].jokbo == SR)
            {
                cout << "����" << endl;
            }
            else
                cout << player[i].jokbo << "��" << endl;
        }
        else //��
        {
            cout << (player[i].jokbo - 20) << "��" << endl;
        }
    }
}

void Swap(Card* deck, int sour, int dest)
{
    Card temp = deck[sour];
    deck[sour] = deck[dest];
    deck[dest] = temp;
}

void Shuffle(Card* deck)
{
    for (int i = 0; i < 1000; i++)
    {
        int sour = rand() % 20;
        int dest = rand() % 20;

        Swap(deck, sour, dest);
    }
}

int main()
{
    srand(time(NULL));

    int tableMoney = 0;
    int size;
    while (true)
    {
        cout << "�÷��̾� �� �Է� : "; cin >> size;

        if (size > 10 || size < 2)
        {
            cout << "�ٽ� �Է�" << endl;
            continue;
        }
        else
        {
            break;
        }
    }

    //�÷��̾� -> �̸� ī�� ��

    Player* player;
    player = new Player[size];

    for (int i = 0; i < size; i++)
    {
        cout << i << "�� ° �̸� : ";
        string temp;
        cin >> temp;
        //cin >> player[i].name;
        player[i].name = temp;
        player[i].money = 50000;
    }

    //�� �����
    Card deck[20];
    for (int i = 0; i < 20; i++)
    {
        deck[i].month = i % 10 + 1;
        deck[i].shape = "��";
    }
    deck[0].shape = deck[2].shape = deck[7].shape = "��";

    int start = 0;
    while (!start)
    {
        //����
        Shuffle(deck);
        tableMoney = 0;

        //�� �����ֱ�
        for (int i = 0; i < size; i++)
        {
            tableMoney += 1000;
            player[i].money -= 1000;
            player[i].card[0] = deck[i];
            player[i].card[1] = deck[i + 10];
            if (player[i].card[0].month > player[i].card[1].month)
            {
                Swap(player[i].card, 0, 1);
            }
        }

        //���� ����
        MakeJokbo(size, player);

        //���� 
        int max = KK_0;
        int winner;
        for (int i = 0; i < size; i++)
        {
            if (player[i].jokbo > max)
            {
                max = player[i].jokbo;
                winner = 1;
            }
            else if (player[i].jokbo == max)
            {
                winner++;
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (player[i].jokbo == max)
            {
                player[i].money += tableMoney / winner;
                cout << player[i].name << "\t";
            }
        }
        cout << "�¸�" << endl;

        //�� �����ֱ�

        //���
        Print(size, player);

        cout << "����Ϸ��� 0 -> "; cin >> start;
    }





    return 0;
}