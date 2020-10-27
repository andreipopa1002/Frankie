#ifndef WifiManagerPresenter_h
#define WifiManagerPresenter_h
#include "Presenter/Presenter.h"
class String;

class WifiManagerPresenter: public Presenter {
    public:
        using Presenter::Presenter;
        void begin();
        void enteringConfigMode(String wifiName);
        void failedToConnect();
        void connectedToWifi(String wifiName);

};

#endif