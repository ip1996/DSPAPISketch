#ifndef PACKET_HPP
#define PACKET_HPP

namespace pipert {

template<class T>
class Packet {
public:
  Packet(T data) : data(data) {} //should moving data not copy
  template<class T2>
  Packet(T data, Packet<T2> packet) : data(data) //should moving data not copy
  { 
    //copy metainformation from old packet to the new one
  }

  T getData() { return data; } //should move data not copy

private:
  int time; //timestamp when package arrived the channel
  int orderNumber; //if necessarry for processing the packets in order
  T data; //the raw data in the package
};

}

#endif //PACKET_HPP