#ifndef NODE0_HPP
#define NODE0_HPP

#include "packet.hpp"
#include "scheduler.hpp"
#include "channel.hpp"
#include "source_channel.hpp"
#include "packet_types.hpp"

//Gets audio data from the outer world
class Node0 {
public:

  //This function will start to fill the source channel of the pipeline
  void FillAudioChannel() {
    //opening a socket connection
    //getting data from a socket
    while (true) {
      AudioSignal data;
      //reading from the socket
      //converting it the audiosignal format
      //assigning it to data
      
      //writing the data for the channel
      outputChannel->write(data);
    }
  }

  void setOutputChannel(pipert::SourceChannel<AudioSignal>* channel) {
    outputChannel = channel;
  }
  
private:
  pipert::SourceChannel<AudioSignal>* outputChannel; //the source channel which is the beginning of the pipeline
};


#endif //NODE0_HPP