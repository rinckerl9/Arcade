/*
** EPITECH PROJECT, 2021
** Arcade Library
** File description:
** SDL2.hpp
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "../../../../core/include/Object.hpp"
#include <memory>
#include "../../../../core/include/IDisplayModule.hpp"

class SDL2 : public IDisplayModule {
    public:
        SDL2();
        ~SDL2() = default;

        void createWindow(void) {};
        bool isWindowOpen(void) const { return false; };
        void closeWindow(void) {};
        void refreshWindow(void) {};
        void clearWindow(void) {};
        void checkWindowEvent(void) {};
        move_t getMovement(void) {};
        void refreshTimer(void) {};
        bool isDelayed(void) { return false; };
        void loadTexture(std::vector<std::shared_ptr<Object>> &obj) { (void) obj; };
        void createSprite(void) {};
        void drawMap(void) {};
        void drawPlayer(std::shared_ptr<Object> player) { (void) player; };
        void drawFruit(std::shared_ptr<Object> fruit) { (void) fruit; };
};

#endif /* SDL2_HPP_ */