#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

		ofImage fly, beetle, flySwatter, fruit, counter, hand;

		float flyx, flyy;
		
		ofVec2f pos, vel; 

		bool fSmack ,bSmack, fStop, bStop; 

};
