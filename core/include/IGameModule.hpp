/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** IGameModule.hpp
*/

#ifndef IGAME_MODULE_HPP_
#define IGAME_MODULE_HPP_

#include "Object.hpp"
#include <memory>
#include "IDisplayModule.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;

        virtual void gameLogic(move_t movement, std::shared_ptr<Object> player, std::shared_ptr<Object> fruit) = 0;
};

#endif /* IGAME_MODULE_HPP_ */