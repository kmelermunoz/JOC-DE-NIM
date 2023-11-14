#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    cout << "BENVINGUT AL JOC NIM!" << endl;
    cout << "Hi ha 3 muntanyes de pedres amb 3, 4 i 5 pedres respectivament." << endl;
    cout << "Guanya el jugador que retiri l'última pedra!" << endl;

    int piles[] = { 3, 4, 5 };

    while (true) {
        cout << "\nEstat actual del joc: ";
        for (int i = 0; i < 3; ++i) {
            cout << piles[i] << " ";
        }
        cout << endl;

        // Torn del jugador
        int pileIndex, stonesToRemove;
        cout << "El teu torn - Escull una muntanya (0, 1, 2): ";
        cin >> pileIndex;

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

        piles[pileIndex] -= stonesToRemove;

        // Verificar si el jugador ha guanyat
        if (piles[0] == 0 && piles[1] == 0 && piles[2] == 0) {
            cout << "Felicitats! Has guanyat!" << endl;
            break;
        }

        // Torn de la computadora
        int compPile = rand() % 3;
        int compStones = rand() % min(3, piles[compPile]) + 1;

        cout << "La computadora retira " << compStones << " pedres de la muntanya " << compPile << endl;

        piles[compPile] -= compStones;

        // Verificar si la computadora ha guanyat
        if (piles[0] == 0 && piles[1] == 0 && piles[2] == 0) {
            cout << "La computadora guanya! Sort en la propera." << endl;
            break;
        }
    }

    return 0;
}
