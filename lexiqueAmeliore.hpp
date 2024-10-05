#ifndef LEXIQUE_AMELIORE_HPP
#define LEXIQUE_AMELIORE_HPP

#include "lexique.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#pragma once

using namespace std;

class LexiqueAmeliore : public Lexique
{
private:
    map<string, vector<int>> lignes;

public:
    LexiqueAmeliore();
    void creerLexiqueAmeliore(string &content);
    void afficherLignes(const string &mot);
};

#endif