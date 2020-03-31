#ifndef NODE2_HPP
#define NODE2_HPP

#include "packet.hpp"
#include "scheduler.hpp"
#include "channel.hpp"
#include "packet_types.hpp"

//Gets audio data from the outer world
class Node2 {

public:
  Node2(pipert::Scheduler* scheduler) {
    //channel generation
    //it's the sink node of that channel, should 
    inputChannel = scheduler->generateChannel<FilteredAudioSignal>(&RefineAudio, 3, 0);
  } //should moving data not copy
  

  //This is the callback function
  void RefineAudio(pipert::Packet<FilteredAudioSignal> packet) {
    FilteredAudioSignal data = packet.getData();
    //Filtering raw audio signal
    //...
    RefinedAudioSignal newData;
    //...
    //Wrapping new data into Packet
    
    pipert::Packet<RefinedAudioSignal> newPacket(newData); //create a new packet with fresh metadatas
    pipert::Packet<RefinedAudioSignal> newPacket(newData, packet); //create a new packet keeping the old metadatas
    // nicer solution, do we need this wrapping??
    outputChannel->write(newPacket);
  }

  void setRefinedChannel(pipert::Channel<RefinedAudioSignal>* channel) {
    outputChannel = channel;
  }

  pipert::Channel<FilteredAudioSignal>* getInputChannel() {
    return inputChannel;
  }
  
private:
  pipert::Channel<FilteredAudioSignal>* inputChannel;
  pipert::Channel<RefinedAudioSignal>* outputChannel;
};


#endif //NODE2_HPP