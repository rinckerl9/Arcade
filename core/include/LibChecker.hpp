/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** LibChecker.hpp
*/

#ifndef LIB_CHECKER_HPP_
#define LIB_CHECKER_HPP_

#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include "../include/ILibChecker.hpp"

class LibChecker : public ILibChecker {
    public:
        LibChecker(const std::string &filepath);
        ~LibChecker() = default;

        DIR *OpenDir(const std::string &filepath);
        std::vector<std::string> ReadDir(DIR *dirp);

        std::vector<std::string> GetFiles(void) const;
    private:
        std::string _filepath;
        DIR *_dirp;
        std::vector<std::string> _files;
};

#endif /* LIB_CHECKER_HPP_ */