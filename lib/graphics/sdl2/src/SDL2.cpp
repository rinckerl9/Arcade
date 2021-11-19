/*
** EPITECH PROJECT, 2021
** Arcade Library
** File description:
** SDL2.cpp
*/

#include <iostream>
#include "../include/SDL2.hpp"

SDL2::SDL2()
{
    std::cerr << "Not implemented yet" << "\n";
}

extern "C"
{
    IDisplayModule *CreateGraphicalLibrary() {
        return (new SDL2);
    }
}