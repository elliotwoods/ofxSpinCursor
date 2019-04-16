#include "ofxSpinCursor.h"

//----------
void ofxSpinCursor::draw(const glm::vec2 & xy) {
	float maxDistance = ofVec2f(ofGetScreenWidth(), ofGetScreenHeight()).length();
	
	ofPushStyle();
	{
		ofPushMatrix();
		{
			ofTranslate(xy);
			
			ofSetLineWidth(1.0f);

			//draw shaded region
			ofEnableAlphaBlending();
			ofFill();
			ofSetColor(0, 80);
			ofDrawRectangle(-10, -10, 20, 20);

			//draw cross
			ofNoFill();
			ofSetColor(255);
			ofDrawRectangle(-10, -10, 20, 20);
			ofDrawLine(-10, -10, -3, -3);
			ofDrawLine(+10, +10, +3, +3);
			ofDrawLine(+10, -10, +3, -3);
			ofDrawLine(-10, +10, -3, +3);

			//draw spin
			ofPushMatrix();
			ofRotateDeg(-ofGetElapsedTimef() * 360.0f / OFXSPINCURSOR_PERIOD);
			for (int i = 0; i < OFXSPINCURSOR_PETAL_COUNT; i++) {
				ofDrawLine(20.0f, 0, maxDistance, 0);
				ofRotateDeg(360.0f / (float)OFXSPINCURSOR_PETAL_COUNT);
			}
			ofPopMatrix();

			//draw center point
			ofMesh point;
			for (int i = 0; i < 3; i++) {
				point.addVertex(ofVec3f(0.0f));
				point.addColor(ofColor((ofGetElapsedTimeMillis() / 1) % 255));
			}
			point.drawVertices();

		}
		ofPopMatrix();
	}
	ofPopStyle();
}

//----------
void ofxSpinCursor::draw(float x, float y) {
	ofxSpinCursor::draw(ofVec2f(x, y));
}