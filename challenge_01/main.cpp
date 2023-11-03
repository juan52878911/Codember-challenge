#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Declaramos la variable que contendra el string a cifrar
string challenge = "murcielago leon jirafa cebra elefante rinoceronte hipopotamo ardilla mapache zorro lobo oso puma jaguar tigre leopardo gato perro caballo vaca toro cerdo oveja cabra gallina pato ganso pavo paloma halcon aguila buho colibri canario loro tucan pinguino flamenco tigre jaguar leopardo oso lobo zorro mapache ardilla elefante rinoceronte hipopotamo cebra jirafa leon murcielago cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago buho aguila halcon paloma pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago colibri buho aguila halcon paloma pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago tucan loro canario colibri buho aguila halcon paloma pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago flamenco pinguino tucan loro canario colibri buho aguila halcon paloma pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago jaguar oso lobo zorro mapache ardilla cebra elefante rinoceronte hipopotamo leon jirafa murcielago caballo vaca toro cerdo oveja cabra gallina pato ganso pavo paloma halcon aguila buho colibri canario loro tucan pinguino flamenco jaguar oso lobo zorro mapache ardilla cebra elefante rinoceronte hipopotamo leon jirafa murcielago caballo vaca toro cerdo oveja cabra gallina pato ganso pavo paloma halcon aguila buho colibri canario loro tucan pinguino flamenco murcielago leon jirafa cebra elefante rinoceronte hipopotamo ardilla mapache zorro lobo oso puma jaguar tigre leopardo gato perro caballo vaca toro cerdo oveja cabra gallina pato ganso pavo paloma halcon aguila buho colibri canario loro tucan pinguino flamenco oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago cabra oveja cerdo toro vaca caballo perro gato leopardo tigre jaguar oso lobo zorro mapache ardilla cebra elefante rinoceronte hipopotamo jirafa leon murcielago pavo ganso pato gallina cabra oveja cerdo toro vaca caballo perro gato buho aguila halcon paloma colibri canario loro tucan pinguino flamenco jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago cabra oveja cerdo toro vaca caballo perro gato buho aguila halcon paloma colibri canario loro tucan pinguino flamenco jaguar oso lobo zorro mapache ardilla hipopotamo rinoceronte elefante jirafa leon murcielago cabra oveja cerdo toro vaca caballo perro gato buho aguila halcon";

/** split function
 * @param str string to split
 * @param delim delimiter
 * @return string array with the split string
*/
vector<string> split(const string &str, const string &delim) {
    vector<string> words;
    size_t start = 0, end = 0;
    while ((end = str.find(delim, start)) != string::npos) {
        words.push_back(str.substr(start, end - start));
        start = end + delim.length();
    }
    words.push_back(str.substr(start));
    return words;
}

/** To lowercase
 * @param str string to convert
 * @return string converted to lowercase
 */
string stoLower(string str){
    for (int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

struct Word{
    string word;
    int count;
    int index;
};

int main() {

    vector<string> words = split(challenge, " ");
    vector<Word> wordsCount;

    // Recorremos el vector de palabras para encontrar las palabras repetidas y numerarlas EJ: llaveS casa CASA casa llaves -> llaves2casa3
    for (int i = 0; i < words.size(); i++) {
        int count = 0;
        for (int j = 0; j < words.size(); j++) {
            if (stoLower(words[i]) == stoLower(words[j])) {
                count++;
            }
        }

        // Verificamos que la palabra no este ya en el vector de palabras contadas
        bool exist = false;
        for (int j = 0; j < wordsCount.size(); j++) {
            if (stoLower(words[i]) == stoLower(wordsCount[j].word)) {
                exist = true;
            }
        }

        // Si la palabra no esta en el vector de palabras contadas, la agregamos
        if (!exist) {
            Word word;
            word.word = words[i];
            word.count = count;
            word.index = i;
            wordsCount.push_back(word);
        }
    }

    // Mostramos las palabras encontradas ordenadas por indice sin espacios
    for (int i = 0; i < wordsCount.size(); i++) {
        cout << wordsCount[i].word << wordsCount[i].count;
    }
    return 0;
}