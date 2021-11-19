/*
** EPITECH PROJECT, 2021
** Arcade Library
** File description:
** SFML.hpp
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "../../../../core/include/Object.hpp"
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../../../core/include/IDisplayModule.hpp"

class SFML : public IDisplayModule {
    public:
        SFML();
        ~SFML() = default;

        void createWindow(void);
        bool isWindowOpen(void) const;
        void closeWindow(void);
        void refreshWindow(void);
        void clearWindow(void);
        void checkWindowEvent(void);
        move_t getMovement(void);
        void refreshTimer(void);
        bool isDelayed(void);
        void loadTexture(std::vector<std::shared_ptr<Object>> &obj);
        void createSprite(void);
        void drawMap(void);
        void drawPlayer(std::shared_ptr<Object> player);
        void drawFruit(std::shared_ptr<Object> fruit);
    private:
        std::shared_ptr<sf::RenderWindow> _window;
        std::shared_ptr<sf::Clock> _clock;
        float _timer;
        float _delay;
        float _time;
        sf::Texture _fr;
        sf::Texture _sn;
        sf::Texture _ti;
        sf::Sprite _fruit;
        sf::Sprite _snake;
        sf::Sprite _tile;
};

#endif /* SFML_HPP_ */