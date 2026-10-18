#pragma once
#include <QString>
#include <functional>
#include <memory>

class module2 {
public:
    module2();
    ~module2();

    void open(std::function<void(const QString&)> onTextSelected);

private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};
