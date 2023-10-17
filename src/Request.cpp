#include "Resource.h"
#include "Request.h"

Request::Request(Resource* resource, double quantity)
{
    this->resource = resource;
    this->quantity = quantity;
}

Resource* Request::getResource()
{
    return resource;
}

double Request::getQuantity()
{
    return quantity;
}
