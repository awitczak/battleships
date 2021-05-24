/*
 *
 *  Created on: 09.05.2021
 * 
 */

#include "battlegroundGeneration.hpp"

using namespace std;

void BattlegroundGeneration::emptyBattlegroundInitialization()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            fieldData[i][j] = ' ';
            fieldData_enemy[i][j] = ' ';
        }
    }
}
void BattlegroundGeneration::dispBattleground(bool enemy_disp)
{
    if (enemy_disp)
    {
        cout << "    ";
        for (int i = 0; i < battlegroundSize; i++)
        {
            cout << coords_alpha[i] << "       ";
        }
        // enemy battleground
        cout << "\t\t";
        cout << "  ";
        for (int i = 0; i < battlegroundSize; i++)
        {
            cout << coords_alpha[i] << "       ";
        }
        //
        cout << endl;
        for (int i = 0; i < battlegroundSize; i++)
        {
            cout << "  ";
            for (int i = 0; i < battlegroundSize; i++)
            {
                cout << "+---+   ";
            }
            // enemy battleground
            cout << "\t\t";
            for (int i = 0; i < battlegroundSize; i++)
            {
                cout << "+---+   ";
            }
            // 
            cout << endl;
            cout << coords_num[i] << " ";
            for (int j = 0; j < battlegroundSize; j++)
            {
                cout << "| " << fieldData[i][j] << " |   ";
            }
            // enemy battleground
            cout << "\t      ";
            cout << coords_num[i] << " ";
            for (int j = 0; j < battlegroundSize; j++)
            {
                cout << "| " << fieldData_enemy[i][j] << " |   ";
            }
            // 
            cout << "  ";
            cout << endl;
            cout << "  ";
            for (int i = 0; i < battlegroundSize; i++)
            {
                cout << "+---+   ";
            }
            // enemy battleground
            cout << "\t\t";
            for (int i = 0; i < battlegroundSize; i++)
            {
                cout << "+---+   ";
            }
            //
            cout << endl;
        }
    }
    else
    {
        cout << "    ";
        for (int i = 0; i < battlegroundSize; i++)
        {
            cout << coords_alpha[i] << "       ";
        }
        cout << endl;
        for (int i = 0; i < battlegroundSize; i++)
        {
            cout << "  ";
            for (int i = 0; i < battlegroundSize; i++)
            {
                cout << "+---+   ";
            }
            cout << endl;
            cout << coords_num[i] << " ";
            for (int j = 0; j < battlegroundSize; j++)
            {
                cout << "| " << fieldData[i][j] << " |   ";
            }
            cout << "  ";
            cout << endl;
            cout << "  ";
            for (int i = 0; i < battlegroundSize; i++)
            {
                cout << "+---+   ";
            }
            cout << endl;
        }
    }
}