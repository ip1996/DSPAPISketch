#ifndef SINK_CHANNEL_HPP
#define SINK_CHANNEL_HPP

#include "packet.hpp"

namespace pipert {

template<class T>
class SinkChannel : public Channel<T> {
public:
	SinkChannel(int bufferSize,
			DroppingOrder droppingOrder = LATEST)
		: Channel(bufferSize, droppingOrder)
	{
		buffer = new T[bufferSize];
	}

	SinkChannel(SouceChannel obj) = delete; //copying channel is disabled
	
	T read() final {
		//Reads packeted data from the buffer
    //Wrap out the tha data 
    //Sends the raw data into the outer world
	}
private:
};

}
#endif //CHANNEL_HPP