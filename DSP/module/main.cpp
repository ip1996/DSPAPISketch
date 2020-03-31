#include "channel.hpp"
#include "scheduler.hpp"
#include "node0.hpp"
#include "node1.hpp"
#include "node2.hpp"
#include "node3.hpp"
#include "node4.hpp"
#include "packet_types.hpp"

int main() {
  pipert::Scheduler scheduler;
 
  //Creating the connection between nodes with the help of channels
  Node0 node0; //node0 will get the data from socket communication
  Node1 node1(&scheduler); //is scheduler injected by constructor to nodes okay or convinient enough???
  node0.setOutputChannel(node1.getSourceChannel()); //node0 will send data to node1's channel 
  Node2 node2(&scheduler); 
  node1.setFilteredChannel(node2.getInputChannel()); //node1 will send data to node2's channel
  Node3 node3(&scheduler);
  node2.setRefinedChannel(node3.getInputChannel()); //node2 will send data to node3's channel
  Node4 node4(&scheduler);
  node3.setTransformedChannel(node4.getSinkChannel()); //node3 will send data to node4's channel

  //node4 will save the data to a database


  return 0;
}