#include <vector>
#include <algorithm>
#include "LinearFactory.h"
#include "Resource.h"
#include "QuantifiedResource.h"
#include "IProducer.h"

using namespace std;

LinearFactory::LinearFactory(Resource *input, Resource *output, double ratio)
{
    this->input = input;
    this->output = output;
    this->ratio = ratio;
    this->lastRequest = 0;
    this->inputResourceStock = 0;
    this->produced = 0;
    availableResources = vector<Resource *>{output};
}

LinearFactory::~LinearFactory()
{
}

vector<Resource *> *LinearFactory::AvailableResources()
{
    vector<Resource *> *resources = new vector<Resource *>{availableResources};
    return resources;
}

void LinearFactory::RequestProduction(Resource *resource, double desiredQuantity)
{
    this->lastRequest = desiredQuantity;
    double produceableQuantity = inputResourceStock / ratio;
    double producedQuantity = min(desiredQuantity, produceableQuantity);
    this->inputResourceStock -= producedQuantity * ratio;
    produced += producedQuantity;
}

vector<QuantifiedResource> LinearFactory::Produce()
{
    auto result = QuantifiedResource(output, produced);
    produced = 0;
    return vector<QuantifiedResource>{result};
}

vector<QuantifiedResource> LinearFactory::GetRequests()
{
    double inputRequired = (lastRequest * ratio) - inputResourceStock;
    auto request = QuantifiedResource(input, inputRequired);
    auto requests = vector<QuantifiedResource>{request};
    return requests;
}

void LinearFactory::Deliver(QuantifiedResource resource)
{
    inputResourceStock += resource.getQuantity();
}