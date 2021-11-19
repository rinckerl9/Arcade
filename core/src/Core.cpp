/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** Core.cpp
*/

#include <ctime>
#include <memory>
#include "../include/IGameModule.hpp"
#include "../include/IDisplayModule.hpp"
#include <dlfcn.h>
#include "../include/DLLoader.hpp"
#include "../include/Error.hpp"
#include <iostream>
#include <map>
#include <string>
#include "../include/Core.hpp"

Core::Core(const std::string &filepath)
{
    this->_filepath = filepath;
}

template<typename T>
T *Core::LoadLibrary(std::unique_ptr<DLLoader> &Loader, const std::string &filepath, const std::string &symbol)
{
    void *ptr = NULL;
    T *(*Library)();
    char *e = NULL;

    ptr = Loader->ldopen(filepath, RTLD_NOW);
    e = Loader->lderror();
    if (ptr == NULL && e != NULL)
        throw Error(e);
    Library = reinterpret_cast<T *(*)()>(Loader->ldsym(ptr, symbol.c_str()));
    e = Loader->lderror();
    if (Library == NULL && e != NULL)
        throw Error(e);
    if (std::is_same<T, IDisplayModule>::value)
        this->_grHandle = ptr;
    else if (std::is_same<T, IGameModule>::value)
        this->_gaHandle = ptr;
    else
        return (nullptr);
    return ((T *)Library());
}

std::vector<std::shared_ptr<Object>> Core::ObjectLoader(int game)
{
    std::vector<std::shared_ptr<Object>> obj;

    if (game == 1) {
        obj.push_back(std::make_shared<Object> ("lib/games/nibbler/assets/white.png"));
        obj.push_back(std::make_shared<Object> ("lib/games/nibbler/assets/green.png"));
        obj.push_back(std::make_shared<Object> ("lib/games/nibbler/assets/red.png"));
    }
    return (obj);
}

int Core::GameLoop(void)
{
    move_t movement;
    std::unique_ptr<DLLoader> Loader (std::make_unique<DLLoader>());
    this->_graphicalLib = LoadLibrary<IDisplayModule>(Loader, this->_filepath, "CreateGraphicalLibrary");
    this->_gameLib = LoadLibrary<IGameModule>(Loader, "./lib/arcade_nibbler.so", "CreateGameLibrary");
    std::vector<std::shared_ptr<Object>> obj;

    std::srand(std::time(nullptr));
    obj = ObjectLoader(1);
    this->_graphicalLib->loadTexture(obj);
    this->_graphicalLib->createSprite();
    this->_graphicalLib->createWindow();
    while (this->_graphicalLib->isWindowOpen()) {
        this->_graphicalLib->refreshTimer();
        this->_graphicalLib->checkWindowEvent();
        movement = this->_graphicalLib->getMovement();
        if (this->_graphicalLib->isDelayed() == true)
            this->_gameLib->gameLogic(movement, obj[1], obj[2]);
        this->_graphicalLib->clearWindow();
        this->_graphicalLib->drawMap();
        this->_graphicalLib->drawPlayer(obj[1]);
        this->_graphicalLib->drawFruit(obj[2]);
        this->_graphicalLib->refreshWindow();
    }
    Loader->ldclose(this->_grHandle);
    Loader->ldclose(this->_gaHandle);
    return (0);
}