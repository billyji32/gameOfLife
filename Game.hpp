#ifndef GAME_HPP
#define GAME_HPP

#include <vector>   // for patternCells



//Stores an ordered (x, y) pair in 2D coordinate space.
struct Cell
{
    // coordinates on grid
    int x;
    int y;

    // constructor that takes the ordered pair
    Cell(int x, int y);
};


class Game
{
    private:
        // total width of game grid, including two side buffers
        int width;

        // total height of game grid, including top and bottom buffers
        int height;

        // number of extra rows/columns off each edge of the visible grid
        int buffer;

        // number of ticks in complete game
        int generations;

        // duration of a single tick
        int pauseLength;

        // stores 2D world of cells either alive or dead
        int **grid;

        // stores the user's chosen initial pattern of live cells in the
        // form of coordinates
        std::vector<Cell> patternCells;

    public:
        // constructor that sets world to initial state (tick 0) with shape
        // included
        Game(int width, int height, char pattern, int xOffset, int yOffset,
             int generations, int pauseLength);

        // destructor which kills the grid
        ~Game();

        // fills entire grid with dead cells - run once
        void clearGrid();
        
        // determines a cell's fate based on the rules and updates its
        // position on nextGrid
        void determineFate(Cell c, int **nextGrid);

        // sets relevant cells of grid to be alive based on patternCells
        void initializePattern();

        // runs the full game and prints each generation to screen 
        void play();

        // testing method which prints current grid, with buffers, to screen
        void printWholeGrid();
        
        // method which prints current grid, without buffers, to screen
        void printWindow();

        // store the initial live cells in patternCells
        void setPatternVector(char pattern, int xOffset, int yOffset);

        // execute a single tick of gameplay, updating grid after rules
        // have been applied to each cell
        void tick();
};

#endif