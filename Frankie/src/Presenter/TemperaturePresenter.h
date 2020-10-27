#ifndef TemperaturePresenter_h
#define TemperaturePresenter_h
#include "Presenter/Presenter.h"

class TemperaturePresenter: public Presenter {
    public:
        using Presenter::Presenter;
        void begin();
        void setupScreen();
        void mainScreen(float temperature, bool isTopFanOn, bool isSideFanOn);
};

#endif