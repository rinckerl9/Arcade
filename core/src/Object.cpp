/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** Object.cpp
*/

#include "../include/Object.hpp"

Object::Object(const std::string &filepath)
{
    this->_filepath = filepath;
}

const std::string Object::getFilepath(void)
{
    return (this->_filepath);
}