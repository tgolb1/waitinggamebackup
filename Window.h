#ifndef WINDOW_H
#define WINDOW_H

class Window {
    public:
        Window();
        ~Window();

    private:
        bool isIdle;
        int idleTime;
        int timeConsumed;

};

#endif