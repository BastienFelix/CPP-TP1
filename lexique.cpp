#include "lexique.hpp"
#include <sstream> // Include the sstream header

using namespace std;

Lexique::Lexique() {};

map<string, unsigned int> Lexique::getLexique()
{
    return lexique;
}

vector<string> Lexique::separerStringEnVecteurMots(const string &content)
{
    vector<string> tab;
    istringstream stream(content);
    string word;
    while (stream >> word)
    {
        tab.push_back(word);
    }

    return tab;
}

void Lexique::creerLexique(string &content)
{
    vector<string> mots = Lexique::separerStringEnVecteurMots(content);
    unsigned int nb_occurences = 0;

    for (int i = 0; i < mots.size(); i++)
    {
        if (lexique.find(mots[i]) == lexique.end())
        {
            lexique[mots[i]] = 1;
        }
        else
        {
            lexique[mots[i]] = lexique[mots[i]] + 1;
        }
    }
}

int Lexique::nb_mots_differents()
{
    if (lexique.empty())
    {
        cout << "Le lexique est vide" << endl;
        return 0;
    }
    else
    {
        return lexique.size();
    }
}

void Lexique::exporterLexique(string name)
{
    if (lexique.empty())
    {
        cout << "Le lexique n'a pas été créé" << endl;
        return;
    }

    ofstream fichier(name);

    if (fichier.is_open())
    {
        for (const auto &entry : lexique)
        {
            fichier << entry.first << " " << entry.second << "\n";
        }
        fichier.close();
    }
}

void Lexique::supprimer_mot(string mot)
{
    if (lexique.empty())
    {
        cout << "Le lexique n'a pas été créé" << endl;
        return;
    }

    if (lexique.find(mot) != lexique.end())
    {
        lexique.erase(mot);
    }
}

/************************************************ */
/*             Surcharge d'opérateurs             */
/************************************************ */

ostream &operator<<(ostream &os, map<string, unsigned int> &lexique)
{
    for (const auto &pair : lexique)
    {
        os << pair.first << ": " << pair.second << endl;
    }
    return os;
}

Lexique &Lexique::operator+=(const Lexique &other)
{
    for (const auto &data : other.lexique)
    {
        if (this->lexique.find(data.first) == this->lexique.end())
        {
            this->lexique[data.first] = data.second;
        }
        else
        {
            this->lexique[data.first] += data.second;
        }
    }
    return *this;
}

Lexique &Lexique::operator-=(Lexique &other)
{
    for (const auto &data : other.lexique)
    {
        this->lexique.erase(data.first);
    }

    return *this;
}