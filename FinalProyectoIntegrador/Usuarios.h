#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class Usuarios {
private:
	string nombreUsuario, apellido, sexo;
	int edad;

public:
	Usuarios(string nombreUsuario, string apellido, string sexo, int edad) {
		this->nombreUsuario = nombreUsuario;
		this->apellido = apellido;
		this->sexo = sexo;
		this->edad = edad;

	}
	Usuarios(string nombreUsuario, string apellido) {
		this->nombreUsuario = nombreUsuario;
		this->apellido = apellido;
	}

	Usuarios() {}

	~Usuarios() {}
	
	virtual void capturaDatos() = 0;

	virtual void imprimirDatos() = 0;

	string getNombreUsuario() {
		return nombreUsuario;
	}
	string getApellido() {
		return apellido;
	}
	string getSexo() {
		return sexo;
	}
	int getEdad() {
		return edad;
	}

	void setNombreUsuario(string newNombreUsaurio) {
		this->nombreUsuario = newNombreUsaurio;
	}
	void setApellido(string newApellido) {
		this->apellido = newApellido; 
	}
	void setSexo(string newSexo) {
		this->sexo = newSexo;
	}
	void setEdad(int newEdad) {
		this->edad = newEdad;
	}


};
