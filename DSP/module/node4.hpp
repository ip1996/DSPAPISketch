#ifndef NODE4_HPP
#define NODE4_HPP

#include "packet.hpp"
#include "scheduler.hpp"
#include "channel.hpp"
#include "packet_types.hpp"

//Gets audio data from the outer world
class Node4 {

public:
  Node4(pipert::Scheduler* scheduler) {
    //channel generation
    //it's the sink node of that channel, should 
    sinkChannel = scheduler->generateSinkChannel<TransformedAudioSignal>(&LogAudio, 3, 0);
  } //should moving data not copy
  

  //This is the callback function
  void LogAudio(TransformedAudioSignal packet) {
    TransformedAudioSignal data = packet;
    //write the raw data into a databade or file
  }

  pipert::SinkChannel<TransformedAudioSignal>* getSinkChannel() {
    return sinkChannel;
  }
  
private:
  pipert::SinkChannel<TransformedAudioSignal>* sinkChannel;
};


#endif //NODE4_HPP