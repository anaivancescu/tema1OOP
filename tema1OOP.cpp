

#include "structs.h"
void test_adauga()
{
    cout << "test_adauga:\n\n";
    Lista v;
    cout << v;
    v.Add(1, 0);  // 1
    v.Add(2, 0);  // 2 1
    v.Add(3, 0);  // 3 2 1
    v.Add(4, 0);  // 4 3 2 1
    v.Add(5, 14); // 4 3 2 1 5
    v.Add(6, 1);  // 4 6 3 2 1 5
    v.Add(7, 1);  // 4 7 6 3 2 1 5
    v.Add(8, 2);  // 4 7 8 6 3 2 1 5
    cout << v;
    cout << "\n---------------\n";

    v.Clear();
}

void test_citeste_si_scrie() {
    cout << "test_citire:\n\n";
    Lista v;
    cout << "mai intai, se citeste <N>, care reprezinta nr de adaugari in lista\n"
        << "apoi <N> tupluri de forma <VAL POZ>\n"
        << "exemplu de citire:     4 10 0 15 1 20 2 30 3  -> va crea lista (10, 15, 20 ,30)\n\n";
    cin >> v;
    cout << v;
    cout << "\n---------------\n";

    v.Clear();
}

void test_sterge() {
    cout << "test_sterge:\n\n";
    Lista v;
    cout << v;
    v.Add(1, 0);  // 1
    v.Add(2, 0);  // 2 1
    v.Add(3, 0);  // 3 2 1
    v.Add(4, 0);  // 4 3 2 1
    v.Add(5, 14); // 4 3 2 1 5
    v.Add(6, 1);  // 4 6 3 2 1 5
    v.Add(7, 1);  // 4 7 6 3 2 1 5
    v.Add(8, 2);  // 4 7 8 6 3 2 1 5
    v.Delete(0); // 7 8 6 3 2 1 5
    v.Delete(0); // 8 6 3 2 1 5
    v.Delete(1); // 8 3 2 1 5
    v.Delete(2); // 8 3 1 5
    cout << v;
    cout << "\n---------------\n";

    v.Clear();
}
void test_plus()
{
    cout << "test_plus:\n\n";
    Lista v, q;
    cout << v;
    v.Add(1, 0);  // 1
    v.Add(2, 0);  // 2 1
    v.Add(3, 0);  // 3 2 1
    v.Add(4, 0);  // 4 3 2 1

    q.Add(5, 0); // 5
    q.Add(6, 0);  // 6 5
    q.Add(7, 0);  // 7 6 5
    q.Add(8, 0);  // 8 7 6 5

    cout << "V:\n" << v;
    cout << "\n\nQ:\n" << q;
    Lista rezultat = v + q;
    cout << "\n\nV + Q:\n" << rezultat;
    rezultat = rezultat + v;
    cout << "\n\nV + Q + V:\n" << rezultat;

    rezultat = rezultat + v;
    cout << "\n\nV + Q + V + V:\n" << rezultat;

    rezultat = rezultat + q;
    cout << "\n\nV + Q + V + V + Q:\n" << rezultat;
    cout << "\n---------------\n";

    v.Clear();
    q.Clear();
}

int main() {
   test_adauga();
    test_sterge();
    test_plus();
    test_citeste_si_scrie();
}
