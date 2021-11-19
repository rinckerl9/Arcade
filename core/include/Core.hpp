/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** Core.hpp
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <map>
#include "Object.hpp"
#include "DLLoader.hpp"
#include <memory>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include <string>

class Core {
    public:
        Core(const std::string &filepath);
        ~Core() = default;

        int GameLoop(void);
        template<typename T>
        T *LoadLibrary(std::unique_ptr<DLLoader> &Loader, const std::string &filepath, const std::string &symbol);
        std::vector<std::shared_ptr<Object>> ObjectLoader(int game);
    private:
        std::string _filepath;
        void *_gaHandle;
        void *_grHandle;
        IDisplayModule *_graphicalLib;
        IGameModule *_gameLib;
};

#endif /* CORE_HPP_ */