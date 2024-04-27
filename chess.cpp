#include <iostream>
#include "pieces.h"

using namespace std;

int main()
{
Knight knight;
Pawn pawn;
Rook rook;
King king;

int newX, newY;
char response;
bool working = true;

while(working)
{
    //welcome message with quit option
    cout << "Welcome to my Chess Game!" << endl;

    //prompt user to move knight
    cout << "Current Knight Pos: (" << knight.getX() << "," << knight.getY() << ")" << endl;
    cout << "Move Knight:  " << endl;
    cin >> newX >> newY;
    cin.ignore();

    if(Knight::withinBounds(newX, newY) && Knight::isCollision(newX, newY, pawn, rook, king) && knight.moveKnight(newX, newY))
    {
        cout << "Knight Move: " << endl;
        cout << "(" << knight.getX() << "," << knight.getY() << ")" << endl;
    }

    //prompt user to move rook
    cout << "Current Rook Pos: (" << rook.getX() << "," << rook.getY() << ")" << endl;
    cout << "Move Rook:  " << endl;
    cin >> newX >> newY;
    cin.ignore();

    if(Rook::withinBounds(newX, newY) && Rook::isCollision(newX, newY, pawn, knight, king) && rook.moveRook(newX, newY))
    {
        cout << "Rook Move: " << endl;
        cout << "(" << rook.getX() << "," << rook.getY() << ")" << endl;
    }

    //prompt user to move pawn
    cout << "Current Pawn Pos: (" << pawn.getX() << "," << pawn.getY() << ")" << endl;
    cout << "Move Pawn:  " << endl;
    cin >> newX >> newY;
    cin.ignore();

    if((Pawn::withinBounds(newX, newY)) && Pawn::isCollision(newX, newY, rook, knight, king) && (pawn.movePawn(newX, newY)))
    {
        cout << "Pawn Move: " << endl;
        cout << "(" << pawn.getX() << "," << pawn.getY() << ")" << endl;
    }

    //prompt user to move king
    cout << "Current King Pos: (" << king.getX() << "," << king.getY() << ")" << endl;
    cout << "Move King:  " << endl;
    cin >> newX >> newY;
    cin.ignore();

    if((King::withinBounds(newX, newY)) && King::isCollision(newX, newY, rook, knight, pawn) && (king.moveKing(newX, newY)))
    {
        cout << "King Move: " << endl;
        cout << "(" << king.getX() << "," << king.getY() << ")" << endl;
    }

    //quit prompt
    cout << "Would you like to continue playing? (y/n)" << endl;
    cin >> response;
    if(response=='n')
        working = false;

}

cout << "Thank you for playing!" << endl;

//end game
return 0;

}
