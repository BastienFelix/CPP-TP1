#include "utilitaire.hpp"
#include "lexique.hpp"
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    Lexique lesMiserables;
    Lexique notreDameDeParis;
    string content1;
    string content2;

    readFileIntoString("Lexique-fichiers/lesMiserables_A.txt", content1);
    readFileIntoString("Lexique-fichiers/notreDameDeParis_A.txt", content2);
    remove_punctuation(content1);
    remove_punctuation(content2);
    toLower(content1);
    toLower(content2);

    lesMiserables.creerLexique(content1);
    notreDameDeParis.creerLexique(content2);

    map<string, unsigned int> lexiqueLesMiserables = lesMiserables.getLexique();
    map<string, unsigned int> lexiqueNotreDameDeParis = notreDameDeParis.getLexique();

    notreDameDeParis.exporterLexique("lexiqueNotreDameDeParis.txt");
    lesMiserables.exporterLexique("lexiqueLesMiserables.txt");

    Lexique lexiqueDifference = lesMiserables -= notreDameDeParis;

    lexiqueDifference.exporterLexique("lexiqueDifference.txt");

    return 0;
}
