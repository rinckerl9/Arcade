/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** DLLoader.cpp
*/

#include <dlfcn.h>
#include "../include/DLLoader.hpp"

DLLoader::DLLoader()
{

}

DLLoader::DLLoader(const std::string &filepath)
{
    this->_filepath = filepath;
}

DLLoader::~DLLoader()
{
    // ???
}

void *DLLoader::ldopen(const std::string &filepath, int flag)
{

    return (dlopen(filepath.c_str(), flag));
}

char *DLLoader::lderror(void)
{
    return (dlerror());
}

void *DLLoader::ldsym(void *handle, char const *symbol)
{
    return (dlsym(handle, symbol));
}

int DLLoader::ldclose(void *handle)
{
    if (handle != NULL)
        return (dlclose(handle));
    else
        return (0);
}

const std::string DLLoader::GetFilepath(void) const
{
    return (this->_filepath);
}

void DLLoader::SetFilepath(const std::string &filepath)
{
    this->_filepath = filepath;
}