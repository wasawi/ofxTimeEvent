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
    int id;
    bool isDispatched;
    uint result;
//    EVENT_MODE mode;
    uint filter, curState;
    
    ofxTimeEventData():hour(-1), minutes(-1), second(-1), isDispatched(false), filter(0), curState(0), result(false), id(0)
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
    vector<ofxTimeEventData> datas;

    ofxTimeEvent()
    {
        ofAddListener(ofEvents().update, this, &ofxTimeEvent::onUpdate);
    }
    
    bool checkNow();
    void registerHour ( int hour );
    void registerMin ( int min );
    void registerSec( int sec );
    void registerHourMin( int hour, int min);
    void registerMinSec( int min, int sec);
    void registerHourSec( int hour, int sec);
    void registerHourMinSec( int hour, int min, int sec);
    
    void onUpdate(ofEventArgs &data) { update();}
    void update();
private:
    void registerTime( ofxTimeEventData data)
    {
        datas.push_back(data);
    }
    
};


#endif
