/*
	Code created by Kelia Murata 
	Images acquired from Google images png library: pixgood, oasisbay
	working with art assets and creating an animated scene with keyboard interaction 
*/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	//control how many frames run per second 
	ofSetFrameRate(20); 

	//load all my images to the program 
	//Note: different loading call for textures 
	fly.loadImage("fly1.png");
	beetle.loadImage("beetle.png");
	flySwatter.loadImage("flySwatter.png");
	fruit.loadImage("fruit.png");
	counter.loadImage("counterTop.jpg");
	hand.loadImage("handSide.png");

	//changing the anchor point of the image 
	fly.setAnchorPercent(0.5, 0.5);
	flySwatter.setAnchorPercent(0.5, 0.5);

	//setting the starting position and velocity of my beetle 
	pos = ofVec2f(150,200);
	vel = ofVec2f(.5, .5); 

	//setting all of my boolean statements to false for start of program 
	fSmack = false;
	bSmack = false; 
	fStop = false; 
	bStop = false; 
}

//--------------------------------------------------------------
void ofApp::update()
{
	//if the fly has stopped (because its been squished) don't update it's position otherwise update
	//the flys x and y position using noise 
	if(fStop == false)
	{
		flyx = ofMap( ofNoise( ofGetElapsedTimef()), 0, 1, 0, fruit.getWidth()/2);
		flyy = ofMap( ofNoise( 1000.0 + ofGetElapsedTimef()), 0, 1, 0, fruit.getHeight()/2);
	}

	//if the beetle has stopped (because it's been squished) don't update position, otherwise 
	//update its position and check for boundry blocks and change velocity accordingly 
	if(bStop == false)
	{
		pos += vel; 
		if( (pos.x > 245) || (pos.x < 10) )  //check sides 
		{
			vel.x *= -1;
		}

		if( (pos.y > 245) || (pos.y < 205) ) //check up and down 
		{
			vel.y *= -1; 
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::draw()
{
	//create the scene of the kitch counter and fruit by frist drawing the counter than fruit atop it 
	counter.draw(0,0);
	fruit.draw(-140, -140);

	//if the beetle hasn't been squished yet, draw it at its position determined in update 
	if(bSmack == false)
	{
		beetle.draw(pos); 
	}

	//if the fly hasn't been hit yet, draw it at its position determined in update 
	if(fSmack == false)
	{
		fly.draw(flyx, flyy);
	}

	//Note: both images are accounting for offset so the part of the image (ie the hand and head of swatter)
	//are where the bug was instead of the wrist or handle of the image 
	//if the fly has been hit, draw the flyswatter where the fly had been on screen 
	if(fSmack == true)
	{	
		flySwatter.draw(flyx,  flyy + 330);
	}

	//if the beetle has been hit, draw the hand where the beetle had been on screen 
	if(bSmack == true)
	{
		hand.draw(pos.x - 380 , pos.y - 50); 
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	//if the f key is pressed, the 'fly' will be squished 
	if(key == 'f')
	{
		fSmack = true;
		fStop = true; 
	}
	//if the b key is pressed, the 'beetle' will be squished 
	if(key == 'b')
	{
		bSmack = true; 
		bStop = true; 
	}
}

