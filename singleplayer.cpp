#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <time.h>

using namespace std;

// user headers includes
#include "battlegroundGeneration.cpp"
#include "battleshipPlacement.cpp"
#include "enemy.cpp"

void singleplayer()
{
    int whichSide = 0;
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    for (int i = 0; i < 10; i++)
    {
        cout << "\n";
    }
    for (int i = 0; i < 30; i++)
    {
        cout << " ";
    }
    cout << "Please pick a side to play (1. Empire 2. Rebellion 3. CIS 4. Republic)" << endl;
    cout << endl;
    for (int i = 0; i < 30; i++)
    {
        cout << " ";
    }
    cin >> whichSide;
    while (whichSide < 1 || whichSide > 4)
    {
        whichSide = 0;
        cout << endl;
        for (int i = 0; i < 30; i++)
        {
            cout << " ";
        }
        cout << "Please pick a correct side to play (1. Empire 2. Rebellion 3. CIS 4. Republic)" << endl;
        for (int i = 0; i < 30; i++)
        {
            cout << " ";
        }
        cin >> whichSide;
    }

    switch (whichSide)
    {
    case 1:
        //PlaySound(NULL, 0, 0);
        system("cls");
        //PlaySound(("Empire.wav"), NULL, SND_LOOP | SND_ASYNC);
        SetConsoleTextAttribute(hcon, 3);
        break;
    case 2:
        //PlaySound(NULL, 0, 0);
        system("cls");
        //PlaySound(("Rebel.wav"), NULL, SND_LOOP | SND_ASYNC);
        SetConsoleTextAttribute(hcon, 12);
        system("cls");
        break;
    default:
        cout << "No colour yet" << endl;
        Sleep(5000);
        break;
    }

    system("cls");
    bool all_placed = false;
    bool enemy_disp = false;
    BattleshipPlacement shipPlacement(whichSide);
    cout << endl;

    while (!all_placed)
    {
        shipPlacement.dispBattleground(enemy_disp);
        shipPlacement.dispShipAmount();
        if (shipPlacement.battleshipPlacement())
        {
            system("pause");
            system("cls");
            cout << "All ships have been deployed. Please prepare for the battle!" << endl;
            all_placed = true;
            enemy_disp = true;
            system("pause");
        }
        system("cls");
        cout << endl;
    }
    cout << "Your enemy has arrived!" << endl;
    shipPlacement.dispBattleground(enemy_disp);
}

int main()
{
    bool all_placed = false;
    srand(time(NULL));
    enemy enemyShips(rand() % 4 + 1);

    while (!all_placed)
    {   
        enemyShips.dispBattleground(true);
        enemyShips.dispShipAmount();
        if (enemyShips.battleshipPlacement())
        {
            system("pause");
            system("cls");
            cout << "All ships have been deployed. Please prepare for the battle!" << endl;
            all_placed = true;
            system("pause");
        }
        system("cls");
        cout << endl;
    }
    enemyShips.dispBattleground(true);

    return 0;
}
