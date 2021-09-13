/*
  ==============================================================================

    CellHolder.cpp
    Created: 13 Sep 2021 6:09:43am
    Author:  Kris Crawford

  ==============================================================================
*/

#include "CellHolder.h"

CellHolder::CellHolder(Gridd &grid)
: parentGrid(grid)
{}

void CellHolder::copyCellState()
{
    for(int x = 0; x < cells.size(); x++)
    {
        for(int y = 0; y < cells[x].size(); y++)
        {
            tempCells[x][y].reset(new Cell());
            *tempCells[x][y] = *cells[x][y];
        }
    }

}


void CellHolder::deleteCell(int x, int y)
{
    cells[x][y] = nullptr;
}


Cell *CellHolder::newCell(int x, int y)
{
    cells[x][y].reset(new Cell(&parentGrid, x, y));
    return cells[x][y].get();
}

Cell *CellHolder::getCell(int x, int y)
{
    return cells[x][y].get();
}

Cell *CellHolder::getTempCell(int x, int y)
{
    return tempCells[x][y].get();
}

int CellHolder::getRowSize()
{
    return (int)cells.size();
}

int CellHolder::getColSize(int x)
{
    return (int)cells[x].size();
}

void CellHolder::clearCells()
{
    tempCells.clear();
    cells.clear();
    
}

void CellHolder::setHolderSize(int xSize, int ySize)
{
    cells.resize(xSize);
    tempCells.resize(xSize);
    
    
    for(int x = 0; x <cells.size(); x++)
    {
        cells[x].resize(ySize);
        tempCells[x].resize(ySize);
    }

    DBG("xSize  = " + juce::String(xSize) + ", ySize = " + juce::String(ySize));
}




