#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Usuarios.h"

class Profesor : public Usuarios
{
private:
    string tituloProfesional;
    int cedulaProfesional;
    static const int maxProfesores = 100;
    static int contadorProfesores;
    Profesor* profe[maxProfesores];

public:
	Profesor(string nombreUsuario, string apellido, string sexo, int edad, string tituloProfesional, int cedulaProfesional) : Usuarios(nombreUsuario, apellido, sexo, edad) {
        this->tituloProfesional = tituloProfesional;
        this->cedulaProfesional = cedulaProfesional;

    }

    Profesor() {}

	~Profesor() {}

    string getTituloProfesional() {
        return tituloProfesional;
    }
    int getCedulaProfesional() {
        return cedulaProfesional;
    }

    void capturaDatos() {
        if (contadorProfesores < maxProfesores) {
            string NombreUsuario, Apellido, Sexo;
            int Edad;

            cout << "\n[+] Ingrese el nombre del profesor: ";
            cin >> NombreUsuario;
            cout << "[+] Ingrese el apellido del profesor: ";
            cin >> Apellido;
            cout << "[+] Ingrese el sexo del profesor: ";
            cin >> Sexo;
            cout << "[+] Ingrese la edad del profesor: ";
            cin >> Edad;
            cout << "[+] Ingrese el titulo profesional del profesor: ";
            cin >> tituloProfesional;
            cout << "[+] Ingrese la cedula profesional del profesor: ";
            cin >> cedulaProfesional;

            // Crear vrctor para almacenar respuestas
            profe[contadorProfesores++] = new Profesor(NombreUsuario, Apellido, Sexo, Edad, tituloProfesional, cedulaProfesional);

            cout << "\n[+] Profesor Agregado Correctamente\n";
        }
        else {
            cout << "\n[!] No se pueden agregar más profesores. Límite alcanzado.\n";
        }
    }

    void imprimirDatos() {
        cout << "\nLista de Profesores:\n";
        for (int i = 0; i < contadorProfesores; ++i) {
            cout << "[+] Profesor " << i + 1 << ":\n";
            cout << " [=] Nombre: " << profe[i]->getNombreUsuario() << " " << profe[i]->getApellido() << endl;
            cout << " [=] Sexo: " << profe[i]->getSexo() << endl;
            cout << " [=] Edad: " << profe[i]->getEdad() << endl;
            cout << " [=] Titulo Profesional: " << profe[i]->getTituloProfesional() << endl;
            cout << " [=] Cedula Profesional: " << profe[i]->getCedulaProfesional() << endl;
            cout << "\n------------------------------------\n";
        }

    }

};

