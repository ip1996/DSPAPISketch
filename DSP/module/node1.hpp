#ifndef NODE1_HPP
#define NODE1_HPP

#include "packet.hpp"
#include "scheduler.hpp"
#include "channel.hpp"
#include "source_channel.hpp"
#include "packet_types.hpp"

//Gets audio data from the outer world
class Node1 {

public:
  Node1(pipert::Scheduler* scheduler) {
    //source channel generation
    //it's the sink node of that channel, should 
    sourceChannel = scheduler->generateSourceChannel<AudioSignal>(&FilterAudio, 3, 0);
  } //should moving data not copy
  

  //This is the callback function
  void FilterAudio(pipert::Packet<AudioSignal> packet) {
    AudioSignal data = packet.getData();
    //Filtering raw audio signal
    //...
    FilteredAudioSignal newData;
    //...
    //Wrapping new data into Packet
    
    pipert::Packet<FilteredAudioSignal> newPacket(newData); //create a new packet with fresh metadatas
    pipert::Packet<FilteredAudioSignal> newPacket(newData, packet); //create a new packet keeping the old metadatas
    // nicer solution, do we need this wrapping??
    outputChannel->write(newPacket);
  }

  void setFilteredChannel(pipert::Channel<FilteredAudioSignal>* channel) {
    outputChannel = channel;
  }

  pipert::SourceChannel<AudioSignal>* getSourceChannel() {
    return sourceChannel;
  }
  
private:
  pipert::SourceChannel<AudioSignal>* sourceChannel; //the source channel from where the data will arrive
  pipert::Channel<FilteredAudioSignal>* outputChannel;  //the output channel where the node will write, gets it from another node
};


#endif //NODE1_HPP