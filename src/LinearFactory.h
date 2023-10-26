#ifndef LINEARFACTORY
#define LINEARFACTORY

#include <vector>
#include "Resource.h"
#include "QuantifiedResource.h"
#include "IProducer.h"
#include "IConsumer.h"

using namespace std;

class LinearFactory : public IProducer, public IConsumer
{
    Resource *input;
    Resource *output;
    /// @brief number of inputs required for each outputs
    double ratio;
    double lastRequest;
    double inputResourceStock;
    double produced;
    vector<Resource *> availableResources;

public:
    LinearFactory(Resource *input, Resource *output, double ratio);
    ~LinearFactory();
    virtual vector<Resource *> *AvailableResources() override;
    virtual void RequestProduction(Resource *resource, double quantity) override;
    virtual vector<QuantifiedResource *> *Produce() override;
    virtual vector<QuantifiedResource *> *GetRequests() override;
    virtual void Deliver(QuantifiedResource *resource) override;
};

#endif