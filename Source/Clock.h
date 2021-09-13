/*
  ==============================================================================

    Clock.h
    Created: 28 May 2021 1:24:38pm
    Author:  Kris Crawford

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Clock  : public juce::Component
{
public:
    Clock();
    ~Clock() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void nextFrame();
    void reset();
    
private:
    
    int currentFrame = 0;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Clock)
};
