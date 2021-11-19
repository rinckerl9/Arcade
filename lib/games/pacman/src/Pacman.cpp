/*
** EPITECH PROJECT, 2021
** Arcade Game
** File description:
** Pacman.cpp
*/

#include <iostream>
#include "../include/Pacman.hpp"

Pacman::Pacman()
{
    std::cerr << "Not implemented yet" << "\n";
}

void Pacman::gameLogic(move_t movement, std::shared_ptr<Object> player, std::shared_ptr<Object> fruit)
{
    (void)movement;
    (void)player;
    (void)fruit;
}

extern "C"
{
    IGameModule *CreateGameLibrary() {
        return (new Pacman);
    }
}