#include "StaticConsumer.h"

StaticConsumer::StaticConsumer(initializer_list<QuantifiedResource> consumption)
{
  this->consumption = vector<QuantifiedResource>(consumption);
  consumed = map<Resource *, double>();
  for (uint i = 0; i < consumption.size(); i++)
  {
    auto resource = this->consumption[i].getResource();
    consumed.insert({resource, .0});
  }
}

StaticConsumer::~StaticConsumer()
{
}

vector<QuantifiedResource> StaticConsumer::GetRequests()
{
  return vector<QuantifiedResource>(consumption);
}

void StaticConsumer::Deliver(QuantifiedResource quantifiedResource)
{
  consumed[quantifiedResource.getResource()] += quantifiedResource.getQuantity();
}

map<Resource *, double> *StaticConsumer::GetConsumption()
{
  return &consumed;
}
