#ifndef MARKET
#define MARKET

#include <vector>
#include "IConsumer.h"
#include "IProducer.h"

class Market
{
  vector<IConsumer *> *consumers;
  vector<IProducer *> *producers;

public:
  Market(vector<IConsumer *> *consumers, vector<IProducer *> *producers);
  void Negotiate();
};

#endif