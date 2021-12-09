#ifndef IPGRADO_H_
#define IPGRADO_H_

#include "IP.h"

class IPGrado{
  private:
   std::string ip;
   int padres;
   int hijos;

  public:
  IPGrado();
  IPGrado(std::string,int,int);
  std::string toString();
  friend std::ostream& operator<<(std::ostream& os, IPGrado& ip2){
		os<<ip2.ip<<" Antecesores: "<<ip2.padres<<", Sucesores"<<ip2.hijos;
		return os;
	}
};

#endif