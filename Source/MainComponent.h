#pragma once

#include <JuceHeader.h>
#include "Grid.h"
#include "Clock.h"

class MainComponent  :  public juce::Component,
                        public juce::KeyListener

{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    bool keyPressed(const juce::KeyPress& key, juce::Component* originatingComponent) override;
    
    void clearGrid();
    
    
private:
    //==============================================================================
    // Your private member variables go here...

    Gridd grid;
    Clock clock;
    
    juce::TextButton clearButton{"Clear", "Clear"};
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
