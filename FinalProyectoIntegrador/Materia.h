#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Profesor.h"

class Materia
{
private:
    string nombreMateria;
    int numeroCreditos;
    static const int maxMateria = 100;
    static int contadorMaterias;
    Materia* materia[maxMateria];
    Profesor prof;

public:
    Materia(string nombreMateria, int numeroCreditos, string nombreUsuario, string apellido) {
        this->nombreMateria = nombreMateria;
        this->numeroCreditos = numeroCreditos;

    }
    Materia(string nombreMateria, int numeroCreditos, Profesor* profesor) 
        : nombreMateria(nombreMateria), numeroCreditos(numeroCreditos), prof(*profesor) {}

    Materia(string nombreMateria) {}

    Materia() {}

    ~Materia() {}

    string getNombreMateria() {
        return nombreMateria;
    }

    int getNumeroCreditos() {
        return numeroCreditos;
    }

    void capturaMateria() {
        if (contadorMaterias < maxMateria) {
            string nombreUsuario, apellido, nombreMateria;
            int numeroCreditos;

            cout << "\n[+] Ingrese el nombre de la materia: ";
            cin >> nombreMateria; 
            cout << "[+] Ingrese el numero de creditos de la materia: ";
            cin >> numeroCreditos; 
            cout << "[+] Ingrese el nombre del profesor titular de la materia: ";
            cin >> nombreUsuario; 
            cout << "[+] Ingrese el apellido del profesor titular de la materia: ";
            cin >> apellido; 

            materia[contadorMaterias++] = new Materia(nombreMateria, numeroCreditos, nombreUsuario, apellido); 
            cout << "\n[+] Materia Agregada Correctamente\n";
        }
        else {
            cout << "\n[!] No se pueden agregar más materias. Límite alcanzado.\n";
        }
    }

    void imprimeMateria() {
        cout << "\nLista de Materias:\n";
        for (int i = 0; i < contadorMaterias; ++i) {
            cout << "[+] Materia " << i + 1 << ":\n";
            cout << " [=] Nombre de la Materia: " << materia[i]->getNombreMateria() << endl; 
            cout << " [=] Creditos para pasar la Materia: " << materia[i]->getNumeroCreditos() << endl; 
            //cout << " [=] Nombre del docente: " << materia[i]->prof.getNombreUsuario() << " " << materia[i]->prof.getApellido() << endl; 
            cout << "\n------------------------------------\n";
        }
    }
};

