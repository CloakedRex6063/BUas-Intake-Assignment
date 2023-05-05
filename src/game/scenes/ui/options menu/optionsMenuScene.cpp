#include "optionsMenuScene.h"

#include "../../../../engine/audioManager.h"

void OptionsMenuScene::CreateButtons()
{
    const auto backPos = sf::Vector2f(100.f,GetWindow().getSize().y - 100.f);
    const auto backBut = Button(backPos,sf::Vector2f(100.f,100.f),5.f,backTex);
    buttonList.emplace_back(backBut);
    for (auto &but : buttonList)
    {
        but.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        but.Init();
    }
}

void OptionsMenuScene::BindButtons()
{
    back = [&]
    {
        GetGame().ChangeState(MainMenu_State);
    };
    buttonList[0].onButtonPressed = back;
}

void OptionsMenuScene::CreateText()
{
    const auto mainPos = sf::Vector2f(GetWindow().getSize().x /2.f,50.f);
    const auto mainText = Text(mainPos,getFont(),50,"Dash");
    const auto sfxPos = sf::Vector2f(GetWindow().getSize().x /2.f - 300.f,350.f);
    const auto sfxText = Text(sfxPos,getFont(),50,"SFX");
    const auto musicPos = sf::Vector2f(GetWindow().getSize().x /2.f + 300.f,350.f);
    const auto musicText = Text(musicPos,getFont(),50,"Music");
    textList.emplace_back(mainText);
    textList.emplace_back(sfxText);
    textList.emplace_back(musicText);
    for (auto &text : textList)
    {
        text.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        text.Init();
    }
}

void OptionsMenuScene::CreateSliders()
{
    const auto soundPos = sf::Vector2f(300.f,GetWindow().getSize().y / 2.f);
    const auto soundSlider = SliderBar(soundPos,sf::Vector2f(400.f,20.f),5.f);
    const auto musicPos = sf::Vector2f(GetWindow().getSize().x/ 2.f + 100.f,GetWindow().getSize().y / 2.f);
    const auto musicSlider = SliderBar(musicPos,sf::Vector2f(400.f,20.f),5.f);
    sliderList.emplace_back(soundSlider);
    sliderList.emplace_back(musicSlider);
    for (auto &slider : sliderList)
    {
        slider.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        slider.Init();
    }
}

void OptionsMenuScene::BindSliders()
{
    soundVolume = [&] (float value)
    {
        AudioManager::SetSoundVolume(value * 100.f);
    };
    musicVolume = [&] (float value)
    {
        AudioManager::SetMusicVolume(value * 100.f);
    };
    sliderList[0].onValueChanged = soundVolume;
    sliderList[1].onValueChanged = musicVolume;
}
