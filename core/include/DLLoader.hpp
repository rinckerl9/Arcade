/*
** EPITECH PROJECT, 2021
** Arcade Core
** File description:
** DLLoader.hpp
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>
#include "IDLLoader.hpp"

class DLLoader : public IDLLoader {
    public:
        DLLoader();
        DLLoader(const std::string &filepath);
        ~DLLoader();

        void *ldopen(const std::string &filepath, int flag);
        char *lderror(void);
        void *ldsym(void *handle, char const *symbol);
        int ldclose(void *handle);

        /* Getters */
        const std::string GetFilepath(void) const;
        /* Getters */

        /* Setters */
        void SetFilepath(const std::string &filepath);
        /* Setters */
    private:
        std::string _filepath;
};

#endif /* DLLOADER_HPP_ */