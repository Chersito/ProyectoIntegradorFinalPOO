#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Usuarios.h"
#include "Materia.h"

class Alumno : public Usuarios
{
private:
    int numeroControl, semestre;
    static const int maxAlumnos = 100;
    static int contadorAlumnos;
    Alumno* alumnos[maxAlumnos];
    Materia materia;

public: 

    Alumno(string nombreUsuario, string apellido, string sexo, int edad, int numeroControl, int semestre, string nombreMateria)
        : Usuarios(nombreUsuario, apellido, sexo, edad), materia(nombreMateria) {
        this->numeroControl = numeroControl;
        this->semestre = semestre;
    }

    Alumno(string nombreUsuario, string apellido) : Usuarios(nombreUsuario, apellido) {}

    Alumno() {}

    ~Alumno() {}

    int getNumeroControl() {
        return numeroControl;
    }

    int getSemestre() {
        return semestre;
    }

    void capturaDatos() {
        if (contadorAlumnos < maxAlumnos) {
            string nombreUsuario, apellido, nombreMateria, sexo;
            int numeroControl, semestre, edad;

            cout << "\n[+] Ingrese el nombre del alumno: ";
            cin >> nombreUsuario;
            cout << "[+] Ingrese el apellido del alumno: ";
            cin >> apellido;
            cout << "[+] Ingrese el sexo del alumno: ";
            cin >> sexo;
            cout << "[+] Ingrese la edad del alumno: ";
            cin >> edad;
            cout << "[+] Ingrese la matricula del alumno: ";
            cin >> numeroControl;
            cout << "[+] Ingrese el numero del semestre que cursa el alumno: ";
            cin >> semestre;
            cout << "[+] Ingrese el nombre de la materia que cursa el alumno: ";
            cin >> nombreMateria;

            alumnos[contadorAlumnos++] = new Alumno(nombreUsuario, apellido, sexo, edad, numeroControl, semestre, nombreMateria);
        }
        else {
            cout << "\n[!] No se pueden agregar mas alumnos. Limite alcanzado." << endl;
        }
    }

    void imprimirDatos() {
        if (contadorAlumnos > 0) {
            cout << "\nLista de Alumnos:\n";
            for (int i = 0; i < contadorAlumnos; ++i) {
                cout << "[+] Alumno " << i + 1 << ":\n";
                cout << " [=] Nombre del alumno: " << alumnos[i]->getNombreUsuario() << " " << alumnos[i]->getApellido() << endl;
                cout << " [=] Sexo: " << alumnos[i]->getSexo() << endl;
                cout << " [=] Edad: " << alumnos[i]->getEdad() << endl;
                cout << " [=] Matricula: " << alumnos[i]->getNumeroControl() << endl;
                cout << " [=] Semestre: " << alumnos[i]->getSemestre() << endl;
                //cout << " [=] Materia Cursada: " << alumnos[i]->materia.getNombreMateria() << endl;

                cout << "\n------------------------------------\n";
            }
        }
        else {
            cout << "\n[!] No hay alumnos registrados.\n";
        }
    }
};
