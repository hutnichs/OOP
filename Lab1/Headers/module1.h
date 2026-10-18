#pragma once

#include <memory>

class module1 {
public:
    module1();
    ~module1();
    void open();

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};
