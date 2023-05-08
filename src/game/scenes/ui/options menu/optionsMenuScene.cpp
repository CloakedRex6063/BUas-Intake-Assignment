#include "optionsMenuScene.h"
#include "../../../../engine/save file/saveFile.h"
#include "../../../../engine/audio manager/audioManager.h"
#include "../../../../engine/main/main.h"

void OptionsMenuScene::CreateButtons()
{
    const auto backPos = sf::Vector2f(100.f,GetWindow().getSize().y - 100.f);
    const auto backBut = Button(backPos,sf::Vector2f(100.f,100.f),5.f,GetGame().backTex);
    const auto vsyncPos = sf::Vector2f(GetWindow().getSize().x/2.f - 300.f,GetWindow().getSize().y/2.f + 150.f);
    const auto vsyncBut = Button(vsyncPos,sf::Vector2f(100.f,100.f),5.f,GetGame().tickTex);
    const auto fpsPos = sf::Vector2f(GetWindow().getSize().x/2.f + 300.f,GetWindow().getSize().y/2.f + 150.f);
    const auto fpsBut = Button(fpsPos,sf::Vector2f(100.f,100.f),5.f,GetGame().tickTex);
    buttonList.emplace_back(backBut);
    buttonList.emplace_back(vsyncBut);
    buttonList.emplace_back(fpsBut);
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
        SaveFile::SaveSettings(AudioManager::GetSoundVolume(),AudioManager::GetMusicVolume(),Main::GetVsync(),Game::GetShowFPS());
    };
    vsync = [&]
    {
        GetWindow().setVerticalSyncEnabled(!Main::GetVsync());
        Main::SetVsync(!Main::GetVsync());
        buttonList[1].SetTexture(Main::GetVsync() ? GetGame().tickTex : GetGame().unTickTex);
    };
    fps = [&]
    {
        Game::SetShowFPS(!Game::GetShowFPS());
        buttonList[2].SetTexture(Game::GetShowFPS() ? GetGame().tickTex : GetGame().unTickTex);
    };
    buttonList[0].onButtonPressed = back;
    buttonList[1].onButtonPressed = vsync;
    buttonList[2].onButtonPressed = fps;
}

void OptionsMenuScene::CreateText()
{
    const auto mainPos = sf::Vector2f(GetWindow().getSize().x /2.f,50.f);
    const auto mainText = Text(mainPos,GetGame().GetFont(),50,"Dash");
    const auto sfxPos = sf::Vector2f(GetWindow().getSize().x /2.f - 300.f,250.f);
    const auto sfxText = Text(sfxPos,GetGame().GetFont(),50,"SFX");
    const auto musicPos = sf::Vector2f(GetWindow().getSize().x /2.f + 300.f,250.f);
    const auto musicText = Text(musicPos,GetGame().GetFont(),50,"Music");
    const auto vsyncPos = sf::Vector2f(GetWindow().getSize().x /2.f - 300.f,GetWindow().getSize().y/2.f + 50.f);
    const auto vsyncText = Text(vsyncPos,GetGame().GetFont(),50,"V-Sync");
    const auto fpsPos = sf::Vector2f(GetWindow().getSize().x /2.f + 300.f,GetWindow().getSize().y/2.f + 50.f);
    const auto fpsText = Text(fpsPos,GetGame().GetFont(),50,"FPS");
    const auto control1Pos = sf::Vector2f(GetWindow().getSize().x /2.f,GetWindow().getSize().y - 150.f);
    const auto control1Text = Text(control1Pos,GetGame().GetFont(),50,"Press Space to Jump");
    const auto control2Pos = sf::Vector2f(GetWindow().getSize().x /2.f,GetWindow().getSize().y - 50.f);
    const auto control2Text = Text(control2Pos,GetGame().GetFont(),50,"Hold Space to Fly in the fly section");
    textList.emplace_back(mainText);
    textList.emplace_back(sfxText);
    textList.emplace_back(musicText);
    textList.emplace_back(vsyncText);
    textList.emplace_back(fpsText);
    textList.emplace_back(control1Text);
    textList.emplace_back(control2Text);
    for (auto &text : textList)
    {
        text.SetTarget(GetWindow(),GetGameView(),GetFixedView(),GetParallaxView());
        text.Init();
    }
}

void OptionsMenuScene::CreateSliders()
{
    const auto soundPos = sf::Vector2f(300.f,GetWindow().getSize().y / 2.f - 100.f);
    const auto soundSlider = SliderBar(soundPos,sf::Vector2f(400.f,20.f),10.f);
    const auto musicPos = sf::Vector2f(GetWindow().getSize().x/ 2.f + 100.f,GetWindow().getSize().y / 2.f - 100.f);
    const auto musicSlider = SliderBar(musicPos,sf::Vector2f(400.f,20.f),10.f);
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
        AudioManager::SetSoundVolume(value);
    };
    musicVolume = [&] (float value)
    {
        AudioManager::SetMusicVolume(value);
    };
    sliderList[0].onValueChanged = soundVolume;
    sliderList[1].onValueChanged = musicVolume;
}
