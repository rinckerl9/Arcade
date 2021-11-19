/*
** EPITECH PROJECT, 2021
** Arcade Library
** File description:
** SFML.cpp
*/

#include "../../../../core/include/Object.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include "../include/SFML.hpp"

SFML::SFML()
{
    this->_window = NULL;
    this->_timer = 0.0;
    this->_delay = 0.1;
    this->_clock = std::make_shared<sf::Clock> ();
}

void SFML::createWindow(void)
{
    if (this->_window == NULL)
        this->_window = std::make_shared<sf::RenderWindow> (sf::VideoMode(800, 600, 32), "Arcade");
    this->_window->setFramerateLimit(60);
}

bool SFML::isWindowOpen(void) const
{
    return (this->_window->isOpen());
}

void SFML::closeWindow(void)
{
    this->_window->close();
}

void SFML::refreshWindow(void)
{
    this->_window->display();
}

void SFML::clearWindow(void)
{
    this->_window->clear();
}

void SFML::checkWindowEvent(void)
{
    sf::Event e;

    while (this->_window->pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            this->closeWindow();
        }
    }
}

move_t SFML::getMovement(void)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        return (UP);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        return (DOWN);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return (LEFT);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return (RIGHT);
    return (NONE);
}

void SFML::refreshTimer(void)
{
    this->_time = this->_clock->getElapsedTime().asSeconds();
    this->_clock->restart();
    this->_timer += this->_time;
}

bool SFML::isDelayed(void)
{
    if (this->_timer > this->_delay) {
        this->_timer = 0;
        return (true);
    }
    return (false);
}

const std::string Object::getFilepath(void)
{
    return (this->_filepath);
}

void SFML::loadTexture(std::vector<std::shared_ptr<Object>> &obj)
{
    this->_ti.loadFromFile(obj[0]->getFilepath());
    this->_sn.loadFromFile(obj[1]->getFilepath());
    this->_fr.loadFromFile(obj[2]->getFilepath());
}

void SFML::createSprite(void)
{
    this->_tile = sf::Sprite(this->_ti);
    this->_snake = sf::Sprite(this->_sn);
    this->_fruit = sf::Sprite(this->_fr);
}

void SFML::drawMap(void)
{
    for (unsigned int i = 0; i < 50; i++) {
        for (unsigned int j = 0; j < 38; j++) {
            this->_tile.setPosition((i * 16), (j * 16));
            this->_window->draw(this->_tile);
        }
    }
}

void SFML::drawPlayer(std::shared_ptr<Object> player)
{
    for (unsigned int i = 0; i < player->size; i++) {
        this->_snake.setPosition((player->spos[i].x * 16), (player->spos->y * 16));
        this->_window->draw(this->_snake);
    }
}

void SFML::drawFruit(std::shared_ptr<Object> fruit)
{
    this->_fruit.setPosition((fruit->pos.x * 16), (fruit->pos.y * 16));
    this->_window->draw(this->_fruit);
}

extern "C"
{
    IDisplayModule *CreateGraphicalLibrary() {
        return (new SFML);
    }
}