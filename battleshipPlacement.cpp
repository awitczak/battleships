#include "battleshipPlacement.hpp"

using namespace std;

void BattleshipPlacement::battleshipInit(int whichSide)
{
    // generating initial battleship count
    
    switch(whichSide)
    {
    // Empire	
    case 1:
    ships.shipLength2 = 0;
    ships.shipLength3 = 2;
    ships.shipLength4 = 3;
    ships.shipLength5 = 2;
    break;
    // Rebel	
    case 2:
    ships.shipLength2 = 5;
    ships.shipLength3 = 2;
    ships.shipLength4 = 2;
    ships.shipLength5 = 0;
    break;
    // CIS
    case 3:
    ships.shipLength2 = 1;
    ships.shipLength3 = 4;
    ships.shipLength4 = 0;
    ships.shipLength5 = 2;
    break;
    // Republic
    case 4: 
    ships.shipLength2 = 2;
    ships.shipLength3 = 2;
    ships.shipLength4 = 2;
    ships.shipLength5 = 1;
    break;
    default:
    ships.shipLength2 = 0;
    ships.shipLength3 = 0;
    ships.shipLength4 = 0;
    ships.shipLength5 = 0;
    cout << "Error, whichSide is equal to: " << whichSide << endl;
    system("pause");
    break;
    }
    shipAmount = ships.shipLength2 + ships.shipLength3 + ships.shipLength4 + ships.shipLength5;
}

void BattleshipPlacement::placeShip(int posY, int posX)
{
    fieldData[posX][posY] = 'O';
}

bool BattleshipPlacement::shipManager(int shipLength)
{
    switch (shipLength)
    {
    case 2:
        if (ships.shipLength2 != 0)
        {
            ships.shipLength2--;
            return true;
        }
        else
        {
            cout << "You have no more ships of such size!" << endl;
            return false;
        }
        break;
    case 3:
        if (ships.shipLength3 != 0)
        {
            ships.shipLength3--;
            return true;
        }
        else
        {
            cout << "You have no more ships of such size!" << endl;
            return false;
        }
        break;
    case 4:
        if (ships.shipLength4 != 0)
        {
            ships.shipLength4--;
            return true;
        }
        else
        {
            cout << "You have no more ships of such size!" << endl;
            return false;
        }
        break;
    case 5:
        if (ships.shipLength5 != 0)
        {
            ships.shipLength5--;
            return true;
        }
        else
        {
            cout << "You have no more ships of such size!" << endl;
            return false;
        }
        break;
    default:
        cout << "Wrong ship length!" << endl;
    }
}

void BattleshipPlacement::dispShipAmount()
{
    cout << "Remaining ships:" << endl;
    cout << "------------------------" << endl;
    cout << "Length:\t\tAmount:" << endl;
    cout << " 2 \t |\t " << ships.shipLength2 << endl;
    cout << " 3 \t |\t " << ships.shipLength3 << endl;
    cout << " 4 \t |\t " << ships.shipLength4 << endl;
    cout << " 5 \t |\t " << ships.shipLength5 << endl;
    cout << "------------------------" << endl;
}

bool BattleshipPlacement::checkFieldAvailability(string userChoice_start, string userChoice_end)
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
        cout << "Error! The size of the ship is not viable!" << endl;
        return false;
    }
    else
    {
        cout << "Ship length is equal to: " << shipLength << endl;

        // checking if the indicated fields are empty
        if ((tempX_start < tempX_end && tempY_start == tempY_end) || (tempX_start == tempX_end && tempY_start < tempY_end)) // prevents wrong direction
        {
            for (int i = 0; i < shipLength; i++)
            {
                if (abs(tempX_start - tempX_end != 0))
                {
                    // horizontal placement
                    if (fieldData[tempY_start][tempX_start + i] != ' ')
                    {
                        cout << "Error! One of the fields is already taken!" << endl;
                        return false;
                    }
                    else if (fieldData[tempX_start + i][tempY_start] == ' ')
                        orientation = false; // horizontal
                    correctFields = true;
                }
                if (abs(tempY_start - tempY_end != 0))
                {
                    // vertical placement
                    if (fieldData[tempY_start + i][tempX_start] != ' ')
                    {
                        cout << "Error! One of the fields is already taken!" << endl;
                        return false;
                    }
                    else if (fieldData[tempX_start][tempY_start + i] == ' ')
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
                system("pause");
                for (int i = 0; i < shipLength; i++)
                {
                    if (orientation)
                        placeShip(tempX_start, tempY_start + i);
                    else
                        placeShip(tempX_start + i, tempY_start);
                }
                return true;
            }
            else return false;
        }
        else
            return false;
    }
}

bool BattleshipPlacement::battleshipPlacement()
{
    string userChoice_start;
    string userChoice_end;
    bool properlyPlaced;

    cout << "Please choose the start and end coordinate of your battleship: " << endl;
    cout << "Enter the beginning: ";
    cin >> userChoice_start;
    cout << "Enter the end: ";
    cin >> userChoice_end;

    if (checkFieldAvailability(userChoice_start, userChoice_end))
    {
        cout << "Everything is fine! The ship has been placed on the chosen fields." << endl;
        properlyPlaced = true;
    }
    else
    {
        cout << "The ship can not be placed on the determined fields. Try again." << endl;
        system("pause");
        properlyPlaced = false;
    }
    if (properlyPlaced)
    {
        shipAmount--;
        if (shipAmount == 0)
            return true; // all ships deployed
    }
    return false;
}
