#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Game;
class Board;
class Block;

enum class Color
{
    Black,
    White
};

class Piece
{
public:
    string name;
    Color color;
    bool killed = false;

    Piece(string _name, Color _color) : name(_name), color(_color) {};
    // deconstruct piece ?

    virtual bool canMove(Board *board, Block *startBlock, Block *endBlock) = 0;

    bool isKilled() const { return killed; }
    void setKilled(bool killed) { this->killed = killed; }
};

class King : public Piece
{
public:
    King(string _name, Color _color) : Piece(_name, _color) {};

    bool canMove(Board *board, Block *startBlock, Block *endBlock)
    {
        // logic for true;
        return false;
    }
};

class Queen : public Piece
{
public:
    Queen(string _name, Color _color) : Piece(_name, _color) {};

    bool canMove(Board *board, Block *startBlock, Block *endBlock)
    {
        // logic for true;
        return false;
    }
};

class Pawn : public Piece
{
public:
    Pawn(string _name, Color _color) : Piece(_name, _color) {};

    bool canMove(Board *board, Block *startBlock, Block *endBlock)
    {
        // logic for true;
        return false;
    }
};

class Block
{

    int x, y;
    string index; // position of block [1-A , 1-1];
    Piece *piece;

    string assignIndex(int x, int y)
    {
        string xIndex[] = {"1", "2", "3", "4", "5", "6", "7", "8"};
        string yIndex[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
        return xIndex[x] + xIndex[y];
    }

public:
    Block(int x, int y, Piece *piece = nullptr) : x(x), y(y), piece(piece)
    {
        index = assignIndex(x, y);
    }

    Piece *getPiece() { return piece; }
    void setPiece(Piece *piece) { this->piece = piece; }
};

class Board
{
    Block *blocks[8][8];

    void initizeBoard()
    {
        // setting white pieces
        blocks[0][3] = new Block(0, 3, new Queen("Q", Color::White));
        blocks[0][4] = new Block(0, 4, new King("K", Color::White));
        for (int i = 0; i < 8; i++)
        {
            blocks[6][i] = new Block(6, i, new Pawn("P", Color::White));
        }
        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                blocks[i][j] = new Block(i, j, nullptr);
            }
        }
        // setting black pieces
    }

public:
    Board()
    {
        initizeBoard();
    }

    Block *getBlock(int x, int y)
    {
        return blocks[x][y];
    }
};

enum class Status
{
    ACTIVE,
    BLACK_WIN,
    WHITE_WIN,
    DRAW,
    PAUSE,
    END
};

class Player
{
    string name;
    Color color;

public:
    Player(string name) : name(name) {}

    void joinGame(Game *g) {};
    bool isValid(Block *startBlock, Block *endBlock)
    {
        // assuming block position are correct
        return !(startBlock->getPiece()->color == endBlock->getPiece()->color);
    }
};

class Game
{
    Board board;
    Player *player1;
    Player *player2;

    Player *currPlayer;
    Status status;

public:
    Game(Player *p1, Player *p2) : player1(p1), player2(p2), currPlayer(p1), status(Status::ACTIVE) {};

    void makeMove(Block *startBlock, Block *endBlock, Player *p)
    {
        if (p->isValid(startBlock, endBlock))
        {
            Piece *srcPiece = startBlock->getPiece();
            if (srcPiece && srcPiece->canMove(&board, startBlock, endBlock))
            {
                Piece *desPiece = endBlock->getPiece();
                if (desPiece != nullptr)
                {
                    if (dynamic_cast<King *>(desPiece))
                    { // if destination piece is king
                        status = (p == player1) ? Status::WHITE_WIN : Status::BLACK_WIN;
                        return;
                    }
                    desPiece->setKilled(true);
                }
                endBlock->setPiece(srcPiece);
                startBlock->setPiece(nullptr);
                currPlayer = (p == player1) ? player2 : player1;
            }
        }
    }
    void start()
    {
        Block *i;
        Block *j;
        while (status == Status::ACTIVE)
        {
            if (currPlayer == player1)
            { // white turn
                makeMove(i, j, player1);
            }
            else
            {
                makeMove(i, j, player2);
            }
        }
    }
};