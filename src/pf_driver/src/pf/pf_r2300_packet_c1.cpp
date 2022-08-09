#include "pf_driver/pf/pf_packet/pf_r2300_packet_c1.h"
#include "pf_driver/pf/pf_packet_reader.h"

void PFR2300Packet_C1::read_with(PFPacketReader& reader)
{
  reader.read(*this);
}

void PFR2300Packet_C1::read_data(uint8_t* buf, size_t num)
{
  uint32_t* data = reinterpret_cast<uint32_t*>(buf);
  distance.resize(num);
  amplitude.resize(num);
  for (int i = 0; i < num; i++)
  {
    uint32_t d = data[i];
    distance[i] = d & 0x000FFFFF;
    amplitude[i] = (d & 0xFFFFF000) >> 20;
  }
}
