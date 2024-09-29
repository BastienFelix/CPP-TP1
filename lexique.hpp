#define lexique_hpp
#define utilitaire_hpp
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#pragma once

using namespace std;

class Lexique
{

private:
    vector<string> separerStringEnVecteurMots(const string &content);
    map<string, unsigned int> lexique = {};

public:
    Lexique();
    map<string, unsigned int> getLexique();
    void creerLexique(string &content);
    int nb_mots_differents();
    void exporterLexique(string name);
    void supprimer_mot(string mot);
    Lexique &operator+=(const Lexique &other);
    Lexique &operator-=(Lexique &other);
};

ostream &operator<<(ostream &os, map<string, unsigned int> &lexique);
