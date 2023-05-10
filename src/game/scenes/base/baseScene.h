#pragma once
#pragma once
#include <vector>
#include "../../../engine/ui/button.h"
#include "../../game.h"
#include "../../../engine/object.h"
#include "../../../engine/ui/sliderBar.h"
#include "../../../engine/ui/text.h"

class BaseScene : public Object
{
    
#pragma region Required
    
public:
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;

#pragma endregion

#pragma region Game
    
    void SetGame(Game& game) {this->game = &game;}
    Game& GetGame() const {return *game;}
private:
    Game* game = nullptr;

#pragma endregion 

#pragma region UI
    
#pragma region Buttons
    
public:
    std::vector<Button>& GetButtonList() {return buttonList;}

protected:
    std::vector<Button> buttonList;
    virtual void CreateButtons() = 0;
    virtual void BindButtons() = 0;

#pragma endregion 

#pragma region Text
    
public:
    std::vector<Text>& GetTextList() {return textList;}

protected:
    std::vector<Text> textList;
    virtual void CreateText() = 0;

#pragma endregion 

#pragma region Sliders
    
public:
    std::vector<SliderBar>& GetSliderList() {return sliderList;}
protected:
    std::vector<SliderBar> sliderList;
    virtual void CreateSliders() {}
    virtual void BindSliders() {}

#pragma endregion

#pragma endregion 
    
};
