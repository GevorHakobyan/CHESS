#ifndef HANDLER_HPP
#define HANDLER_HPP

class Handler {
    public:
    virtual Handler& setNextHandler() = 0;
    virtual bool HandleRequest() = 0;
};

#endif