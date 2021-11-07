/* Implementación de la clase registro
 * Santiago Álvarez <A01640172@itesm.mx>
 * 6 de noviembre de 2021
 */

#include "Registro.h"
#include <sstream>
#include <vector>

using std::string;

std::vector <string> MESES = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
								 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Registro::Registro(){
	//Constructor sin parámetros
	this->fecha = 0;
	this->razon = "";
}

Registro::Registro(time_t tiempo){
	//Constructor que recibe una fecha
	this->fecha = tiempo;
}

Registro::Registro(string data){
	//Constructor completo, que se usa al leer de un archivo
	try{
		string temp;
		std::stringstream ss(data);
		struct tm dateStruct;
		
		dateStruct.tm_year = 2021-1900;
		getline(ss,temp,' '); //mes
		for(int i = 0; i<12; i++){
			if(MESES[i] == temp){
				dateStruct.tm_mon = i;
			}
		}
		
		getline(ss,temp,' '); //Dia
		dateStruct.tm_mday = stoi(temp);	
		getline(ss,temp,':');  //Hora
		dateStruct.tm_hour = stoi(temp);
		getline(ss,temp,':'); //Min
		dateStruct.tm_min = stoi(temp);
		getline(ss,temp,' '); //Seg
		dateStruct.tm_sec = stoi(temp);
		
		getline(ss,temp,':'); //IP
		this->ip = IP(temp);
		
		getline(ss,temp,' '); //IP
		this->puerto = stoi(temp);
		
		getline(ss,temp); //Razon
		this->razon = temp;
		
		dateStruct.tm_isdst = -1;
		this->fecha = mktime(&dateStruct);

	} catch(...){
		//Si se dió alguna excepción durante la ejecución
		throw "El formato del archivo es distinto al esperado";
	}
}

bool Registro::operator ==(const Registro &otro){
	//Sobrecarga del operador ==, en función de la fecha
	return this->ip == otro.ip;
}

bool Registro::operator <(const Registro &otro){
	//Sobrecarga del operador <, en función de la fecha
	return this->ip < otro.ip;
}

bool Registro::operator >(const Registro &otro){
	//Sobrecarga del operador >, en función de la fecha
	return this->ip > otro.ip;
}

string Registro::dateToString(){
	//Regresa la fecha almacenada, en formato humano (legible)
	
	struct tm ts = *localtime(&this->fecha);
	char res[20];
	
	strftime(res,20,"%b ",&ts);
	std::string fecha(res);
	
	fecha.append(std::to_string(ts.tm_mday));
	fecha.append(" ");
	fecha.append(std::to_string(ts.tm_hour));
	
	strftime(res,20,":%M:%S",&ts);
	fecha.append(res);
	return fecha;
}

IP Registro::getIP(){
	return this->ip;
}
