#include "utilitaire.hpp"
#include "lexique.hpp"
#include "lexiqueAmeliore.hpp"
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    LexiqueAmeliore lesMiserables;
    string content;

    readFileIntoString("Lexique-fichiers/lesMiserables_A.txt", content);
    remove_punctuation(content);

    lesMiserables.creerLexiqueAmeliore(content);
    map<string, unsigned int> lexique = lesMiserables.getLexique();

    lesMiserables.afficherLignes("les");

    return 0;
}
