#include "Market.h"

Market::Market(vector<IConsumer *> *consumers, vector<IProducer *> *producers)
{
  this->consumers = consumers;
  this->producers = producers;
}

void Market::Negotiate()
{
}
