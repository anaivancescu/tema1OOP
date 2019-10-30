#pragma once


#include <iostream>
using namespace std;

class Nod
{
public:
    Nod(int _value)
        :value(_value), next(nullptr), prev(nullptr)
    {

    };
    ~Nod() {
        // daca un vecin avea muchie catre nodul curent la distrugerea lui
        // sterg acele muchii
        if (nullptr != next && next->GetPrev() == this) {
            next->SetPrev(nullptr);
        }
        if (nullptr != prev && prev->GetNext() == this) {
            prev->SetNext(nullptr);
        }
    };
    int GetValue() {
        return value;
    }
    Nod* GetNext() {
        return next;
    }
    Nod* GetPrev() {
        return prev;
    }

    void SetNext(Nod* _next) {
        next = _next;
    }
    void SetPrev(Nod* _prev) {
        prev = _prev;
    }

private:
    int value;
    Nod *prev = nullptr;
    Nod *next = nullptr;

};

class Lista {

public:
    Lista() : primul(nullptr), ultimul(nullptr)
    {
    }
    ~Lista() {
        // nu pot face Clear pe destructor pentru ca
        // destructorul se apeleaza implicit la sfarsitul operatorului de "+"
        // si in " a = b + c ", "a" ar deveni o lista goala
        // b + c -> return {rezultat} -> destructor(rezultat) -> a devine lista goala
    }

    void Clear() {
        // eliberez memoria pentru toate nodurile pe destructor
        // cat timp delete(0) returneaza true, inseamna ca a sters un element
        // cand returneaza false, inseamna ca primul == ultimul == nulptr (lista e goala)
        while (Delete(0));
    }

    bool Add(int element, int poz) {
        Nod* ceAdaug = new Nod(element);
        if (!ceAdaug) {
            std::cout << "alocarea nu a reusit, nu mai avem memorie" << endl;
            return false;
        }
        if (nullptr == primul) {
            primul = ultimul = ceAdaug;
            return true;
        }
        if (poz == 0) {
            // adaug la inceputul listei
            primul->SetPrev(ceAdaug);
            ceAdaug->SetNext(primul);
            primul = ceAdaug;
            return true;
        }
        Nod* aux = primul;
        while (aux->GetNext() != nullptr && poz > 1) {
            poz--;
            aux = aux->GetNext();
        }

        Nod* urmatorul = aux->GetNext();
        if (urmatorul != nullptr) {
            urmatorul->SetPrev(ceAdaug);
            ceAdaug->SetNext(urmatorul);
        }
        else {
            ultimul = ceAdaug;
        }

        aux->SetNext(ceAdaug);
        ceAdaug->SetPrev(aux);
        return true;
    }

    // true daca a reusit sa stearga un element, false daca e deja goala
    bool Delete(int poz) {
        // legaturile se sterg automat pe destructorul nodului
        if (primul == nullptr) {
            return false;
        }

        if (primul == ultimul) {
            // doar un element
            delete primul;
            primul = ultimul = nullptr;
            return true;
        }

        Nod* aux = primul;
        if (poz == 0) {
            primul = primul->GetNext();
            delete aux;
            return true;
        }

        while (aux->GetNext() != nullptr && poz > 0) {
            poz--;
            aux = aux->GetNext();
        }

        // (... <-> A <-> aux <-> B <-> ...) devine ( ... <-> A <-> B <-> ... )
        Nod* prev = aux->GetPrev(), * next = aux->GetNext();

        if (prev != nullptr) {
            prev->SetNext(next);
        }
        if (next != nullptr) {
            next->SetPrev(prev);
        }

        delete aux;
        return true;
    }
    friend ostream& operator << (ostream& out, Lista& v)
    {
        if (nullptr == v.primul) {
            out << "lista e goala" << endl;
            return out;
        }
        out << "lista in ordine logica:" << endl;
        Nod* aux = v.primul;
        while (aux != nullptr) {
            out << aux->GetValue() << " ";
            aux = aux->GetNext();
        }
        out << endl << "lista in ordine inversa:" << endl;
        aux = v.ultimul;
        while (aux != nullptr) {
            out << aux->GetValue() << " ";
            aux = aux->GetPrev();
        }
        return out;
    }

    friend istream& operator >> (istream& in, Lista& v)
    {
        int n;
        in >> n;
        for (int i = 0; i < n; i++) {
            int val, poz;
            in >> val >> poz;
            v.Add(val, poz);
        }
        return in;
    }
    Lista operator+(const Lista& param)
    {
        Lista rezultat;
        Nod* aux;

        aux = param.ultimul;
        while (aux != nullptr) {
            rezultat.Add(aux->GetValue(), 0);
            aux = aux->GetPrev();
        }

        aux = ultimul;
        while (aux != nullptr) {
            rezultat.Add(aux->GetValue(), 0);
            aux = aux->GetPrev();
        }


        return rezultat;
    }


private:
    Nod* primul, * ultimul;


};
