/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** main.cpp
*/

#include "../include/Core.hpp"
#include <memory>
#include "../include/Error.hpp" 
#include <iostream>

static int my_strncmp(char const *s1, char const *s2, size_t n)
{
    size_t i = 0;

    while ((*s1 && *s2) && (i < n)) {
        *s1++;
        *s2++;
    }
    return (*s2 - *s1);
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strncmp(argv[1], "-h", 2) == 0) {
        std::cout << "USAGE: ./arcade ./lib/arcade_lib.so" << std::endl;
        return (0);
    } else if (argc == 2) {
        try {
            std::string filepath (argv[1]);
            std::unique_ptr<Core> Arcade (std::make_unique<Core> (filepath));
            Arcade->GameLoop();
        } catch (const Error &e) {
            std::cerr << e.what() << std::endl;
            return (84);
        }
    } else {
        std::cerr << "Bad args, retry with -h" << std::endl;
        return (84);
    }
}