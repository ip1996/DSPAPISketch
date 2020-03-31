#ifndef NODE3_HPP
#define NODE3_HPP

#include "packet.hpp"
#include "scheduler.hpp"
#include "channel.hpp"
#include "packet_types.hpp"

//Gets audio data from the outer world
class Node3 {

public:
  Node3(pipert::Scheduler* scheduler) {
    //channel generation
    //it's the sink node of that channel, should 
    inputChannel = scheduler->generateChannel<RefinedAudioSignal>(&TransformAudio, 3, 0);
  } //should moving data not copy
  

  //This is the callback function
  void TransformAudio(pipert::Packet<RefinedAudioSignal> packet) {
    RefinedAudioSignal data = packet.getData();
    //Filtering raw audio signal
    //...
    TransformedAudioSignal newData;
    //...
    //Wrapping new data into Packet
    
    pipert::Packet<TransformedAudioSignal> newPacket(newData); //create a new packet with fresh metadatas
    pipert::Packet<TransformedAudioSignal> newPacket(newData, packet); //create a new packet keeping the old metadatas
    // nicer solution, do we need this wrapping??
    sinkChannel->write(newPacket);
  }

  void setTransformedChannel(pipert::SinkChannel<TransformedAudioSignal>* channel) {
    sinkChannel = channel;
  }

  pipert::Channel<RefinedAudioSignal>* getInputChannel() {
    return inputChannel;
  }
  
private:
  pipert::Channel<RefinedAudioSignal>* inputChannel; //the source channel from where the data will arrive
  pipert::SinkChannel<TransformedAudioSignal>* sinkChannel;
};


#endif //NODE3_HPP