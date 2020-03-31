#ifndef PACKET_TYPES_HPP
#define PACKET_TYPES_HPP

struct FilteredAudioSignal
{
  unsigned char audio[1000];
};

struct AudioSignal
{
  unsigned char audio[2000];
};

struct RefinedAudioSignal
{
  unsigned char audio[3000];
};

struct TransformedAudioSignal
{
  unsigned char audio[3000];
};

#endif //PACKET_TYPES_HPP