#include "MainComponent.h"




template<class ButtonType>
auto makeButton(ButtonType* buttonToMakeUnique) -> std::unique_ptr<ButtonType>
{
    return std::unique_ptr<ButtonType>(buttonToMakeUnique);
}



//==============================================================================
MainComponent::MainComponent() 
{
  

//    std::make_unique<juce::TextButton>(nullptr);
//    ButtonWrapper<juce::DrawableButton>()
    
    heapButton.reset(new HeapButtonWrapper<juce::TextButton>([](){DBG("You clicked the heap");},                                                                                                    new juce::TextButton("heapButton"))
                    );
    addAndMakeVisible(button);
    
    addAndMakeVisible( (*heapButton) );
    setSize(600, 400);
}


MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (48.0f));
    g.setColour (juce::Colours::red);
    g.drawText ("Hello NEW WORLD!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    button->setBounds(498,
                      0,
                      100, 30);
    (*heapButton)->setBounds(498,
                             368,
                             100, 30);
}



