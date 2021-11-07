/* Declaración de la clase IP
 * Santiago Álvarez <A01640172@itesm.mx>
 * 6 de noviembre de 2021
 */

#ifndef IP_H
#define IP_H

#include <string>
#include <iostream>

class IP{
	private:
		short int cuart1, cuart2, cuart3, cuart4;
	public:
		IP();
		IP(std::string data);
		bool operator < (IP ip2);
		bool operator > (IP ip2);
		bool operator == (IP ip2);
	friend std::ostream& operator<<(std::ostream& os, IP& ip){
		os<<ip.cuart1<<"."<<ip.cuart2<<"."<<ip.cuart3<<"."<<ip.cuart4;
		return os;
	}
};

#endif
