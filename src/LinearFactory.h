#ifndef LINEARFACTORY
#define LINEARFACTORY

#include <vector>
#include "Resource.h"
#include "IProducer.h"
#include "IConsumer.h"

using namespace std;

class LinearFactory : public IProducer, public IConsumer {
    Resource* input;
    Resource* output;
    double ratio;
    double lastRequest;
    vector<Resource*> availableResources;
    public:
        LinearFactory(Resource* input, Resource *output, double ratio);
        ~LinearFactory();
        virtual vector<Resource*>* AvailableResources() override;
        virtual vector<Request*>* GetRequests() override;
};

#endif