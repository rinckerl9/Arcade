/*
** EPITECH PROJECT, 2021
** Arcade Game
** File description:
** Nibbler.hpp
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "../../../../core/include/Object.hpp"
#include <memory>
#include "../../../../core/include/IGameModule.hpp"

class Nibbler : public IGameModule {
    public:
        Nibbler();
        ~Nibbler() = default;

    void gameLogic(move_t movement, std::shared_ptr<Object> player, std::shared_ptr<Object> fruit);
};

#endif /* NIBBLER_HPP_ */