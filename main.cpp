#include <iostream>


using namespace std;
#define DIM_MAX 10001

//declarare variabile
int lista[10001], n, creat; //lista alocata static de dimensiune 1001
int stiva[DIM_MAX], varf; //stiva alocata static de dimensiune 1001
int coada[DIM_MAX], prim, ultim; //coada alocata static de dimensiune 1001
///ultim - poz ultimului elem coada; ultim <=> varf(stiva) <=> n(lista)
///prim - poz primului elem din coada
void Ecran1()
{
    cout << "Bazele listelor alocate static" << endl;

    cout << "Apasa orice tasta pentru a continua" << endl;
    char c;
    cin >> c;
}


///------------------------LISTA-----------------------------///
void CreareLista()
{
    n = 0; //numarul de elemente este 0, lista este vida
    creat = 1;
    cout << "Lista a fost creata, aceasta este goala." << endl;
}

void AfisareLista()
{
    if (!n) cout << "Lista este goala" << " ";
    else {
        for (int i = 1; i <= n; i++) cout << lista[i] << " ";
    }
    cout << endl;
}

void AdaugaElemLista()
{
    cout << "Introdu elementul pe care sa-l adaugi in lista:" << endl;
    int elem;
    cin >> elem;

    n++; ///cresc nr de elem
    lista[n] = elem; ///pe ultima pozitie pun elem citit

    cout << "S-a adaugat cu succes. Lista este urmatoarea:" << endl;
    AfisareLista();
}

void Sterge(int x)
{
    //mut toate elementele cu o pozitie in fata incepand de la pozitia x, astfel elementul de pe acea pozitie se va pierde
    for (int i = x; i <= n; i++){
        lista[i] = lista[i + 1];
    }
    lista[n] = 0;
    n--;

    cout << "S-a eliminat cu succes, lista este urmatoarea:" << endl;
    AfisareLista();
}


void EliminaPozX()
{
    if (n){
        cout << "Introdu Pozitia de pe care doresti sa stergi elementul din lista:" << endl;
        int x;
        cin >> x;
        if (x <= 0 or x > n) cout << "Pozitia nu exista" << endl;
        else Sterge(x);


    }
    else cout << "Lista este goala, nu se pot sterge elemente" << endl;

}

void EliminaValX()
{
    if (n){
        cout << "Introdu Valoarea pe care doresti sa o stergi din lista:" << endl;
        int x;
        cin >> x;

        for (int i = 1; i <= n; i++){
            if (lista[i] == x){ ///daca elementul din lista de pe poz. i este egal cu x
                Sterge(i); ///daca da, atunci sterg elementul de pe poz. i
                return; ///termin functia, ies din ea
            }
        }
        cout << "Elementul nu se afla in lista" << endl;
    }
    else cout << "Lista este goala, nu se pot sterge elemente" << endl;


}
void Lista()
{
    cout << endl;
    cout << "1. Crearea unei liste" << endl;
    cout << "2. Adaugarea unui element" << endl;
    cout << "3. Afisarea elementelor din lista" << endl;
    cout << "4. Eliminarea primului element" << endl;
    cout << "5. Eliminarea ultimului element" << endl;
    cout << "6. Eliminarea elementului situat pe pozitia x" << endl;
    cout << "7. Eliminarea elementului egal cu o valoare x" << endl;
    cout << "8. Revenire" << endl;
    cout << "Introdu comanda: " << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1) CreareLista();
    else if (comanda == 2){
        if (creat == 1) AdaugaElemLista();
        else cout << "Lista nu a fost creata." << endl;
    }
    else if (comanda == 3){
        if (creat){
            cout << "Elementele din lista sunt:" << endl;
            AfisareLista();
        }
        else cout << "Lista nu a fost creata." << endl;

    }
    else if (comanda == 4) {
        if (creat){
            if (n) Sterge(1); ///if(n) <=> if (n!=0); if(!n) <=> if(n==0)
            else cout << "Lista este goala, nu se pot sterge elemente" << endl;
        }
        else cout << "Lista nu a fost creata." << endl;

    }
    else if (comanda == 5) {
        if (creat){
            if (n) Sterge(n + 1);
            else cout << "Lista este goala, nu se pot sterge elemente" << endl;
        }
        else cout << "Lista nu a fost creata." << endl;

    }
    else if (comanda == 6){
        if (creat) EliminaPozX();
        else cout << "Lista nu a fost creata." << endl;
    }
    else if (comanda == 7){
        if (creat) EliminaValX();
        else cout << "Lista nu a fost creata." << endl;
    }
    else if (comanda == 8) return; ///se termina functia si iese din ea
    else cout << "Comanda gresita" << endl;

    Lista();
}



///--------------------------STIVA-----------------------------///
void AfisareStiva()
{
    if (varf == 0) cout << "Stiva este goala" << endl;
    else{
        for (int i = varf - 1; i >= 0; i--) cout << stiva[i] << endl;
        cout << endl;
    }

}

void AdaugaElemStiva()
{
    if (varf == 10001){
        cout << "Stiva este plina, nu se mai pod adauga elemente" << endl;
    }
    else{
        cout << "Introdu numarul pe care sa-l adaugi in stiva:" << endl;

        int elem;
        cin >> elem;
        varf++;
        stiva[varf] = elem;

        cout << "S-a adaugat cu succes. Stiva este urmatoarea:" <<  endl;
        AfisareStiva();
        cout << endl;
    }
}

void StergeElemStiva()
{
    if (!varf){
        cout << "Stiva este goala, nu se pot sterge elemente" << endl << endl;
    }
    else{
        stiva[varf] = 0;
        varf--;

        cout << "S-a sters cu succes. Stiva este urmatoarea:" << endl;
        AfisareStiva();
        cout << endl;
    }
}

void OperatiiStiva()
{
    cout << endl;
    cout << "Variante disponibile" << endl;
    cout << "1. Adaugarea unui element" << endl;
    cout << "2. Eliminarea unui element" << endl;
    cout << "3. Revenire" << endl;
    cout << "Introdu Comanda:" << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1) AdaugaElemStiva();
    else if (comanda == 2) StergeElemStiva();
    else if (comanda == 3) return; ///ies din functie
    else cout << "Comanda gresita" << endl;

    OperatiiStiva(); ///reapelez ca sa fac alta operatie
}


void DefinitieStiva()
{
    /// "\n" <=> endl; cout << "\n" <=> cout << endl;
    cout << "Stiva (stack) este o structura de date liniara abstracta, \n"
            "pentru care sunt definite operatiile de adaugare a unui element si eliminare a unui element \n"
            "si aceste operatii se realizeaza la un singur capat al structurii, numit varful stivei. \n" << endl;
}

void Stiva()
{
    cout << endl;
    cout << "Variante disponibile: " << endl;
    cout << "1. Definitie" << endl;
    cout << "2. Operatii" << endl;
    cout << "3. Revenire" << endl;
    cout << "Introdu comanda:" << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1) DefinitieStiva();
    else if (comanda == 2) OperatiiStiva();
    else if (comanda == 3) return; //ies din functie
    else cout << "Comanda gresita" << endl;

    Stiva(); ///reapelez functia ca sa pot sa citesc alta comanda
}



///----------------------------COADA-------------------------///
void DefinitieCoada()
{
    cout << "Coada (queue) este o structura de date abstracta in care operatia de adaugare se realizeaza la un capat, \n"
            "iar cea de eliminare se realizeaza la celalalt capat.\n"
            "\n"
            "In timpul operatiilor cu coada avem acces la un singur element, \n"
            "cel aflat la inceputul cozii - elementul care urmeaza sa se elimine. \n" << endl;
}

void AfisareCoada()
{
    if (prim == ultim) cout <<"Coada este goala." << endl;
    else{
        for (int i = prim; i < ultim; i++) cout << coada[i] <<" ";
        cout << endl;
    }
}

void AdaugaElemCoada()
{
    if (ultim == DIM_MAX){
        cout << "Coada este plina, nu se mai pot adauga elemente" << endl << endl;
    }
    else{
        cout << "Introdu numarul pe care sa-l adaugi in coada:" << endl;

        int elem;
        cin >> elem;
        ultim++;
        coada[ultim] = elem;

        cout << "S-a adaugat cu succes. Coada este urmatoarea:" <<  endl;
        AfisareCoada();
        cout << endl;
    }
}

void StergeElemCoada()
{
    if (prim == ultim){
        cout << "Coada este goala, nu se pot sterge elemente" << endl << endl;
    }
    else{
        coada[prim] = 0;
        prim++;

        cout << "S-a sters cu succes. Coada este urmatoarea:" << endl;
        AfisareCoada();
        cout << endl;
    }
}

void OperatiiCoada()
{
    cout << endl;
    cout << "Variante disponibile" << endl;
    cout << "1. Adaugarea unui element" << endl;
    cout << "2. Eliminarea unui element" << endl;
    cout << "3. Revenire" << endl;
    cout << "Introdu Comanda:" << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1) AdaugaElemCoada();
    else if (comanda == 2) StergeElemCoada();
    else if (comanda == 3) return;
    else cout << "Comanda gresita" << endl;

    OperatiiCoada();
}

void Coada()
{
    cout << endl;
    cout << "Variante disponibile: " << endl;
    cout << "1. Definitie" << endl;
    cout << "2. Operatii" << endl;
    cout << "3. Revenire" << endl;
    cout << "Introdu comanda:" << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1) DefinitieCoada();
    else if (comanda == 2) OperatiiCoada();
    else if (comanda == 3) return;
    else cout << "Comanda gresita." << endl;

    Coada();
}

void MeniuPrincipal()
{
    cout << endl;
    cout << "Variante disponibile: " << endl;
    cout << "1. Lista" << endl;
    cout << "2. Stiva" << endl;
    cout << "3. Coada" << endl;
    cout << "4. Iesire" << endl;
    cout << "Introdu comanda: " << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1) Lista(); ///meniul pentru lista
    else if (comanda == 2) Stiva(); ///meniul pentru stiva
    else if (comanda == 3) Coada(); ///meniul pentru coada
    else if (comanda == 4) return ; ///cand programul da de return, se termina functia
    else cout << "Comanda gresita" << endl;

    MeniuPrincipal(); ///se apeleaza recursiv
}
int main()
{
    Ecran1();
    MeniuPrincipal();
}
