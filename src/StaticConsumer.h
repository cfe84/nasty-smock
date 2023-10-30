#ifndef LINEARGROWTHCONSUMER
#define LINEARGROWTHCONSUMER

#include <vector>
#include <map>
#include "IConsumer.h"
#include "QuantifiedResource.h"

/// @brief Consumer which staticly asks for a resource
class StaticConsumer : IConsumer
{
  vector<QuantifiedResource> consumption;
  // Track total consumption
  map<Resource *, double> consumed;

public:
  StaticConsumer(initializer_list<QuantifiedResource> consumption);
  ~StaticConsumer();
  virtual vector<QuantifiedResource> GetRequests() override;
  virtual void Deliver(QuantifiedResource resource) override;
  map<Resource *, double> *GetConsumption();
};

#endif