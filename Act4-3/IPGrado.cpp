#include "IPGrado.h"

IPGrado::IPGrado(IP ip2,int a){ //Complejidad O(1)
  this->ip = ip2;
  this->grado = a;
}

bool IPGrado::operator < (IPGrado ip2){ //Complejidad O(1)
  return this->grado < ip2.grado;
}

bool IPGrado::operator > (IPGrado ip2){ //Complejidad O(1)
  return this-> grado > ip2.grado;
}

bool IPGrado::operator == (IPGrado ip2){ //Complejidad O(1)
  return this->grado == ip2.grado;
}