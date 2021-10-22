/* Declaración de la clase registro
 * Santiago Álvarez <A01640172@itesm.mx>
 * 15 de septiembre de 2021
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <iostream>

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
		bool operator<=(const Registro&);
		string dateToString();
		string toStringSingleWhitespaces();
	private:
		time_t fecha;
		string ip;
		string razon;
		friend std::ostream& operator<<(std::ostream& os, Registro& reg){
			const int IP_SIZE = 24;
			os<< reg.dateToString() << "  " <<reg.ip<<
				  string(IP_SIZE-reg.ip.length(),' ') <<reg.razon;
			return os;
		}
};

#endif
