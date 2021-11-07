/* Implementación de la clase IP
 * Santiago Álvarez <A01640172@itesm.mx>
 * 6 de noviembre de 2021
 */

#include "IP.h"
#include <sstream>

IP::IP(){
	//Constructor de IP, sin parámetros
	this->cuart1 = 0;
	this->cuart2 = 0;
	this->cuart3 = 0;
	this->cuart4 = 0;
}

IP::IP(std::string data){
	//Constructor de IP, con una cadena como parámetro
	std::string temp;
	std::stringstream ss(data);
	
	getline(ss,temp,'.');
	this->cuart1 = stoi(temp);
	getline(ss,temp,'.');
	this->cuart2 = stoi(temp);
	getline(ss,temp,'.');
	this->cuart3 = stoi(temp);
	getline(ss,temp);
	this->cuart4 = stoi(temp);
}

bool IP::operator < (IP ip2){
	//Comparador de IP, va comparando por cuartos, si dos cuartos son 
	//iguales, sigue comparando, si no lo son, regresa el resultado del
	//operador < con los cuartos actuales
	
	if(this->cuart1 == ip2.cuart1){
		if(this->cuart2 == ip2.cuart2){
			if(this->cuart3 == ip2.cuart3){
				return this->cuart4 < ip2.cuart4;
			} else return this->cuart3 < ip2.cuart3;
		} else return this->cuart2 < ip2.cuart2;
	} else return this->cuart1 < ip2.cuart1;
}

bool IP::operator > (IP ip2){
	//Comparador de IP, va comparando por cuartos, si dos cuartos son 
	//iguales, sigue comparando, si no lo son, regresa el resultado del
	//operador > con los cuartos actuales
	if(this->cuart1 == ip2.cuart1){
		if(this->cuart2 == ip2.cuart2){
			if(this->cuart3 == ip2.cuart3){
				return this->cuart4 > ip2.cuart4;
			} else return this->cuart3 > ip2.cuart3;
		} else return this->cuart2 > ip2.cuart2;
	} else return this->cuart1 > ip2.cuart1;
}

bool IP::operator == (IP ip2){
	//Regresa verdadero si todos los cuartos de ambas IP son iguales
	if(this->cuart1 == ip2.cuart1){
		if(this->cuart2 == ip2.cuart2){
			if(this->cuart3 == ip2.cuart3){
				return this->cuart4 == ip2.cuart4;
			} else return false;
		} else return false;
	} else return false;
}
