#ifndef SCREEN_H
#define SCREEN_H

class Screen {
public:
    virtual void view() = 0;
    virtual ~Screen() = default;
};

#endif