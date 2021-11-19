/*
** EPITECH PROJECT, 2021
** Arcade Game
** File description:
** Pacman.hpp
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../../../core/include/Object.hpp"
#include <memory>
#include "../../../../core/include/IGameModule.hpp"

class Pacman : public IGameModule {
    public:
        Pacman();
        ~Pacman() = default;

        void gameLogic(move_t movement, std::shared_ptr<Object> player, std::shared_ptr<Object> fruit);
};

#endif /* PACMAN_HPP_ */