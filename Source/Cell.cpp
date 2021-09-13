/*
  ==============================================================================

    Cell.cpp
    Created: 28 May 2021 1:24:32pm
    Author:  Kris Crawford

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Cell.h"
#include "Grid.h"

//==============================================================================

Cell::Cell (Gridd* grid, int xPos, int yPos)
: parentGrid(grid), x(xPos), y(yPos)
{

    
    neighbors.emplace(NeighborsIds::left, false);
    neighbors.emplace(NeighborsIds::right, false);
    neighbors.emplace(NeighborsIds::up, false);
    neighbors.emplace(NeighborsIds::down, false);
    neighbors.emplace(NeighborsIds::leftUp, false);
    neighbors.emplace(NeighborsIds::leftDown, false);
    neighbors.emplace(NeighborsIds::rightUp, false);
    neighbors.emplace(NeighborsIds::rightDown, false);
    
}


Cell::~Cell()
{
    neighbors.clear();
    parentGrid = nullptr;
}

void Cell::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    
   if (alive)
   {
       g.setColour(juce::Colours::lightgrey);
   }
   else
   {
       g.setColour(juce::Colours::darkgrey);
   }
    
    g.fillRect(area);
    
    g.setColour(juce::Colours::white);
    g.drawRect(area);
    
    
}

void Cell::resized()
{
    
}

void Cell::mouseDown(const juce::MouseEvent& e)
{
    // LEFT clicking the cell will toggle it's state, RIGHT clicking the cell will toggle and then Print Cell state.
    alive = !alive;
    setLivingState(alive, e.mods.isRightButtonDown());
}

void Cell::mouseDrag(const juce::MouseEvent& e)
{
    //Fix me
    //this only gets called on the cell where the orignal click happens. Will need to deduce which cells to turn on based off mouse position
}

bool Cell::getCellState()
{
    return alive;
}

void Cell::setLivingState(bool isAlive, bool print)
{
    alive = isAlive;
    
    //If neighbor is on the screen we update it's knowledge of this cell's state,
    //otherwise we update this cell's neihgbors of offscreen (dead) cell
    
    if (parentGrid == nullptr)
    {
        DBG("Grid Null in Cell " + juce::String(x) + ", " + juce::String(y));
    }
    else
    {
        if (auto cell = parentGrid->getCell(x - 1, y))
        {
            cell->setNeighbor(NeighborsIds::right, alive);
        }
        else
        {
            setNeighbor(NeighborsIds::left, false);
        }
        
        if (auto cell = parentGrid->getCell(x + 1, y))
        {
            cell->setNeighbor(NeighborsIds::left, alive);
        }
        else
        {
            setNeighbor(NeighborsIds::right, false);
        }
        
        if (auto cell = parentGrid->getCell(x, y - 1))
        {
            cell->setNeighbor(NeighborsIds::down, alive);
        }
        else
        {
            setNeighbor(NeighborsIds::up, false);
        }
        
        if (auto cell = parentGrid->getCell(x, y + 1))
        {
            cell->setNeighbor(NeighborsIds::up, alive);
        }
        else
        {
            setNeighbor(NeighborsIds::down, false);
        }
        
        if (auto cell = parentGrid->getCell(x - 1, y - 1))
        {
            cell->setNeighbor(NeighborsIds::leftDown, alive);
        }
        else
        {
            setNeighbor(NeighborsIds::leftUp, false);
        }
        
        if (auto cell = parentGrid->getCell(x - 1, y + 1))
        {
            cell->setNeighbor(NeighborsIds::leftUp, alive);
        }
        else
        {
            setNeighbor(NeighborsIds::leftDown, false);
        }
        
        if (auto cell = parentGrid->getCell(x + 1, y - 1))
        {
            cell->setNeighbor(NeighborsIds::rightDown, alive);
        }
        else
        {
            setNeighbor(NeighborsIds::rightUp, false);
        }
        
        if (auto cell = parentGrid->getCell(x + 1, y + 1))
        {
            cell->setNeighbor(NeighborsIds::rightUp, alive);
        }
        else
        {
            setNeighbor(NeighborsIds::rightDown, false);
        }
        
        repaint();
        
        if (print)
        {
            printCellState();
        }
    }
}




void Cell::setNeighbor(NeighborsIds id, bool state)
{
    neighbors[id] = state;
}

int Cell::sumAliveNeighbors()
{
    numNieghborsAlive = 0;
    
    for (int i = 0; i < neighbors.size(); i++)
    {
        NeighborsIds neighbor = static_cast<NeighborsIds>(i);
        if (neighbors[neighbor] == true)
        {
            ++numNieghborsAlive;
        }
    }
    
    return numNieghborsAlive;
}

void Cell::printCellState()
{
    
    DBG("--------Cell State-------");
    DBG("X = " + juce::String(x));
    DBG("Y = " + juce::String(y));
    DBG("Alive = " + juce::String(alive ? "True" : "False"));
    DBG("Neihgbors--");
    
    for (int i = 0; i < neighbors.size(); i++)
    {
        NeighborsIds neighbor = static_cast<NeighborsIds>(i);
        bool state = neighbors[neighbor];
        if (state)
        {
            DBG("Id: " + juce::String(neighbor) + ", Alive: True" );
        }
        else
        {
            DBG("Id: " + juce::String(neighbor) + ", Alive: False" );
        }
        
    }
}

int Cell::getX()
{
    return x;
}


int Cell::getY()
{
    return y;
}

