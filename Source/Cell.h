/*
  ==============================================================================

    Cell.h
    Created: 28 May 2021 1:24:32pm
    Author:  Kris Crawford

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/

enum NeighborsIds
{
    left,
    right,
    up,
    down,
    leftUp,
    leftDown,
    rightUp,
    rightDown
};

class Gridd;

class Cell  : public juce::Component
{
public:
    
    //copy ctor
    Cell(const Cell& other)
    : alive(other.alive), numNieghborsAlive(other.numNieghborsAlive), neighbors(other.neighbors), x(other.x), y(other.y), parentGrid(other.parentGrid)
    {}
    
    //assignment operator
    Cell& operator= (Cell& other)
    {
        alive = other.alive;
        numNieghborsAlive = other.numNieghborsAlive;
        neighbors = other.neighbors;
        x = other.x;
        y = other.y;
        parentGrid = other.parentGrid;
        
        return *this;
    }
    
   
    Cell(Gridd* grid = nullptr, int x = 0, int y = 0);
    
    ~Cell() override;

     
    void paint (juce::Graphics&) override;
    void resized() override;

    void mouseDown(const juce::MouseEvent& e) override;
    void mouseDrag(const juce::MouseEvent& e) override;
    
    
    bool getCellState(); 

    void setLivingState(bool isAlive, bool print = false);
    
    void setNeighbor(NeighborsIds, bool state);
    int sumAliveNeighbors();
    
    void printCellState();
    
    int getX();
    int getY();
    
    
private:
    
    bool alive = false;
    int numNieghborsAlive = 0;
    
    std::map<NeighborsIds, bool> neighbors;
    
    int x;
    int y;
     
    Gridd* parentGrid = nullptr;
    
};

