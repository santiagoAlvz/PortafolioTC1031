 #include "IP.h"

IP::IP(){ //Constructor default. Complejidad O(1)
  oct1 = 0;
  oct2 = 0;
  oct3 = 0;
  oct4 = 0;
}

IP::IP(std::string line){ //Obtiene los octetos de las IP para encontrar el valor numérico. Complejidad O(1)
  string o1,o2,o3,o4;
  int pos;
  pos = 0;
  o1 = line.substr(0,line.find("."));
  pos+= o1.length()+1;
  o2 = line.substr(pos,line.find(".",pos)-pos);
  pos+= o2.length()+1;
  o3 = line.substr(pos,line.find(".",pos)-pos);
  pos+= o3.length()+1;
  o4 = line.substr(pos,line.find(".",pos)-pos);
  oct1 = stoi(o1);
  oct2 = stoi(o2);
  oct3 = stoi(o3);
  oct4 = stoi(o4);
}

int IP::getValue(){ //Regresa el valor numérico de cada IP. Complejidad O(1)
  int valueIP;
  valueIP = (oct1*256^3)+(oct2*256^2)+(oct3*256)+oct4;
  return valueIP;
}

bool IP::operator> (IP ip2){
	//Comparador de IP, va comparando por octos, si dos octos son 
	//iguales, sigue comparando, si no lo son, regresa el resultado del
	//operador > con los octos actuales
	if(this->oct1 == ip2.oct1){
		if(this->oct2 == ip2.oct2){
			if(this->oct3 == ip2.oct3){
				return this->oct4 > ip2.oct4;
			} else return this->oct3 > ip2.oct3;
		} else return this->oct2 > ip2.oct2;
	} else return this->oct1 > ip2.oct1;
}

bool IP::operator == (IP ip2){
	//Regresa verdadero si todos los octos de ambas IP son iguales
	if(this->oct1 == ip2.oct1){
		if(this->oct2 == ip2.oct2){
			if(this->oct3 == ip2.oct3){
				return this->oct4 == ip2.oct4;
			} else return false;
		} else return false;
	} else return false;
}

bool IP::operator < (IP ip2){
	//Comparador de IP, va comparando por octos, si dos octos son 
	//iguales, sigue comparando, si no lo son, regresa el resultado del
	//operador < con los octos actuales
	
	if(this->oct1 == ip2.oct1){
		if(this->oct2 == ip2.oct2){
			if(this->oct3 == ip2.oct3){
				return this->oct4 < ip2.oct4;
			} else return this->oct3 < ip2.oct3;
		} else return this->oct2 < ip2.oct2;
	} else return this->oct1 < ip2.oct1;
}

std::string IP::toString(){
  string IPstr;
  IPstr = to_string(oct1)+"."+to_string(oct2)+"."+to_string(oct3)+"."+to_string(oct4);

  return IPstr;

}