/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** IDisplayModule.hpp
*/

#ifndef IDISPLAY_MODULE_HPP_
#define IDISPLAY_MODULE_HPP_

#include <map>
#include <vector>
#include "Object.hpp"
#include "Error.hpp"

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE,
} move_t;

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;

        virtual void createWindow(void) = 0;
        virtual bool isWindowOpen(void) const = 0;
        virtual void closeWindow(void) = 0;
        virtual void refreshWindow(void) = 0;
        virtual void clearWindow(void) = 0;
        virtual void checkWindowEvent(void) = 0;
        virtual move_t getMovement(void) = 0;
        virtual void refreshTimer(void) = 0;
        virtual bool isDelayed(void) = 0;
        virtual void loadTexture(std::vector<std::shared_ptr<Object>> &obj) = 0;
        virtual void createSprite(void) = 0;
        virtual void drawMap(void) = 0;
        virtual void drawPlayer(std::shared_ptr<Object> player) = 0;
        virtual void drawFruit(std::shared_ptr<Object> fruit) = 0;
};

#endif /* IDISPLAY_MODULE_HPP_ */