//
// Created by Charlie Lakis on 1/20/24.
//

#ifndef P1_PIECES_H
#define P1_PIECES_H

class Knight;
class Pawn;
class Rook;
class King;

class Knight {
public:
    //default constructor to set location at start
    Knight();
    //getter for location (CHECKER DELETE AFTER)
    int getX() const;
    int getY() const;
    //setter for location
    bool moveKnight(int newX, int newY);
    //bounds checker
    static bool withinBounds(int newX, int newY);
    //collision checker
    static bool isCollision(int newX, int newY, const Pawn &p, const Rook &r, const King &k);
private:
    //location of peice
    int x;
    int y;
};

class Pawn {
public:
    //default constructor to set location at start
    Pawn();
    //getter for location (CHECKER DELETE AFTER)
    int getX() const;
    int getY() const;
    //setter for location
    bool movePawn(int newX, int newY);
    static bool withinBounds(int newX, int newY);
    static bool isCollision(int newX, int newY, const Rook &r, const Knight &g, const King &k);
private:
    //location of peice
    int x;
    int y;
};

class Rook {
public:
    //default constructor to set location at start
    Rook();
    //getter for location (CHECKER DELETE AFTER)
    int getX() const;
    int getY() const;
    //setter for location
    bool moveRook(int newX, int newY);
    static bool withinBounds(int newX, int newY);
    static bool isCollision(int newX, int newY, const Pawn &p, const Knight &g, const King &k);
private:
    //location of peice
    int x;
    int y;
};

class King {
public:
    //default constructor to set location at start
    King();
    //getter for location (CHECKER DELETE AFTER)
    int getX() const;
    int getY() const;
    //setter for location
    bool moveKing(int newX, int newY);
    static bool withinBounds(int newX, int newY);
    static bool isCollision(int newX, int newY, const Rook &r, const Knight &g, const Pawn &p);
private:
    //location of peice
    int x;
    int y;
};


#endif //P1_PIECES_H
