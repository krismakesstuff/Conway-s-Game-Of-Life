#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(grid);
    addAndMakeVisible(clock);
    
    addAndMakeVisible(clearButton);
    clearButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::black.withAlpha(0.5f));
    clearButton.setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::white);
    clearButton.onClick = [this] { clearGrid(); };
    
    
    addKeyListener(this);
    
    setSize (600, 400);
    setWantsKeyboardFocus(true);
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    
    int clockW = 100;
    int clockH = 30;
    
    int clearW = 60;
    int clearH = 30;
    
    grid.setBounds(area);
    clock.setBounds(area.withRight(clockW).withBottom(clockH));
    clearButton.setBounds(area.withLeft(area.getRight() - clearW).withBottom(clearH));
                    
    grid.buildGrid();
}


bool MainComponent::keyPressed(const juce::KeyPress& key, juce::Component* originatingComponent)
{
    if (key.isKeyCode(juce::KeyPress::rightKey))
    {
        clock.nextFrame();
        grid.nextFrame();
    }
    
    return true;
}


void MainComponent::clearGrid()
{
    
    grid.clearCells();
    clock.reset();
}
