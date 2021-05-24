#include <iostream>
#include <string>
#include <windows.h>

#include "battleshipPlacement.hpp"

using namespace std;

class BattleshipPlacement;

class enemy : public BattleshipPlacement
{
public:
    string ship_start, ship_end;
    vector<string> past_ship_starts;
    const int coords_num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const string coords_alpha = "ABCDEFGHIJ";

    enemy(int whichSide)
    {
        battleshipInit(whichSide);
    };
    ~enemy(){};
    void placeShip(int posY, int posX)
    {
        fieldData_enemy[posX][posY] = 'O';
    }
    bool checkFieldAvailability(string userChoice_start, string userChoice_end)
    {
        int tempX_start;
        int tempY_start;
        int tempX_end;
        int tempY_end;
        int shipLength;
        bool orientation;
        bool correctFields;

        // initial coordinate
        tempX_start = (int)userChoice_start[0] - 65; // conversion so that we can have from 0 to 9
        tempY_start = (int)userChoice_start[1] - 48; // in the fieldData[x][x]
        // final coordinate
        tempX_end = (int)userChoice_end[0] - 65; // conversion so that we can have from 0 to 9
        tempY_end = (int)userChoice_end[1] - 48; // in the fieldData[x][x]

        // determining the chosen ship length
        if (abs(tempX_start - tempX_end) > abs(tempY_start - tempY_end))
        {
            shipLength = abs(tempX_start - tempX_end) + 1;
        }
        else
        {
            shipLength = abs(tempY_start - tempY_end) + 1;
        }

        // checking if the chosen ship length is viable
        if (shipLength == 0 || shipLength > 5)
        {
            cout << "THIS IS THE ERROR 1 _ _ _ Ship length is equal to: " << shipLength << endl;

            cout << "first coord: " << tempX_start << tempY_start << endl;
            cout << "second coord: " << tempX_end << tempY_end << endl;

            cout << "Error! The size of the ship is not viable!" << endl;
            return false;
        }
        else
        {
            cout << "THIS IS THE ERROR 2 _ _ _ Ship length is equal to: " << shipLength << endl;

            // checking if the indicated fields are empty
            if ((tempX_start < tempX_end && tempY_start == tempY_end) || (tempX_start == tempX_end && tempY_start < tempY_end)) // prevents wrong direction
            {
                for (int i = 0; i < shipLength; i++)
                {
                    if (abs(tempX_start - tempX_end != 0))
                    {
                        // horizontal placement
                        if (fieldData_enemy[tempY_start][tempX_start + i] != ' ')
                        {
                            cout << "Error! One of the fields is already taken!" << endl;
                            return false;
                        }
                        else if (fieldData_enemy[tempX_start + i][tempY_start] == ' ')
                            orientation = false; // horizontal
                        correctFields = true;
                    }
                    if (abs(tempY_start - tempY_end != 0))
                    {
                        // vertical placement
                        if (fieldData_enemy[tempY_start + i][tempX_start] != ' ')
                        {
                            cout << "Error! One of the fields is already taken!" << endl;
                            return false;
                        }
                        else if (fieldData_enemy[tempX_start][tempY_start + i] == ' ')
                            orientation = true; // vertical
                        correctFields = true;
                    }
                }
            }
            else
            {
                cout << "Wrong direction of ship placement!" << endl;
                return false;
            }

            if (correctFields)
            {
                if (shipManager(shipLength))
                {
                    for (int i = 0; i < shipLength; i++)
                    {
                        if (orientation)
                            placeShip(tempX_start, tempY_start + i);
                        else
                            placeShip(tempX_start + i, tempY_start);
                    }
                    return true;
                }
                else
                    return false;
            }
            else
                return false;
        }
    }
    bool choosingFields()
    {
        int temp_alpha = 0;
        int temp_num = 0;

        ship_start.clear();
        ship_end.clear();

        temp_alpha = rand() % 10;
        temp_num = rand() % 10;

        ship_start += coords_alpha[temp_alpha];
        ship_start += to_string(coords_num[temp_num]);

        int i = 0;
        // keeping track of the previous ship initial locations to save some time
        while (!past_ship_starts.empty())
        {
            if (past_ship_starts[i] == ship_start)
            {
                return false;
            }
            else
            {
                past_ship_starts.push_back(ship_start);
            }
        }
        // checking for ship amount
        if (shipAmount != 0)
        {
            // checking for ship length to generate the next coordinate
            if (ships.shipLength2 > 0)
            {
                // random number for horizontal/vertical ship placement
                if (rand() % 2 == 1) // horizontal
                {
                    if (temp_alpha == 9) // making sure if the direction is horizontal and the last letter is chosen,
                                         // the ship can not be placed, as there it exceeds the letter limit
                    {
                        ship_start.clear();
                        ship_end.clear();
                        return false;
                    }
                    else // if it is less than 10, the ship of length 2 can be placed
                    {
                        ship_end += coords_alpha[temp_alpha + 1];
                        ship_end += to_string(coords_num[temp_num]);
                    }
                }
                else // vertical
                {
                    if (temp_num == 9) // making sure if the direction is vertical and the last number is chosen,
                                       // the ship can not be placed, as there it exceeds the number limit
                    {
                        ship_start.clear();
                        ship_end.clear();
                        return false;
                    }
                    else // if it is less than 10, the ship of length 2 can be placed
                    {
                        ship_end += coords_alpha[temp_alpha];
                        ship_end += to_string(coords_num[temp_num + 1]);
                    }
                }
            }
            else if (ships.shipLength3 > 0)
            {
                // random number for horizontal/vertical ship placement
                if (rand() % 2 == 1) // horizontal
                {
                    if (temp_alpha >= 8) // making sure if the direction is horizontal and the last letter is chosen,
                                         // the ship can not be placed, as there it exceeds the letter limit
                    {
                        ship_start.clear();
                        ship_end.clear();
                        return false;
                    }
                    else // if it is less than 9, the ship of length 3 can be placed
                    {
                        ship_end += coords_alpha[temp_alpha + 2];
                        ship_end += to_string(coords_num[temp_num]);
                    }
                }
                else // vertical
                {
                    if (temp_num >= 8) // making sure if the direction is horizontal and the last number is chosen,
                                       // the ship can not be placed, as there it exceeds the number limit
                    {
                        ship_start.clear();
                        ship_end.clear();
                        return false;
                    }
                    else // if it is less than 9, the ship of length 3 can be placed
                    {
                        ship_end += coords_alpha[temp_alpha];
                        ship_end += to_string(coords_num[temp_num + 2]);
                    }
                }
            }
            else if (ships.shipLength4 > 0)
            {
                // random number for horizontal/vertical ship placement
                if (rand() % 2 == 1) // horizontal
                {
                    if (temp_alpha >= 7) // making sure if the direction is horizontal and the last letter is chosen,
                                         // the ship can not be placed, as there it exceeds the letter limit
                    {
                        ship_start.clear();
                        ship_end.clear();
                        return false;
                    }
                    else // if it is less than 8, the ship of length 4 can be placed
                    {
                        ship_end += coords_alpha[temp_alpha + 3];
                        ship_end += to_string(coords_num[temp_num]);
                    }
                }
                else // vertical
                {
                    if (temp_num >= 7) // making sure if the direction is vertical and the last number is chosen,
                                       // the ship can not be placed, as there it exceeds the number limit
                    {
                        ship_start.clear();
                        ship_end.clear();
                        return false;
                    }
                    else // if it is less than 8, the ship of length 4 can be placed
                    {
                        ship_end += coords_alpha[temp_alpha];
                        ship_end += to_string(coords_num[temp_num + 3]); // it is important to add the correct number here
                    }                                                    // shipLength - 1
                }
            }
            else if (ships.shipLength5 > 0)
            {
                // random number for horizontal/vertical ship placement
                if (rand() % 2 == 1) // horizontal
                {
                    if (temp_alpha >= 6) // making sure if the direction is horizontal and the last letter is chosen,
                                         // the ship can not be placed, as there it exceeds the letter limit
                    {
                        ship_start.clear();
                        ship_end.clear();
                        return false;
                    }
                    else // if it is less than 7, the ship of length 5 can be placed
                    {
                        ship_end += coords_alpha[temp_alpha + 4];
                        ship_end += to_string(coords_num[temp_num]);
                    }
                }
                else // vertical
                {
                    if (temp_num >= 6) // making sure if the direction is vertical and the last number is chosen,
                                       // the ship can not be placed, as there it exceeds the number limit
                        return false;
                    else // if it is less than 7, the ship of length 5 can be placed
                    {
                        ship_end += coords_alpha[temp_alpha];
                        ship_end += to_string(coords_num[temp_num + 4]); // it is important to add the correct number here
                    }                                                    // shipLength - 1
                }
            }
            // at this point we have the start and end of the enemy ship
            // and we can proceed with the ship placement
            return true;
        }
    }
    bool battleshipPlacement()
    {
        bool properlyPlaced;

        while (shipAmount != 0)
        {
            properlyPlaced = false;

            if (choosingFields())
            {
                cout << "first: " << ship_start << endl;
                cout << "second: " << ship_end << endl;
                system("pause");

                if (checkFieldAvailability(ship_start, ship_end))
                {
                    properlyPlaced = true;
                }
                else
                {
                    cout << "Error, the specified fields are invalid." << endl;
                    system("pause");
                    properlyPlaced = false;
                }
                if (properlyPlaced)
                {
                    shipAmount--;
                    if (shipAmount == 0)
                        return true; // all ships deployed
                }
            }
        }
        return false;
    }
};