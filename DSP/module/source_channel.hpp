#ifndef SOURCE_CHANNEL_HPP
#define SOURCE_CHANNEL_HPP

#include "packet.hpp"

namespace pipert {

template<class T>
class SourceChannel : public Channel<T> {
public:
	SourceChannel(int bufferSize,
			DroppingOrder droppingOrder = LATEST)
		: Channel(bufferSize, droppingOrder)
	{
		buffer = new T[bufferSize];
	}

	SouceChannel(SouceChannel obj) = delete; //copying channel is disabled
	
	void write(T packet) final {
		//Get raw data from the outer world
    //Wrap the tha data into a Packet with metainformation
    //Puts the data into the buffer
	}
private:
};

}

#endif //CHANNEL_HPP