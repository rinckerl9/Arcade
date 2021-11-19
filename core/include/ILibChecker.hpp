/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** LibChecker.hpp
*/

#ifndef ILIB_CHECKER_HPP_
#define ILIB_CHECKER_HPP_

#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>

class ILibChecker {
    public:
        virtual ~ILibChecker() = default;

        virtual DIR *OpenDir(const std::string &filepath) = 0;
        virtual std::vector<std::string> ReadDir(DIR *dirp) = 0;
        virtual std::vector<std::string> GetFiles(void) const = 0;
};

#endif /* ILIB_CHECKER_HPP_ */