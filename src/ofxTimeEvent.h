//
//  ofxTimerEvent.h
//  motherfarmLED
//
//  Created by 堀 宏行 on 11/28/12.
//
//

#ifndef motherfarmLED_ofxTimerEvent_h
#define motherfarmLED_ofxTimerEvent_h
#include "ofMain.h"
//TODO
//enum EVENT_TYPE
//{
//    T_MORE, T_EQUAL, T_LESS
//};

class ofxTimeEventData
{
public:
    int _id;
    bool isDispatched;
    uint result;
//    EVENT_MODE mode;
    uint filter, curState;
    
    ofxTimeEventData():hour(-1), minutes(-1), second(-1), isDispatched(false), filter(0), curState(0), result(false), _id(0)
    {
    }
    
    bool checkTime();
    int hour, minutes, second;
//    EVENT_TYPE t;
};

class ofxTimeEvent
{
public:
    ofEvent<ofxTimeEventData > eventData;
    
    static ofxTimeEvent* getInstance()
    {
        static ofxTimeEvent instance;
        return &instance;
    }
    
    bool checkNow();
    void registerHour ( const int& _id, const int& hour );
    void registerMin ( const int& _id, const int& min );
    void registerSec ( const int& _id, const int& sec );
    void registerHourMin ( const int& _id, const int& hour, const int& min);
    void registerMinSec ( const int& _id, const int& min, const int& sec);
    void registerHourSec ( const int& _id, const int& hour, const int& sec);
    void registerHourMinSec ( const int& _id, const int& hour, const int& min, const int& sec);
    
    void onUpdate(ofEventArgs& data) { update();}
    void update();
private:
    
    ofxTimeEvent()
    {
        ofAddListener(ofEvents().update, this, &ofxTimeEvent::onUpdate);
    }
    ofxTimeEvent(const ofxTimeEvent& rhs);
    ofxTimeEvent& operator=(const ofxTimeEvent& rhs);
    
    vector<ofxTimeEventData> datas;
    void registerTime( const ofxTimeEventData& data)
    {
        datas.push_back(data);
    }
};


#endif
