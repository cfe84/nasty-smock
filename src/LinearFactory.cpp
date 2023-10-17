#include <vector>
#include "LinearFactory.h"
#include "Resource.h"
#include "Request.h"
#include "IProducer.h"

using namespace std;

LinearFactory::LinearFactory(Resource* input, Resource* output, double ratio)
{
    this->input = input;
    this->output = output;
    this->ratio = ratio;
    this->lastRequest = 0;
    availableResources = vector<Resource*> { output };
}

LinearFactory::~LinearFactory()

{}

vector<Resource*>* LinearFactory::AvailableResources()
{
    vector<Resource*>* resources = new vector<Resource*> {availableResources};
    return resources;
};

vector<Request*>* LinearFactory::GetRequests()
{
    Request* request = new Request(input, lastRequest);
    vector<Request*>* requests = new vector<Request*> {request};

    return requests;
}
