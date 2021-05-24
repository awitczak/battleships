/*
 *
 *  Created on: 09.05.2021
 * 
 */

#ifndef BATTLEGROUNG_GENERATION_HPP
#define BATTLEGROUNG_GENERATION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

class BattlegroundGeneration
{
public:
    char fieldData[10][10];
    char fieldData_enemy[10][10];
    const int battlegroundSize = 10;
    const int coords_num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const string coords_alpha = "ABCDEFGHIJ";

    void emptyBattlegroundInitialization();
    void dispBattleground(bool enemy_disp);
    BattlegroundGeneration()
    {
        emptyBattlegroundInitialization();
    };
    ~BattlegroundGeneration(){};
};
#endif