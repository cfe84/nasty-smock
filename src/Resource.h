#ifndef RESOURCE
#define RESOURCE

#include <string>

class Resource {
    std::string name;
    public:
        Resource(std::string name);
        std::string getName();
};

#endif