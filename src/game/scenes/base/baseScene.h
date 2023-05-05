﻿#pragma once
#pragma once
#include <vector>
#include "../../../engine/ui/button.h"
#include "../../game.h"
#include "../../../engine/object.h"
#include "../../../engine/ui/sliderBar.h"
#include "../../../engine/ui/text.h"

class BaseScene : public Object
{
public:
    void SetGame(Game& game) {this->game = &game;}
    
    void Init() override;
    void Tick(float deltaTime) override;
    void PhysicsTick(float fixedDeltaTime) override;
    void Render() override;

    std::vector<Button>& GetButtonList() {return buttonList;}
    std::vector<Text>& GetTextList() {return textList;}
    std::vector<SliderBar>& GetSliderList() {return sliderList;}
    
protected:
    Game& GetGame() const {return *game;}
    
    std::vector<Button> buttonList;
    virtual void CreateButtons() = 0;
    virtual void BindButtons() = 0;
    
    sf::Texture* playTex = nullptr;
    sf::Texture* pauseTex = nullptr;
    sf::Texture* menuTex = nullptr;
    sf::Texture* restartTex = nullptr;
    sf::Texture* backTex = nullptr;
    sf::Texture* shopTex = nullptr;
    sf::Texture* optionsTex = nullptr;
    void CreateTextures();
    
    std::vector<Text> textList;
    sf::Font font;
    sf::Font& getFont() {return font;}
    void SetFont(const sf::Font& newFont) {font = newFont;}
    virtual void CreateText() = 0;

    std::vector<SliderBar> sliderList;
    virtual void CreateSliders() {}
    virtual void BindSliders() {}
    
private:
    Game* game = nullptr;
};