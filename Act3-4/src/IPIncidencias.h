/* Declaración de la clase IPIncidencias
 * Santiago Álvarez <A01640172@itesm.mx>
 * 6 de noviembre de 2021
 */

#ifndef IPINCIDENCIAS_H
#define IPINCIDENCIAS_H


//Esta clase es una unión de una IP con un número entero, que representa las incidencias
class IPIncidencias{
	private:
		IP ip;
		int incidencias;
	public:
		IPIncidencias();
		IPIncidencias(IP ip2, int inc);
		bool operator <(IPIncidencias ip2);
		bool operator >(IPIncidencias ip2);
		friend std::ostream& operator<<(std::ostream& os, IPIncidencias& myIP){
			os<<myIP.ip<<" "<<myIP.incidencias;
			return os;
		}
};

IPIncidencias::IPIncidencias(){
	//Constuctor sin parámetros
	this->incidencias = 0;
}

IPIncidencias::IPIncidencias(IP ip2, int inc){
	//Constructor con parámetros
	this->ip = ip2;
	this->incidencias = inc;
}

bool IPIncidencias::operator <(IPIncidencias ip2){
	//Operador de comparación <
	return this->incidencias < ip2.incidencias;
}

bool IPIncidencias::operator >(IPIncidencias ip2){
	//Operador de comparación >
	return this->incidencias > ip2.incidencias;
}

#endif
