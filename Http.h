//
// Created by hvalle on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_HTTPS_H
#define FIRSTEXAMPLE_HTTPS_H

#include <string>

class Http
{
public:
    virtual ~Http() {}
    virtual void initialize() = 0;
    virtual std::string get(const std::string& url) const = 0;
};


#endif //FIRSTEXAMPLE_HTTPS_H
