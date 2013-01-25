//
//  ofxTimerEvent.cpp
//  motherfarmLED
//
//  Created by 堀 宏行 on 11/28/12.
//
//

#include "ofxTimeEvent.h"

bool ofxTimeEventData::checkTime()
{
    curState = 0;
    if ( ofGetHours() == hour)
    {
        curState += 4; //100
    }
    if ( ofGetMinutes() == minutes)
    {
        curState += 2; //010
    }
    
    if ( ofGetSeconds() == second)
    {
        curState += 1;//001
    }
    return (curState & filter) == filter;
}

void ofxTimeEvent::update()
{
    for( int i = 0; i < datas.size(); i++)
    {
        if ( datas[i].checkTime())
        {
            if ( !datas[i].result )
            {
                datas[i].result = true;
                ofNotifyEvent(eventData, datas[i], this);
            }
        }
        else
        {
            datas[i].result = false;
        }
    }
}

void ofxTimeEvent::registerSec ( const int& _id, const int& sec )
{
    ofxTimeEventData dt;
    dt.filter = 1;
    dt._id = _id;
    dt.second = sec;
    registerTime(dt);
}

void ofxTimeEvent::registerMin ( const int& _id, const int& min )
{
    ofxTimeEventData dt;
    dt._id = _id;
    dt.filter = 2;
    dt.minutes = min;
    registerTime(dt);
}

void ofxTimeEvent::registerMinSec( const int& _id, const int& min, const int& sec)
{
    ofxTimeEventData dt;
    dt._id = _id;
    dt.filter = 3;
    dt.minutes = min;
    dt.second = sec;
    registerTime(dt);
}

void ofxTimeEvent::registerHour ( const int& _id, const int& hour )
{
    ofxTimeEventData dt;
    dt._id = _id;
    dt.filter = 4;
    dt.hour = hour;
    registerTime(dt);
}

void ofxTimeEvent::registerHourSec( const int& _id, const int& hour, const int& sec)
{
    ofxTimeEventData dt;
    dt._id = _id;
    dt.filter = 5;
    dt.hour = hour;
    dt.second = sec;
    registerTime(dt);
}

void ofxTimeEvent::registerHourMin( const int& _id, const int& hour, const int& min)
{
    ofxTimeEventData dt;
    dt._id = _id;
    dt.filter = 6;
    dt.hour = hour;
    dt.minutes = min;
    registerTime(dt);
}

void ofxTimeEvent::registerHourMinSec( const int& _id, const int& hour, const int& min, const int& sec)
{
    ofxTimeEventData dt;
    dt._id = _id;
    dt.filter = 7;
    dt.hour = hour;
    dt.minutes = min;
    dt.second = sec;
    registerTime(dt);
}

