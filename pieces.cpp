//
// Created by Charlie Lakis on 1/20/24.
//
#include <iostream>
#include <cmath>
#include "pieces.h"
using namespace std;

//default constructor declaration
Knight::Knight()
{
    x = 3;
    y = 0;
}

int Knight::getX() const
{
    return x;
}

int Knight::getY() const
{
    return y;
}

bool Knight::moveKnight(int newX, int newY)
{
    //move validator for knight
    if((abs(newX-x) == 2 && abs(newY-y) == 1))
    {
        x = newX;
        y = newY;
        return true;
    }
    else
    {
        cout << "Invalid Knight Move..." << endl;
        return false;
    }
}

bool Knight::withinBounds(int newX, int newY)
{
    //checks 10x10 cartesian board boundaries
    if(newX<0 || newX>10 || newY<0 || newY>=10)
    {
            cout << "Invalid Knight Move..." << endl;
            return false;
    }
    return(true);
}

bool Knight::isCollision(int newX, int newY, const Pawn &p, const Rook &r, const King &k)
{
    //simply put, if any of the objects share the same cord, user will be given a collision error.
    if((p.getX()==newX) && (p.getY()==newY) || (r.getX()==newX) && (r.getY()==newY) || (k.getX()==newX) && (k.getY()==newY))
    {
        cout << "Invalid Knight Move (Collision)..." << endl;
        return false;
    }
    return(true);
}

//default constructor declaration
Pawn::Pawn()
{
    x = 4;
    y = 0;
}

int Pawn::getX() const
{
    return x;
}

int Pawn::getY() const
{
    return y;
}

bool Pawn::movePawn(int newX, int newY)
{
    //starting move allows 2 spaces up
    if (x==4 && y==0)
    {
        if((newX==4) && ((newY-y) == 2 || (newY-y) == 1))
        {
            x = newX;
            y = newY;
            return true;
        }
        else
        {
            cout << "Invalid Pawn Move..." << endl;
            return false;
        }
    }
    else if(x==4 && y!=0)
    {
        if((newX==4) && (newY-y) == 1)
        {
            x = newX;
            y = newY;
            return true;
        }
        else
        {
            cout << "Invalid Pawn Move..." << endl;
            return false;
        }
    }
}

bool Pawn::withinBounds(int newX, int newY)
{
    if(newX<0 || newX>=10 || newY<0 || newY>=10)
    {
        cout << "Invalid Pawn Move..." << endl;
        return false;
    }
    return(true);
}

bool Pawn::isCollision(int newX, int newY, const Rook &r, const Knight &g, const King &k)
{
    if((r.getX()==newX) && (r.getY()==newY) || (g.getX()==newX) && (g.getY()==newY) || (k.getX()==newX) && (k.getY()==newY))
    {
        cout << "Invalid Pawn Move (Collision)..." << endl;
        return false;
    }
    return(true);
}

//default constructor declaration
Rook::Rook()
{
    x = 5;
    y = 0;
}

int Rook::getX() const
{
    return x;
}

int Rook::getY() const
{
    return y;
}

bool Rook::moveRook(int newX, int newY)
{
    if(newX==x && newY==y)
    {
        cout << "Invalid Rook Move..." << endl;
        return false;
    }
    //for x movement
    else if(abs(newX-x)<=9 && abs(newX-x)>=0 && newY==y)
    {
        x = newX;
        return true;
    }
    //for y movement
    else if(abs(newY-y)<=9 && abs(newY-y)>=0 && newX==x)
    {
        y = newY;
        return true;
    }
    else
    {

        cout << "Invalid Rook Move..." << endl;
        return false;
    }
}

bool Rook::withinBounds(int newX, int newY)
{
    if(newX<0 || newX>=10 || newY<0 || newY>=10)
    {
        cout << "Invalid Rook Move..." << endl;
        return false;
    }
    return(true);
}

bool Rook::isCollision(int newX, int newY, const Pawn &p, const Knight &g, const King &k)
{
    //simply put, if any of the objects share the same cord, user will be given a collision error.
    if((p.getX()==newX) && (p.getY()==newY) || (g.getX()==newX) && (g.getY()==newY) || (k.getX()==newX) && (k.getY()==newY))
    {
        cout << "Invalid Rook Move (Collision)..." << endl;
        return false;
    }
    return(true);
}

//default constructor declaration
King::King()
{
    x = 6;
    y = 0;
}

int King::getX() const
{
    return x;
}

int King::getY() const
{
    return y;
}

bool King::moveKing(int newX, int newY)
{
    //wont move peice to same square
    if(newX==x && newY==y)
    {
        cout << "Invalid King Move..." << endl;
        return false;
    }
    //strictly x movement
    else if((newX!=x) && newY==y)
    {
        if(abs(newX-x)==1)
        {
            x = newX;
            return true;
        }
        else
        {
            cout << "Invalid King Move..." << endl;
            return false;
        }
    }
    //strictly y movement
    else if((newX==x) && (newY!=y))
    {
        if(abs(newY-y)==1)
        {
            y = newY;
            return true;
        }
        else {
            cout << "Invalid King Move..." << endl;
            return false;
        }
    }

    //diagonal movement
    else if((newX!=x) && (newY!=y))
    {
        if((abs(newX-x)==1) && (abs(newY-y)==1))
        {
            x = newX;
            y = newY;
            return true;
        }
        else
        {
            cout << "Invalid King Move..." << endl;
            return false;
        }
    }
}

bool King::withinBounds(int newX, int newY)
{
    //checks cartesian board boundaries
    if(newX<0 || newX>=10 || newY<0 || newY>=10)
    {
        cout << "Invalid King Move..." << endl;
        return false;
    }
    return(true);
}

bool King::isCollision(int newX, int newY, const Rook &r, const Knight &g, const Pawn &p)
{
    //gets for collision with other piece objects
    if((r.getX()==newX) && (r.getY()==newY) || (g.getX()==newX) && (g.getY()==newY) || (p.getX()==newX) && (p.getY()==newY))
    {
        cout << "Invalid King Move (Collision)..." << endl;
        return false;
    }
    return(true);
}




