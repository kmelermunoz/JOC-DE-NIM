// Implementació de llibreries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Inicialització de la llavor per a generar nombres aleatoris
    srand(time(0));

    // Missatges de benvinguda i introducció al joc
    cout << "BENVINGUT AL JOC NIM!" << endl;
    cout << "Hi ha 3 muntanyes de pedres amb 3, 4 i 5 pedres respectivament." << endl;
    cout << "Guanya el jugador que retiri l'última pedra!" << endl;

    // Inicialització de les piles de pedres a cada muntanya
    int piles[] = { 3, 4, 5 };

    // Bucle principal del joc
    while (true) {
        // Mostra l'estat actual del joc (quantitat de pedres a cada muntanya)
        cout << "\nEstat actual del joc: ";
        for (int i = 0; i < 3; ++i) {
            cout << piles[i] << " ";
        }
        cout << endl;

        // Torn del jugador
        int pileIndex, stonesToRemove;
        cout << "El teu torn - Escull una muntanya (0, 1, 2): ";
        cin >> pileIndex;

        // Verifica la validesa del moviment del jugador
        if (pileIndex < 0 || pileIndex >= 3 || piles[pileIndex] == 0) {
            cout << "Moviment invàlid! Torna-ho a provar." << endl;
            continue;
        }

        cout << "Quantes pedres vols retirar (1-3)? ";
        cin >> stonesToRemove;

        if (stonesToRemove < 1 || stonesToRemove > 3 || stonesToRemove > piles[pileIndex]) {
            cout << "Moviment invàlid! Torna-ho a provar." << endl;
            continue;
        }

        // Actualitza l'estat de la muntanya després del moviment del jugador
        piles[pileIndex] -= stonesToRemove;

        // Verifica si el jugador ha guanyat
        if (piles[0] == 0 && piles[1] == 0 && piles[2] == 0) {
            cout << "Felicitats! Has guanyat!" << endl;
            break;
        }

        // Torn de la computadora
        int compPile = rand() % 3;
        int compStones = rand() % min(3, piles[compPile]) + 1;

        cout << "La computadora retira " << compStones << " pedres de la muntanya " << compPile << endl;

        // Actualitza l'estat de la muntanya després del moviment de la computadora
        piles[compPile] -= compStones;

        // Verifica si la computadora ha guanyat
        if (piles[0] == 0 && piles[1] == 0 && piles[2] == 0) {
            cout << "La computadora guanya! Sort en la propera." << endl;
            break;
        }
    }

    return 0;
}
