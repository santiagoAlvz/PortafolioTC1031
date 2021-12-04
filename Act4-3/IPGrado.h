#ifndef IPGRADO_H_
#define IPGRADO_H_

#include "IP.h"

class IPGrado{
  private:
   IP ip;
   int grado;
  public:
  IPGrado(IP,int);
  bool operator < (IPGrado);
  bool operator > (IPGrado);
  bool operator == (IPGrado);
  friend std::ostream& operator<<(std::ostream& os, IPGrado& ip2){
		os<<"Dirección IP: "<<ip2.ip.oct1<<"."<<ip2.ip.oct2<<"." <<ip2.ip.oct3<<"."<<ip2.ip.oct4<<" \t\tGrado: "<<ip2.grado;
		return os;
	}
};

#endif