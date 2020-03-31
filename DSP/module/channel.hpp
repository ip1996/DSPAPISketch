#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "packet.hpp"

namespace pipert {

template<class T>
class Channel {
public:
	enum class DroppingOrder { LATEST, NEWEST, HISTORICAL };
	Channel(int bufferSize,
			DroppingOrder droppingOrder = LATEST)
		:bufferSize(bufferSize),
		droppingOrder(droppingOrder)
	{
		buffer = new T[bufferSize];
		//initialize the channel;
	} //Maybe constructor should be deleted too, and should have a static generator, which will give back a channel pointer

	Channel(Channel obj) = delete; //copying channels is disabled
	
	
	virtual void write(Packet<T> packet) {
		//Works with wrapped packeges where metainformation is stored
		//maybe can change this metainformation if neccessary
		//writes into buffer
	}

	virtual Packet<T> read() {
		//reads from the buffer
		//and calls the callback function
	}
protected:
	Packet<T>[] buffer;
	int bufferSize;
	DroppingOrder droppingOrder;
};

}

#endif //CHANNEL_HPP
