/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** Object.hpp
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <string>

typedef struct s_vector {
    int x;
    int y;
} vector2_t;

class Object {
    public:
        Object(const std::string &filepath);
        ~Object() = default;

        const std::string getFilepath(void);
    //private:
        std::string _filepath;
        vector2_t pos;
        vector2_t spos[100];
        size_t size = 4;
};

#endif /* OBJECT_HPP_ */