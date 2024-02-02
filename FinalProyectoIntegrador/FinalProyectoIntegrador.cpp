#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Usuarios.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Materia.h"

int main()
{
    int opc;
    int opc1, opc2;
    Profesor* prof = new Profesor();
    Alumno* alumn = new Alumno();
    Materia* mat = new Materia();

    do {
        cout << "\n<=========================================================>";
        cout << "\n\tBienvenido al administrador de usuarios" << endl;
        cout << "<=========================================================>\n";

        cout << "\nIntroduce el numero de la accion a realizar:" << endl;
        cout << "1.- Agregar: " << endl;
        cout << "2.- Visualizar: " << endl;
        cout << "0.- Salir: \n" << endl;
        cin >> opc;

        switch (opc) {

            // Agregar 
        case 1:

            cout << "\nIntroduce el numero de lo que vas a agregar:" << endl;
            cout << "1.- Profesor: " << endl;
            cout << "2.- Materia: " << endl;
            cout << "3.- Alumno: \n" << endl;
            cin >> opc1;

            switch (opc1) {

                //Profesor
            case 1:
                prof->capturaDatos();

                break;

                //Materia
            case 2:
                mat->capturaMateria();
                break;

                //Alumno
            case 3:
                alumn->capturaDatos();
                break;

            default:
                cout << "\n[!] Opcion no valida, vuelva a intentar" << endl;

            }

            break;

            // Visualizar 
        case 2:

            cout << "\nIntroduce el numero de lo que vas a visualizar:" << endl;
            cout << "1.- Profesor: " << endl;
            cout << "2.- Materia: " << endl;
            cout << "3.- Alumno: \n" << endl;
            cin >> opc2;

            switch (opc2) {

                //Profesor
            case 1:
                prof->imprimirDatos();
                break;

                //Materia
            case 2:
                mat->imprimeMateria();
                break;

                //Alumno
            case 3:
                alumn->imprimirDatos();
                break;

            default:
                cout << "\n[!] Opcion no valida, vuelva a intentar" << endl;

            }

            break;

        default:
            if (opc == 0) {
                cout << "\n[+] Hasta Pronto" << endl;
            }
            else {
                cout << "\n[!] Opcion no valida, vuelva a intentar" << endl;
            }
        }

        system("pause");
        system("cls");
    } while (opc != 0);
}