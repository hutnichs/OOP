#pragma once

#include <memory>

class module1a {
public:
    module1a();
    ~module1a();
    int open();

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};

