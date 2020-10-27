#ifndef Presenter_h
#define Presenter_h
class Logger;
class String;

class Presenter {
    public:
        Presenter(Logger *logger);
        void loading(String message, int duration);
    protected:
        Logger *_logger;
};

#endif