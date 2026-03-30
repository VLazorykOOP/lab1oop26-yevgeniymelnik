#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


void task1();
void task2();
void task3();
void showMenu();

int main() {
    int choice;
    do {
        showMenu();
        cout << "Vash vybir: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Vykhid..." << endl; break;
            default: cout << "Nevirnyi punkt menu!" << endl;
        }
        cout << "\n-----------------------------\n";
    } while (choice != 0);

    return 0;
}

void showMenu() {
    cout << "\n--- Laboratorna robota (Variant 12) ---" << endl;
    cout << "1. Zavdannya 1: Serednye aryfmetychne (dynamichnyi masyv)" << endl;
    cout << "2. Zavdannya 2: Ostanniy minimalnyi element (vector)" << endl;
    cout << "3. Zavdannya 3: Min(Max) dlya matrytsi n x m" << endl;
    cout << "0. Vykhid" << endl;
}


void task1() {
    int n;
    cout << "\n[Zavdannya 1] Vvedit rozmir masyvu N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Rozmir mae buty dodatnym!" << endl;
        return;
    }

    double* A = new double[n];
    double sum = 0;

    cout << "Vvedit elementy masyvu:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "] = ";
        cin >> A[i];
        sum += A[i];
    }

    cout << "Serednye aryfmetychne: " << sum / n << endl;
    delete[] A;
}


void task2() {
    int n;
    double T1, T2;
    cout << "\n[Zavdannya 2] Vvedit rozmir vektora N: ";
    cin >> n;
    cout << "Vvedit T1: "; cin >> T1;
    cout << "Vvedit T2: "; cin >> T2;

    vector<double> A(n);
    cout << "Vvedit elementy vektora:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "] = ";
        cin >> A[i];
    }

    int firstT2Index = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] == T2) {
            firstT2Index = i;
            break;
        }
    }

    if (firstT2Index == -1 || firstT2Index == n - 1) {
        cout << "T2 ne znaydeno abo pislya nyoho nemae elementiv." << endl;
        return;
    }

    double minVal = 1e18;
    int lastMinIndex = -1;
    bool found = false;

    for (int i = firstT2Index + 1; i < n; i++) {
        if (A[i] < T1) {
            if (A[i] <= minVal) {
                minVal = A[i];
                lastMinIndex = i;
                found = true;
            }
        }
    }

    if (found) {
        cout << "Nomer ostannoho minimalnoho: " << lastMinIndex << endl;
        cout << "Znachennya: " << minVal << endl;
    } else {
        cout << "Elementiv ne znaydeno." << endl;
    }
}


void task3() {
    int n, m;
    cout << "\n[Zavdannya 3] Vvedit n (ryadky, max 100): "; cin >> n;
    cout << "Vvedit m (stovptsi, max 15): "; cin >> m;

    if (n <= 0 || n > 100 || m <= 0 || m > 15) {
        cout << "Neprypustymi rozmiry matrytsi!" << endl;
        return;
    }


    vector<vector<double>> A(n, vector<double>(m));
    vector<double> rowMaxes;

    cout << "Vvedit elementy matrytsi:" << endl;
    for (int i = 0; i < n; i++) {
        double currentMax = -1e18; 
        for (int j = 0; j < m; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
            if (A[i][j] > currentMax) {
                currentMax = A[i][j];
            }
        }
        rowMaxes.push_back(currentMax);
    }


    double V = rowMaxes[0];
    for (int i = 1; i < n; i++) {
        if (rowMaxes[i] < V) {
            V = rowMaxes[i];
        }
    }

    cout << "\nRezultat V (min sered max ryadkiv) = " << V << endl;
}
