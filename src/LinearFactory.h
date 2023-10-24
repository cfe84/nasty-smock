#ifndef LINEARFACTORY
#define LINEARFACTORY

#include <vector>
#include "Resource.h"
#include "Request.h"
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
    vector<Resource *> availableResources;

public:
    LinearFactory(Resource *input, Resource *output, double ratio);
    ~LinearFactory();
    virtual vector<Resource *> *AvailableResources() override;
    virtual double Produce(Resource *resource, double quantity) override;
    virtual vector<Request *> *Require() override;
    virtual void Deliver(Resource *resource, double quantity) override;
};

#endif