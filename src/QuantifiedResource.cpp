#include "Resource.h"
#include "QuantifiedResource.h"

QuantifiedResource::QuantifiedResource(Resource *resource, double quantity)
{
    this->resource = resource;
    this->quantity = quantity;
}

Resource *QuantifiedResource::getResource()
{
    return resource;
}

double QuantifiedResource::getQuantity()
{
    return quantity;
}
