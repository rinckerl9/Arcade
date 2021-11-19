/*
** EPITECH PROJECT, 2021
** Arcade Library
** File description:
** Ncurses.cpp
*/

#include <iostream>
#include "../include/Ncurses.hpp"

Ncurses::Ncurses()
{
    std::cerr << "Not implemented yet" << "\n";
}

extern "C"
{
    IDisplayModule *CreateGraphicalLibrary() {
        return (new Ncurses);
    }
}