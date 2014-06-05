#include "ofxSpinCursor.h"

//----------
void ofxSpinCursor::draw(const ofVec2f & xy) {
	float maxDistance = ofVec2f(ofGetScreenWidth(), ofGetScreenHeight()).length();
	
	ofPushStyle();
	ofPushMatrix();
	
	ofSetLineWidth(1.0f);
	ofNoFill();
	
	ofTranslate(xy);
	ofRect(-10, -10, 20, 20);
	ofLine(-10, -10, +10, +10);
	ofLine(+10, -10, -10, +10);
	
	ofPushMatrix();
	ofRotate(ofGetElapsedTimef() * 360.0f / OFXSPINCURSOR_PERIOD);
	for(int i=0; i < OFXSPINCURSOR_PETAL_COUNT; i++) {
		ofLine(20.0f, 0, maxDistance, 0);
		ofRotate(360.0f / (float) OFXSPINCURSOR_PETAL_COUNT);
	}
	ofPopMatrix();
	
	ofMesh point;
	for(int i=0; i<3; i++) {
		point.addVertex(ofVec3f(0.0f));
		point.addColor(ofColor((ofGetElapsedTimeMillis() / 3)% 255));
	}
	point.drawVertices();
	
	ofPopMatrix();
	ofPopStyle();
}

//----------
void ofxSpinCursor::draw(float x, float y) {
	ofxSpinCursor::draw(ofVec2f(x, y));
}