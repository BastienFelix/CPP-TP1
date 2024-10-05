#include "lexiqueAmeliore.hpp"
#include <sstream>
#include <algorithm>

using namespace std;

LexiqueAmeliore::LexiqueAmeliore() : Lexique() {}

void LexiqueAmeliore::creerLexiqueAmeliore(string &content)
{
    istringstream stream(content);
    string ligne;
    int numeroLigne = 0;

    while (getline(stream, ligne))
    {
        numeroLigne++;
        istringstream lineStream(ligne);
        string mot;
        while (lineStream >> mot)
        {
            lignes[mot].push_back(numeroLigne);
        }
    }
}

void LexiqueAmeliore::afficherLignes(const string &mot)
{
    if (lignes.find(mot) != lignes.end())
    {
        cout << "Le mot \"" << mot << "\" a été trouvé aux lignes : ";
        for (int ligne : lignes[mot])
        {
            cout << ligne << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Le mot \"" << mot << "\" n'a pas été trouvé." << endl;
    }
}