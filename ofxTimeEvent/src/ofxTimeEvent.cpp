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

void ofxTimeEvent::registerSec( int sec )
{
    ofxTimeEventData dt;
    dt.filter = 1;
    dt.second = sec;
    registerTime(dt);
}

void ofxTimeEvent::registerMin ( int min )
{
    ofxTimeEventData dt;
    dt.filter = 2;
    dt.minutes = min;
    registerTime(dt);
}

void ofxTimeEvent::registerMinSec( int min, int sec)
{
    ofxTimeEventData dt;
    dt.filter = 3;
    dt.minutes = min;
    dt.second = sec;
    registerTime(dt);
}

void ofxTimeEvent::registerHour ( int hour )
{
    ofxTimeEventData dt;
    dt.filter = 4;
    dt.hour = hour;
    registerTime(dt);
}

void ofxTimeEvent::registerHourSec( int hour, int sec)
{
    ofxTimeEventData dt;
    dt.filter = 5;
    dt.hour = hour;
    dt.second = sec;
    registerTime(dt);
}

void ofxTimeEvent::registerHourMin( int hour, int min)
{
    ofxTimeEventData dt;
    dt.filter = 6;
    dt.hour = hour;
    dt.minutes = min;
    registerTime(dt);
}

void ofxTimeEvent::registerHourMinSec( int hour, int min, int sec)
{
    ofxTimeEventData dt;
    dt.filter = 7;
    dt.hour = hour;
    dt.minutes = min;
    dt.second = sec;
    registerTime(dt);
}

