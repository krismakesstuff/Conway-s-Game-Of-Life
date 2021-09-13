/*
  ==============================================================================

    Clock.cpp
    Created: 28 May 2021 1:24:38pm
    Author:  Kris Crawford

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Clock.h"

//==============================================================================
Clock::Clock()
{


}

Clock::~Clock()
{
}

void Clock::paint (juce::Graphics& g)
{
    auto area  = getLocalBounds();
    g.setColour(juce::Colours::black.withAlpha((0.5f)));
    g.fillRect(area);
    
    g.setColour(juce::Colours::white);
   
    juce::String frameString = currentFrame == 0 ? "Seed" : "Frame: " + juce::String(currentFrame);
    
    g.drawFittedText(frameString, area, juce::Justification::centred, 1);
    
}

void Clock::resized()
{
    
}


void Clock::nextFrame()
{
    ++currentFrame;
    repaint();
}

void Clock::reset()
{
    currentFrame = 0;
    repaint();
}
