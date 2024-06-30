#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/include/SDL.h>

class Input {
public:
    void Update();
    bool IsQuit() const;

private:
    bool quit;
};

#endif // INPUT_HPP
