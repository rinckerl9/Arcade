/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** LibChecker.cpp
*/

#include "../include/Error.hpp"
#include <vector>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include "../include/LibChecker.hpp"

LibChecker::LibChecker(const std::string &filepath)
{
    this->_filepath = filepath;
    this->_dirp = this->OpenDir(this->_filepath);
    this->_files = ReadDir(this->_dirp);
}

DIR *LibChecker::OpenDir(const std::string &filepath)
{
    return (opendir(filepath.c_str()));
}

std::vector<std::string> LibChecker::ReadDir(DIR *dirp)
{
    std::size_t pos (0);
    std::vector<std::string> files;
    struct dirent *entry = NULL;

    while ((entry = readdir(dirp)) != NULL) {
        files.push_back(entry->d_name);
    }
    for (unsigned int i = 0; i < files.size(); i++) {
        if ((pos = files[i].find(".so")) != std::string::npos) {
            continue;
        } else {
            files[i].erase();
        }
    }
    if (files.empty() == true)
        throw Error("Error: no .so found in ./lib/");
    return (files);
}

std::vector<std::string> LibChecker::GetFiles(void) const
{
    return (this->_files);
}