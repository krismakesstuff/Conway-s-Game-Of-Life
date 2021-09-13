/*
  ==============================================================================

    Grid.h
    Created: 28 May 2021 1:24:21pm
    Author:  Kris Crawford

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CellHolder.h"

//Gridd is spelled with two "d"s to avoid juce::grid, annoying...

class Gridd  : public juce::Component
{
public:
    Gridd();
    ~Gridd() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void resizeGrid(juce::Rectangle<int> newBounds);
    
    void buildGrid();
    
    Cell* getCell(int x, int y);
    
    void nextFrame();
    
    void clearCells();
    
private:
    
    CellHolder cellHolder{*this};
    
    
    int numColumnCells = 0;
    int numRowCells = 0;
    
    int totalNumCells = 0;
    
    
    int cellWidth = 12;
    int cellHeight = 12;
    
    bool toggle = false;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gridd)
};

