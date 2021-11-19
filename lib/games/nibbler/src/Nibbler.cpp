/*
** EPITECH PROJECT, 2021
** Arcade Game
** File description:
** Nibbler.cpp
*/
#include "../../../../core/include/Object.hpp"
#include <memory>
#include <iostream>
#include "../include/Nibbler.hpp"

Nibbler::Nibbler()
{

}

void Nibbler::gameLogic(move_t movement, std::shared_ptr<Object> player, std::shared_ptr<Object> fruit)
{
    for (unsigned int i = player->size; i > 0; i--) {
        player->spos[i].x = player->spos[i - 1].x;
        player->spos[i].y = player->spos[i - 1].y;
    }
    switch (movement) {
    case UP:
        player->spos[0].y -= 1;
        break;
    case DOWN:
        player->spos[0].y += 1;
        break;
    case LEFT:
        player->spos[0].x -= 1;
        break;
    case RIGHT:
        player->spos[0].x += 1;
        break;
    default:
        break;
    }
    if ((player->spos[0].x == fruit->pos.x) && (player->spos[0].y == fruit->pos.y)) {
        player->size += 1;
        fruit->pos.x = std::rand() % 50;
        fruit->pos.y = std::rand() % 30;
    }
    if (player->spos[0].x > 800) {
        player->spos[0].x = 0;
    }
    if (player->spos[0].x < 0) {
        player->spos[0].x = 800;
    }
    if (player->spos[0].y > 600) {
        player->spos[0].y = 0;
    }
    if (player->spos[0].y < 0) {
        player->spos[0].y = 600;
    }
    for (unsigned int i = 1; i < player->size; i++) {
        if ((player->spos[0].x == player->spos[i].x) && (player->spos[0].y == player->spos[i].y)) {
            player->size = i;
        }
    }
}

extern "C"
{
    IGameModule *CreateGameLibrary() {
        return (new Nibbler);
    }
}