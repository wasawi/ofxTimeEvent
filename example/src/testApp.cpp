#include "testApp.h"

void testApp::listenEvent( ofxTimeEventData& data )
{
    cout << "TIME EVENT DISPATCHED EVENT NO:" << data._id << endl;
}

//--------------------------------------------------------------
void testApp::setup(){
    event = ofxTimeEvent::getInstance();
    ofAddListener( event->eventData, this, &testApp::listenEvent);
    event->registerMin(1, 9);
    event->registerMin(2, 10);
    event->registerMin(3, 11);
    event->registerMin(4, 12);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}