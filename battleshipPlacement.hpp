#ifndef BATTLESHIP_PLACEMENT_HPP
#define BATTLESHIP_PLACEMENT_HPP

#include <iostream>
#include <string>
#include <windows.h>

#include "battlegroundGeneration.hpp"

class BattlegroundGeneration;
class BattleshipPlacement : public BattlegroundGeneration
{
public:
    int shipAmount;
    struct battleshipDispenser
    {
        int shipLength2;
        int shipLength3;
        int shipLength4;
        int shipLength5;
    };

    battleshipDispenser ships;
    void battleshipInit(int whichSide); // creates the struct with ships
    bool checkFieldAvailability(std::string userChoice_start, std::string userChoice_end); // checks if chosen fields are available
    bool battleshipPlacement(); // responsible for user input/output and general ship placement
    void placeShip(int posX, int posY); // updating the fieldData variable
    void dispShipAmount(); // display the remaining ships
    bool shipManager(int shipLength);
    BattleshipPlacement(int whichSide)
    {
        battleshipInit(whichSide);
    };
    BattleshipPlacement() = default;
    ~BattleshipPlacement(){};
};

#endif