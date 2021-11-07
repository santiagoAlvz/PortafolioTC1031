/* Declaración de la clase registro
 * Santiago Álvarez <A01640172@itesm.mx>
 * 6 de noviembre de 2021
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <iostream>
#include "IP.h"

using std::string;

class Registro{
	//Clase que almacena los datos de una incidencia
	public:
		Registro();
		Registro(time_t tiempo);
		Registro(std::string data);
		bool operator==(const Registro&);
		bool operator<(const Registro&);
		bool operator>(const Registro&);
		string dateToString();
		IP getIP();
		
	private:
		time_t fecha;
		IP ip;
		int puerto;
		string razon;
		friend std::ostream& operator<<(std::ostream& os, Registro& reg){
			os<< reg.dateToString() << " " <<reg.ip<<":"<<reg.puerto<<" "<<reg.razon;
			return os;
		}
};

#endif
