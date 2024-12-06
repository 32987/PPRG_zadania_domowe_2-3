#include <iostream>
using namespace std;

int getRozmiarFromInput() {
    int rozmiar;
    while (true) {
        cout << "Wpisz rozmiar tablicy: " << endl;
        cin >> rozmiar;
        if (rozmiar <= 0) {
            cout << "Tablica musi miec dodatnia liczbe elementow. Sprobuj jeszcze raz." << endl;
        }
        else {
            break;
        }
    }
    return rozmiar;
}

void zad4_2() {
    int rozmiar = getRozmiarFromInput();
    cout << "Rozmiar tablicy: " << rozmiar << endl;

    int tablica[rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        int element;
        cout << "Wpisz " << i + 1 << ". element tablicy: " << endl;
        cin >> element;
        tablica[i] = element;
    }

    cout << "\nTablica: ";
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << ", ";
    }
    cout << endl;

    //sortowanie tablicy
    bool check = false;
    do {
        check = false;
        for (int i = 0;i < rozmiar - 1;i++) {
            if (tablica[i + 1] < tablica[i]) {
                int pomocnicza = tablica[i];
                tablica[i] = tablica[i + 1];
                tablica[i + 1] = pomocnicza;
                check = true;
            }
        }
    }
    while (check);

    int liczbyWystapienia[2][rozmiar];
    int najwiekszaLiczbaWyst = 0;
    for (int i = 0; i < rozmiar; i++) {
        if (i == 0 || tablica[i] != tablica[i - 1]) {
            int liczba = tablica[i];
            int liczbaWystapien = 0;

            //liczenie ile razy wystepuje dana liczba
            for (int j = 0; j < rozmiar; j++) {
                if (tablica[j] == liczba) {
                    liczbaWystapien++;
                }
            }

            liczbyWystapienia[0][i] = liczba;
            liczbyWystapienia[1][i] = liczbaWystapien;

            if (liczbaWystapien > najwiekszaLiczbaWyst) {
                najwiekszaLiczbaWyst = liczbaWystapien;
            }

            cout << "Liczba " << liczba << " wystepuje " << liczbaWystapien << " razy." << endl;
        }
    }

    string zbiorLiczb;
    for (int i = 0; i < rozmiar; i++) {
        if (liczbyWystapienia[1][i] == najwiekszaLiczbaWyst) {
            zbiorLiczb.append(to_string(liczbyWystapienia[0][i]) + ",");
        }
    }
    zbiorLiczb.pop_back();


    cout << "\nNajczesciej wystepuja liczby {" << zbiorLiczb << "} (" << najwiekszaLiczbaWyst << " razy)." << endl;
}

void zad4_3() {
    int tablicaDwuwymiarowa[10][10];
    for (int i = 0; i < 10; i++) {
        tablicaDwuwymiarowa[i][0] = i;
        tablicaDwuwymiarowa[i][1] = i + i;
        tablicaDwuwymiarowa[i][2] = i * i;
        tablicaDwuwymiarowa[i][3] = i + 3;
        tablicaDwuwymiarowa[i][4] = i - 4;
        for (int j = 5; j < 10; j++) {
            tablicaDwuwymiarowa[i][j] = 0;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << tablicaDwuwymiarowa[i][j] << ", ";
        }
        cout << endl;
    }

}

int main() {
    zad4_2();
    zad4_3();
    return 0;
}
