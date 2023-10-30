#include "Resource.h"
#include "QuantifiedResource.h"

QuantifiedResource::QuantifiedResource(Resource *resource, double quantity)
{
    this->resource = resource;
    this->quantity = quantity;
}

QuantifiedResource::QuantifiedResource(QuantifiedResource *original)
{
    this->resource = original->resource;
    this->quantity = original->quantity;
}

Resource *QuantifiedResource::getResource()
{
    return resource;
}

double QuantifiedResource::getQuantity()
{
    return quantity;
}
