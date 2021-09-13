/*
  ==============================================================================

    Grid.cpp
    Created: 28 May 2021 1:24:21pm
    Author:  Kris Crawford

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Grid.h"
#include "CellHolder.h"

//==============================================================================
Gridd::Gridd()
{
}

Gridd::~Gridd()
{
}

void Gridd::paint (juce::Graphics& g)
{
}

void Gridd::resized()
{

}


//bounds must be set first!!
void Gridd::buildGrid()
{
    auto area = getLocalBounds();
    int width = area.getWidth();
    int height = area.getHeight();
    numColumnCells = width / cellWidth;
    numRowCells = height / cellHeight;
    
    cellHolder.setHolderSize(numColumnCells, numRowCells);

    for (int x = 0; x < numColumnCells; x++)
    {
        for (int y = 0; y < numRowCells; y++)
        {
            auto newCell  = cellHolder.newCell(x, y);
            newCell->setBounds(x * cellWidth, y * cellHeight, cellWidth, cellHeight );
            addAndMakeVisible(newCell);
            totalNumCells++;
        }
    }
    
    DBG("Total Cells: " + juce::String(totalNumCells));
    
}


Cell* Gridd::getCell(int x, int y)
{
    return cellHolder.getCell(x, y);
}

void Gridd::nextFrame()
{
    
    cellHolder.copyCellState();
    
    for (int x = 0; x < cellHolder.getRowSize(); x++)
    {
        for (int y = 0; y < cellHolder.getColSize(x); y++)
        { 
            int numNeighborsAlive = cellHolder.getTempCell(x, y)->sumAliveNeighbors();
            bool tempCellState = cellHolder.getTempCell(x, y)->getCellState();
            
            if (tempCellState && (numNeighborsAlive < 2 || numNeighborsAlive > 3))
            {
                //cell dies if it doesn't have the right amount of neighbors alive
                cellHolder.getCell(x, y)->setLivingState(false);
                
            }
            else if (!tempCellState && numNeighborsAlive == 3)
            {
                //cell is born
                cellHolder.getCell(x, y)->setLivingState(true);
            }
        }
    }
}

void Gridd::clearCells()
{
    cellHolder.clearCells();
    buildGrid();
}
