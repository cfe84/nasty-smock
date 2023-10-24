#include <vector>
#include <algorithm>
#include "LinearFactory.h"
#include "Resource.h"
#include "Request.h"
#include "IProducer.h"

using namespace std;

LinearFactory::LinearFactory(Resource *input, Resource *output, double ratio)
{
    this->input = input;
    this->output = output;
    this->ratio = ratio;
    this->lastRequest = 0;
    this->inputResourceStock = 0;
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

double LinearFactory::Produce(Resource *resource, double desiredQuantity)
{
    this->lastRequest = desiredQuantity;
    double produceableQuantity = inputResourceStock / ratio;
    double producedQuantity = min(desiredQuantity, produceableQuantity);
    this->inputResourceStock -= producedQuantity * ratio;
    return producedQuantity;
}

vector<Request *> *LinearFactory::Require()
{
    double inputRequired = (lastRequest * ratio) - inputResourceStock;
    Request *request = new Request(input, inputRequired);
    vector<Request *> *requests = new vector<Request *>{request};
    return requests;
}

void LinearFactory::Deliver(Resource *resource, double quantity)
{
    inputResourceStock += quantity;
}