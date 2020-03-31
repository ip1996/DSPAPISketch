#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "channel.hpp"
#include "source_channel.hpp"
#include "sink_channel.hpp"
#include <functional>

namespace pipert {

class Scheduler {
public:
	Scheduler() {
		
	}

	template<class T>
	Channel<T>* generateChannel(std::function<void(Packet<T>)> callback,
			int bufferSize,
			int droppingOrder)
	{
		channels.add(Channel(..,..))
		return channels[last];
	}

	template<class T>
	SourceChannel<T>* generateSourceChannel(std::function<void(Packet<T>)> callback,
			int bufferSize,
			int droppingOrder)
	{
		channels.add(Channel(..,..))
		return channels[last];
	}

	template<class T>
	SinkChannel<T>* generateSinkChannel(std::function<void(T)> callback,
			int bufferSize,
			int droppingOrder)
	{
		channels.add(Channel(..,..))
		return channels[last];
	}

	//what will the Scheduler do, timing the channels, giving threads to channel? Will it call directly call the channels to work??

	//checking when a channel has data and calls the callback function and writes the output data to the next channel
	//or this functionality should be done in the channel??
private:
	//is there any way to store these channels in this way???
	std::pair<SourceChannel<T>, std::function<void(Packet<T>)>) sourceChannels;
	std::pair<Channel<T>, std::function<void(Packet<T>)>)[] channels; //stores channels and callback regarding to that channel
	std::pair<SinkChannel<T>, std::function<void(Packet<T>)>) sinkChannels;
};

}

#endif //SCHEDULER_HPP
