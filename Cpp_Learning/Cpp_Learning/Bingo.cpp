//c++ 표준 라이브러리
#include <iostream>
#include <string>

//c 표준 라이브러리
#include <time.h>
#include <math.h>

using namespace std;

void Swap(int** bingo, int sour1, int sour2, int dest1, int dest2)
{
    int temp = bingo[sour1][sour2];
    bingo[sour1][sour2] = bingo[dest1][dest2];
    bingo[dest1][dest2] = temp;
}

void Shuffle(int** bingo, int size)
{
    for (int i = 0; i < 1000; i++)
    {
        int sour1 = rand() % size;
        int sour2 = rand() % size;
        int dest1 = rand() % size;
        int dest2 = rand() % size;

        Swap(bingo, sour1, sour2, dest1, dest2);
    }
}

void Print(int** bingo, int size)
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if (bingo[x][y] == -1)
                cout << "X" << "\t";
            else
                cout << bingo[x][y] << "\t";
        }
        cout << endl;
    }
}

bool Check(int** bingo, int size, int input)
{
    bool isChecking = false;

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if (bingo[x][y] == input)
            {
                bingo[x][y] = -1;
                isChecking = true;
            }
        }
    }

    if (!isChecking)
    {
        return false;
    }

    return true;
}

//sal
void Count(int** bingo, int size, __inout int& count)
{
    //가로    
    for (int y = 0; y < size; y++)
    {
        int countX = 0;
        for (int x = 0; x < size; x++)
        {
            if (bingo[x][y] == -1)
            {
                countX++;
            }
            if (countX == size)
            {
                count++;
            }
        }
    }

    //세로
    for (int x = 0; x < size; x++)
    {
        int countY = 0;
        for (int y = 0; y < size; y++)
        {
            if (bingo[x][y] == -1)
            {
                countY++;
            }
            if (countY == size)
            {
                count++;
            }
        }
    }

    //대각선
    int countZL = 0;
    int countZR = 0;
    for (int i = 0; i < size; i++)
    {
        if (bingo[i][i] == -1)
            countZL++;
        if (countZL == size)
            count++;

        if (bingo[i][(size - 1) - i] == -1)
            countZR++;
        if (countZR == size)
            count++;
    }
}

int main()
{
    srand(time(NULL));

    int input, size;
    int myCount = 0;
    int niCount = 0;
    int** myBingo;
    int** niBingo;

    cout << "입력 : ";
    cin >> size;

    //내 빙고판 할당
    myBingo = new int* [size];
    for (int i = 0; i < size; i++)
    {
        myBingo[i] = new int[size];
    }

    //니 빙고판 할당
    niBingo = new int* [size];
    for (int i = 0; i < size; i++)
    {
        niBingo[i] = new int[size];
    }

    //내 빙고판 초기화
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            myBingo[x][y] = y * size + x;
        }
    }

    //니 빙고판 초기화
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            niBingo[x][y] = y * size + x;
        }
    }

    Shuffle(myBingo, size);
    Shuffle(niBingo, size);

    while (myCount < 3)
    {
        //출력
        cout << "내 빙고" << endl;
        Print(myBingo, size);
        cout << "=========================================" << endl;
        Print(niBingo, size);
        cout << "컴퓨터 빙고" << endl;

        cout << "입력 -> "; cin >> input;

        if (input >= pow(size, 2) || input < 0)
        {
            cout << "범위잘못입력" << endl;
            continue;
        }

        //중복
        if (!Check(myBingo, size, input))
        {
            cout << "중복" << endl;
            continue;
        }

        if (!Check(niBingo, size, input))
        {
            cout << "중복" << endl;
            continue;
        }

        int com = -1;
        while (com == -1)
        {
            com = niBingo[rand() % size][rand() % size];
        }

        //중복
        if (!Check(myBingo, size, com))
        {
            cout << "중복" << endl;
            continue;
        }

        if (!Check(niBingo, size, com))
        {
            cout << "중복" << endl;
            continue;
        }

        myCount = 0;
        niCount = 0;

        //카운트
        Count(myBingo, size, myCount);
        Count(niBingo, size, niCount);

        cout << "내 빙고 카운트 : " << myCount << endl;
        cout << "니 빙고 카운트 : " << niCount << endl;
    }

    cout << "3빙고" << endl;

    return 0;
}