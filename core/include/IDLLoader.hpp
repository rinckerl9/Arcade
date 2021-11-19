/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** IDLLoader.hpp
*/

#ifndef IDLLOADER_HPP_
#define IDLLOADER_HPP_

#include <string>

class IDLLoader {
    public:
        virtual ~IDLLoader() = default;

        virtual void *ldopen(const std::string &filepath, int flag) = 0;
        virtual char *lderror(void) = 0;
        virtual void *ldsym(void *handle, char const *symbol) = 0;
        virtual int ldclose(void *handle) = 0;

        /* Getters */
        virtual const std::string GetFilepath(void) const = 0;
        /* Getters */

        /* Setters */
        virtual void SetFilepath(const std::string &filepath) = 0;
        /* Setters */
};

#endif /* IDLLOADER_HPP_ */