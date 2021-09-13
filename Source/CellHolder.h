/*
  ==============================================================================

    CellHolder.h
    Created: 13 Sep 2021 6:09:43am
    Author:  Kris Crawford

  ==============================================================================
*/


#pragma once
#include "Cell.h"

//This class exists to abstract away some of the weird syntax(s) of the arrays.
class CellHolder
{
public:
    CellHolder(Gridd& grid);
    
    Cell* newCell(int x, int y);
    void deleteCell(int x, int y);
    
    Cell* getCell(int x, int y);
    Cell* getTempCell(int x, int y);
    
    void copyCellState();
    
    int getColSize(int x);
    int getRowSize();
    
    void clearCells();
    
    void setHolderSize(int x, int y);
    
private:
    
    Gridd& parentGrid;
    
    std::vector<std::vector<std::unique_ptr<Cell>>> cells;
    std::vector<std::vector<std::unique_ptr<Cell>>> tempCells;
    
};
