#ifndef IP_H_
#define IP_H_

#include <iostream>
#include <string>
using namespace std;

class IP{
  public:
    int oct1, oct2, oct3, oct4;
    IP(string filename);
    IP();
    int getValue();
    bool operator > (IP ip2);
    bool operator == (IP ip2);
    bool operator < (IP ip2);
    friend std::ostream& operator<<(std::ostream& os, IP& ip) {
      os<<ip.oct1<<'.'<<ip.oct2<<'.'<<ip.oct3<<'.'<<ip.oct4;
      return os;
    }
};

#endif //IP_H_