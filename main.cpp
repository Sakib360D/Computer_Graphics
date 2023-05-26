#include<bits/stdc++.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
///For music
#include <Mmsystem.h>
#include<windows.h>
#include<fstream>

using namespace std;
#pragma comment(lib, "Winmm.lib")
#define int GLint
#define PI 3.1416


float cpos1=200,cpos2=400,cpos3=-250,cpos4=50,cpos5=490,sp1=2.0f,bul=0;
float sun_x=620 ,sun_y=330,sp_x=0.5f,sp_y=1.0f,plane_x=0.0f, plane_speed=4.5f,_rain = 0.0;

bool rainday = false, day = true,fire=true;
float TruckTireRotateAngle = 0.0f;
int _TruckMoveReverse = 0;

///Circle
void circle(GLfloat x, GLfloat y, GLfloat rad){
    GLint triangle_amt=60,i;
    GLfloat t_pi=2*PI;
    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(43,78,88);
    glVertex2f(x,y);
    for(i=0;i<=triangle_amt;i++){
        GLfloat dx=rad*cos(i*t_pi/triangle_amt), dy=rad*sin(i*t_pi/triangle_amt);
        glVertex2f(x+dx,y+dy);
    }
    glEnd();
}
///Cloud Model-1 Structure
void cloudModel1(){
    if(day)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();

   glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();

    glPopMatrix();

}
///Cloud Model-2 Structure
void cloudModel2(){
    if(day)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();
}
///Cloud Model-3 Structure
void cloudModel3(){

    if(day)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();
    glPopMatrix();
}

///Sky
void sky(){
    glPushMatrix();
    if(day)glColor3ub(157, 216, 250);
    else glColor3ub(4, 11, 51);

    glBegin(GL_POLYGON);
    glVertex2i(0,300);
    glVertex2i(1000,300);
    glVertex2i(1000,500);
    glVertex2i(0,500);
    glEnd();
    glPopMatrix();
}



void tilla1(){

	glBegin(GL_POLYGON);
	glColor3ub(0,128,0);

	glVertex2i(0, 300);
	glVertex2i(300, 300);
	glVertex2i(150, 370);
glEnd();
}

void tilla2(){
     glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(34,139,34);

	glVertex2i(250, 300);
	glVertex2i(550, 300);
	glVertex2i(400, 380);


	glEnd();
	glPopMatrix();
}

void tilla3(){
     glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(0,128,0);

	glVertex2i(500, 300);
	glVertex2i(750, 300);
	glVertex2i(650, 370);


	glEnd();
	glPopMatrix();
}
void tilla4(){
     glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(34,139,34);

	glVertex2i(700, 300);
	glVertex2i(1000, 300);
	glVertex2i(900, 380);


	glEnd();
	glPopMatrix();
}
///Sun
void sun(){
    if(day){
        glPushMatrix();
        glColor3ub(252, 212, 64);
        glTranslatef(sun_x,sun_y,0.0);
        circle(0,0,30);
        glPopMatrix();
    }
}
///Moon
void moon(){
    if(!day){
        glPushMatrix();

        glColor3ub(255, 255, 255);
        glTranslatef(0.0,100.0,0.0);
        circle(320,360,20);
        glColor3ub(4, 11, 51);
        circle(320,380,15);
        glPopMatrix();
    }
}
///Star
void star(){
    if(!day){
        glPushMatrix();
        glColor3ub(255,255,255);
        glPointSize(4);
        glBegin(GL_POINTS);

        glVertex2i(100,400);
        glVertex2i(120,420);
        glVertex2i(150,450);
        glVertex2i(170,470);
        glVertex2i(200,430);
        glVertex2i(230,470);
        glVertex2i(350,460);
        glVertex2i(900,400);
        glVertex2i(580,470);
        glVertex2i(840,460);
        glVertex2i(750,400);
        glVertex2i(950,400);
        glVertex2i(760,420);
        glVertex2i(690,450);
        glVertex2i(550,470);
        glVertex2i(790,430);
        glVertex2i(830,470);
        glVertex2i(690,460);
        glVertex2i(590,400);
        glVertex2i(490,430);
        glVertex2i(330,470);
        glVertex2i(390,460);
        glVertex2i(460,400);
        glVertex2i(390,360);
        glVertex2i(930,370);
        glVertex2i(30,370);
        glVertex2i(290,360);
        glVertex2i(60,360);
        glEnd();

        glPopMatrix();
    }
}

///cloud1
void cloud1(){

        glPushMatrix();
        glTranslatef(cpos1,170,0);
         glTranslatef(50,50,0);
        cloudModel1();
        glPopMatrix();

}
///cloud2
void cloud2(){
    if(day){
        glPushMatrix();
        glTranslatef(cpos2,270,0);
         glTranslatef(25,0,0);
        cloudModel2();
        glPopMatrix();
    }
}
///cloud3
void cloud3(){

        glPushMatrix();
        glTranslatef(cpos3,200,0);
         glTranslatef(-50,50,0);
        cloudModel3();
        glPopMatrix();

}
///cloud4
void cloud4(){
    glPushMatrix();
    glTranslatef(cpos4,250,0);
     glTranslatef(-50,20,0);
    cloudModel2();
    glPopMatrix();
}

///cloud5
void cloud5(){
    glPushMatrix();
    glTranslatef(cpos5,220,0);
     glTranslatef(-25,25,0);
    cloudModel1();
    glPopMatrix();
}

///Airplane Design
void airPlane(){
    glPushMatrix();
    glTranslatef(plane_x,370,0);

    glPushMatrix();
    glTranslatef(0,75,0);
    ///body
    glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON); //rectangular body
        glVertex2f(0.0, 30.0*0.4);
        glVertex2f(0.0, 55.0*0.4);
        glVertex2f(135.0*0.4, 55.0*0.4);
        glVertex2f(135.0*0.4, 30.0*0.4);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON); //upper triangle construction plane
        glVertex2f(135.0*0.4, 55.0*0.4);
        glVertex2f(150.0*0.4, 50.0*0.4);
        glVertex2f(155.0*0.4, 45.0*0.4);
        glVertex2f(160.0*0.4, 40.0*0.4);
        glVertex2f(135.0*0.4, 40.0*0.4);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINE_LOOP); //outline of upper triangle plane
        glVertex2f(135.0*0.4, 55.0*0.4);
        glVertex2f(150.0*0.4, 50.0*0.4);
        glVertex2f(155.0*0.4, 45.0*0.4);
        glVertex2f(160.0*0.4, 40.0*0.4);
        glVertex2f(135.0*0.4, 40.0*0.4);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON); //lower triangle
        glVertex2f(135.0*0.4, 40.0*0.4);
        glVertex2f(160.0*0.4, 40.0*0.4);
        glVertex2f(160.0*0.4, 37.0*0.4);
        glVertex2f(145.0*0.4, 30.0*0.4);
        glVertex2f(135.0*0.4, 30.0*0.4);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON); //back wing
        glVertex2f(0.0, 55.0*0.4);
        glVertex2f(0.0, 80.0*0.4);
        glVertex2f(10.0*0.4, 80.0*0.4);
        glVertex2f(40.0*0.4, 55.0*0.4);
        glEnd();
        // glPopMatrix();

        // glPushMatrix();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON); //left side wing
        glVertex2f(65.0*0.4, 55.0*0.4);
        glVertex2f(50.0*0.4, 70.0*0.4);
        glVertex2f(75.0*0.4, 70.0*0.4);
        glVertex2f(90.0*0.4, 55.0*0.4);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON); //rightside wing
        glVertex2f(70.0*0.4, 40.0*0.4);
        glVertex2f(100.0*0.4, 40.0*0.4);
        glVertex2f(80.0*0.4, 15.0*0.4);
        glVertex2f(50.0*0.4, 15.0*0.4);

        glEnd();
glPopMatrix();
    glPopMatrix();


}
void field(){
glPushMatrix();
    if(day)glColor3ub(96,185,34);
    else glColor3ub(96,185,34);

    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(1000,0);
    glVertex2i(1000,300);
    glVertex2i(0,300);
    glEnd();
    glPopMatrix();



}
void treemodel(){
    if(day) glColor3ub(0, 173, 36);
    else glColor3ub(17, 102, 30);
    circle(130,130,7);
    circle(125,126,7);
    circle(135,126,7);
    circle(130,125,7);

    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(129,104);
    glVertex2i(129,126);
    glVertex2i(131,126);
    glVertex2i(131,104);
    glEnd();
}
void tree1(){
    glPushMatrix();
    glTranslatef(-100,195,0);
    treemodel();
    glPopMatrix();
}
 void tree2(){
    glPushMatrix();
    glTranslatef(100,195,0);
    treemodel();
    glPopMatrix();
}
 void tree3(){
    glPushMatrix();
    glTranslatef(120,195,0);
    treemodel();
    glPopMatrix();
}

void tree4(){
    glPushMatrix();
    glTranslatef(-80,195,0);
    treemodel();
    glPopMatrix();
}
void tree5(){
    glPushMatrix();
    glTranslatef(-60,195,0);
    treemodel();
    glPopMatrix();
}
void tree6(){
    glPushMatrix();
    glTranslatef(300,195,0);
    treemodel();
    glPopMatrix();
}
void tree7(){
    glPushMatrix();
    glTranslatef(320,195,0);
    treemodel();
    glPopMatrix();
}
void tree8(){
    glPushMatrix();
    glTranslatef(340,195,0);
    treemodel();
    glPopMatrix();
}
void tree9(){
    glPushMatrix();
    glTranslatef(360,195,0);
    treemodel();
    glPopMatrix();
}
void tree10(){
    glPushMatrix();
    glTranslatef(380,195,0);
    treemodel();
    glPopMatrix();
}

void tree11(){
    glPushMatrix();
    glTranslatef(540,195,0);
    treemodel();
    glPopMatrix();
}
 void tree12(){
    glPushMatrix();
    glTranslatef(560,195,0);
    treemodel();
    glPopMatrix();
}
 void tree13(){
    glPushMatrix();
    glTranslatef(580,195,0);
    treemodel();
    glPopMatrix();
}

void tree14(){
    glPushMatrix();
    glTranslatef(620,195,0);
    treemodel();
    glPopMatrix();
}
void tree15(){
    glPushMatrix();
    glTranslatef(640,195,0);
    treemodel();
    glPopMatrix();
}
void tree16(){
    glPushMatrix();
    glTranslatef(680,195,0);
    treemodel();
    glPopMatrix();
}
void tree17(){
    glPushMatrix();
    glTranslatef(700,195,0);
    treemodel();
    glPopMatrix();
}
void tree18(){
    glPushMatrix();
    glTranslatef(720,195,0);
    treemodel();
    glPopMatrix();
}
void tree19(){
    glPushMatrix();
    glTranslatef(800,195,0);
    treemodel();
    glPopMatrix();
}
void tree20(){
    glPushMatrix();
    glTranslatef(820,195,0);
    treemodel();
    glPopMatrix();
}


void TruckTire(int xx, int yy, float r)//C029//H103
{
    glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
glTranslatef(0.0f,0.0f,0.0f);
glRotatef(TruckTireRotateAngle, 0.0f, 0.0f,1.0f);
glTranslatef(-0.0f,-0.0f,0.0f);
glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {

        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;

        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xx, y + yy);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);//black-rim
    glVertex2f(-0.075,0);
    glVertex2f(0.075,0);

    glVertex2f(-0.05,-0.075);
    glVertex2f(0.05,0.075);

    glVertex2f(0.05,-0.075);
    glVertex2f(-0.05,0.075);

    glVertex2f(0,-0.1);
    glVertex2f(0,0.1);

    glEnd();

    glPopMatrix();

}
void TruckScaledTire()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(140.1,95,0);
    glScalef(90,90,0);
    glColor3ub(0,0,0);//black-tire
    TruckTire(0, 0, 0.2);
    glColor3ub(192,192,192);//silver-tire-rim
    TruckTire(0,0,0.13);
    glColor3ub(211,211,255);//grey-tire-rim
    TruckTire(0,0,0.09);
    glPopMatrix();
}

void TruckBody()
{

    glColor3ub(128,128,0); //blue-body

    glBegin(GL_POLYGON);
    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(240, 127);
    glVertex2f(240, 92);
    glVertex2f(150,92);
    glEnd();

    glBegin(GL_POLYGON);//trolly
    glVertex2f(150, 129);
    glVertex2f(60,129);
    glVertex2f(60,92);
    glVertex2f(150,92);
    glEnd();
     glBegin(GL_POLYGON);//trolly-cargo
     glColor3ub(169, 120, 53);//brown
    glVertex2f(70,129);
    glVertex2f(100,129);
    glVertex2f(100, 152);
    glVertex2f(70,152);
    glEnd();

    glColor3ub(9, 12, 53);//black
     //text(90.0,130.0,text3);
    glBegin(GL_POLYGON); //back-light
    glColor3ub(255, 0, 0);
    glVertex2f(110-50, 92);
    glVertex2f(115-50, 92);
    glVertex2f(115-50, 117);
    glVertex2f(110-50, 117);
    glEnd();

    glBegin(GL_POLYGON); //window
    glColor3ub(0, 0, 0);//black-window-in-day
    if(!day)
    glColor3ub(163, 228, 215);//gray-window-in-night
    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(150, 127);
    glVertex2f(130, 127);
    glEnd();





    glBegin(GL_POLYGON); //window-Divider
    glColor3ub(192, 192, 192);
    glVertex2f(170, 152);
    glVertex2f(165, 152);
    glVertex2f(165, 127);
    glVertex2f(170, 127);
    glEnd();



    glBegin(GL_POLYGON); //roof-plate
    glColor3ub(168, 169, 173);

    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(185, 157);
    glVertex2f(150, 157);
    glEnd();

    glBegin(GL_POLYGON); //window-holder-front
    glColor3ub(168, 169, 173);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(185, 152);
    glEnd();

    glBegin(GL_POLYGON); //window-holder-back
    glColor3ub(168, 169, 173);
    glVertex2f(140+20-10, 157);
    glVertex2f(115+20, 127);
    glVertex2f(125+20, 127);
    glVertex2f(140+20-10, 152);
    glEnd();

    glBegin(GL_POLYGON); //foot-holder
    glColor3ub(168, 169, 173);
    glVertex2f(242, 92);
    glVertex2f(60, 92);
    glVertex2f(60, 97);
    glVertex2f(242, 97);

    glEnd();

    glBegin(GL_POLYGON);      //mirror
    glColor3f(0, 0, 0.1373);
    glVertex2f(211.5, 134.5);
    glVertex2f(204.5, 135.5);
    glVertex2f(203.5, 129);
    glVertex2f(210.5, 127);
    glEnd();

    glBegin(GL_POLYGON);      //Yellow-headlight
    glColor3f(1.0, 1.0, 0.0); //body
    glVertex2f(210.5+28, 134.5-10);
    glVertex2f(203.5+28, 135.5-10);
    glVertex2f(203.5+28, 129-10);
    glVertex2f(210.5+28, 127-10);
    glEnd();
    if(!day)
    {
        glBegin(GL_POLYGON);      //Yellow-headlight
        glColor3f(1.0, 1.0, 1.0); //body
        glVertex2f(210.5+28+90, 134.5-10-0);
        glVertex2f(205.5+28, 134.5-10);
        glColor3f(0.8, 0.9, 0.0);
        glVertex2f(205.5+28, 127-10);
        glVertex2f(210.5+28+90, 127-10-30);
        glEnd();

    }

    glBegin(GL_POLYGON); //window-opener-1
    glColor3ub(192, 192, 192);
    glVertex2f(150-15-5+20, 127-5-3);
    glVertex2f(155-5-5+20, 127-5-3);
    glVertex2f(155-5-5+20, 129-5);
    glVertex2f(150-15-5+20, 129-5);
    glEnd();
    glBegin(GL_POLYGON); //window-opener-2
    glColor3ub(192, 192, 192);
    glVertex2f(150-15+40, 127-5-3);
    glVertex2f(155-5+40, 127-5-3);
    glVertex2f(155-5+40, 129-5);
    glVertex2f(150-15+40, 129-5);
    glEnd();
}
void TruckThrust()
{
    if(day)
    {
        glBegin(GL_POLYGON);
        glColor3ub(168, 169, 173);
        glVertex2f(110-50, 92);
        glColor3ub(255, 255, 255);
        glVertex2f(00-50, 80);
        glVertex2f(00-50, 110);
        glColor3ub(0, 0, 0);
        glVertex2f(110-50, 97);
        glEnd();
    }


}
void fullTruck()
{

    TruckBody();
    glPushMatrix();
    glTranslatef(65,0,0);
    TruckScaledTire();
    glTranslatef(-85,0,0);
    TruckScaledTire();
    glPopMatrix();

}
void TruckReverse()
{
    glLineWidth(1);

    glTranslatef(-100.5, 0, 0);

    fullTruck();


}
void rocket(){
        glBegin(GL_POLYGON);

        glColor3ub(255, 255, 255);//body

        glVertex2f(250, 200);
        glVertex2f(300, 200);
        glVertex2f(300, 220);
        glVertex2f(250, 220);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);//head

        glVertex2f(250, 200);
        glVertex2f(250, 220);
        glVertex2f(230, 210);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(255, 0, 0);//leg

        glVertex2f(300, 200);
        glVertex2f(300, 220);
        glVertex2f(305, 225);
        glVertex2f(305, 195);

        glEnd();


        glPushMatrix();
    if(fire)glTranslatef(bul,0,0);
        glBegin(GL_POLYGON);
        glColor3ub(105,105,105);//bullet

        glVertex2f(230, 208);
        glVertex2f(230, 212);
        glVertex2f(220, 212);
        glVertex2f(220, 208);

        glEnd();
        glPopMatrix();





}
void ScaledTruckReverse()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(500,140,0);
    glScalef(-0.7,0.7,0);
    TruckReverse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(190,48,0);
    rocket();
    glPopMatrix();

}
///////////////---------////////////////////


void ScaledTruck2Reverse()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(600,200,0);
    glScalef(-0.7,0.7,0);
    TruckReverse();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(286,108,0);
    rocket();
    glPopMatrix();

}



void ScaledTruck3Reverse()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(608,58,0);
    glScalef(-0.7,0.7,0);
    TruckReverse();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(295,-33,0);
    rocket();
    glPopMatrix();

}


void ScaledTruck4Reverse()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(655,142,0);
    glScalef(-0.7,0.7,0);
    TruckReverse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(349,51,0);
    rocket();
    glPopMatrix();

}



//////////////////////////////////
////////////////For Tank////////////////////////

void tankrocket(){
        glBegin(GL_POLYGON);

        //glColor3ub(255, 255, 255);//body
        //glColor3f(0.0f, 1.0f, 0.0f);//Green
        //glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
        glColor3f(0.0f, 0.0f, 1.0f);//Blue
        //glColor3f(0.5f, 1.0f, 1.0f);//cyan

        glVertex2f(250, 200);
        glVertex2f(300, 200);
        glVertex2f(300, 220);
        glVertex2f(250, 220);

        glEnd();

        glBegin(GL_POLYGON);
       // glColor3ub(255, 0, 0);//head
        glColor3f(0.0f, 1.0f, 0.0f);//Green
        //glColor3f(0.0f, 0.0f, 1.0f);//Blue
        glVertex2f(250, 200);
        glVertex2f(250, 220);
        glVertex2f(230, 210);

        glEnd();

        glBegin(GL_POLYGON);
        //glColor3ub(255, 0, 0);//leg
        //glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
        glColor3f(0.0f, 0.1f, 0.0f);//Forest Green

        glVertex2f(300, 200);
        glVertex2f(300, 220);
        glVertex2f(305, 225);
        glVertex2f(305, 195);

        glEnd();


        glPushMatrix();
    if(fire)glTranslatef(bul,0,0);
        glBegin(GL_POLYGON);
        //glColor3ub(105,105,105);//bullet
        glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red

        glVertex2f(230, 208);
        glVertex2f(230, 212);
        glVertex2f(220, 212);
        glVertex2f(220, 208);

        glEnd();
        glPopMatrix();





}

void TankTire(int xx, int yy, float r)//C029//H103
{
    glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
glTranslatef(0.0f,0.0f,0.0f);
glRotatef(TruckTireRotateAngle, 0.0f, 0.0f,1.0f);
glTranslatef(-0.0f,-0.0f,0.0f);
glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {

        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;

        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xx, y + yy);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);//black-rim
    //glColor4f(1.0f, 0.5f, 0.0f, 0.0f);//orange/brown
    glVertex2f(-0.075,0);
    glVertex2f(0.075,0);

    glVertex2f(-0.05,-0.075);
    glVertex2f(0.05,0.075);

    glVertex2f(0.05,-0.075);
    glVertex2f(-0.05,0.075);

    glVertex2f(0,-0.1);
    glVertex2f(0,0.1);

    glEnd();

    glPopMatrix();

}

void TankScaledTire()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(140.1,95,0);
    glScalef(90,90,0);
    glColor3ub(0,0,0);//black-tire
    //glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
    //glColor3f(2.0f, 0.5f, 1.0f);//Lilac

    TankTire(0, 0, 0.2);
    //glColor3ub(192,192,192);//silver-tire-rim
    //glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glColor3f(2.0f, 0.5f, 1.0f);//Lilac

    TankTire(0,0,0.13);
    glColor3ub(211,211,255);//grey-tire-rim
    TankTire(0,0,0.09);
    glPopMatrix();
}

void TankBody()
{

    //glColor3ub(128,128,0); //blue-body

   glColor3f(0.0f, 0.1f, 0.0f);//Forest Green
    //glColor3f(0.0f, 0.0f, 1.0f);//Blue

    glBegin(GL_POLYGON); //body
    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(240, 127);
    glVertex2f(240, 92);
    glVertex2f(150,92);
    glEnd();

    glBegin(GL_POLYGON);//Back
        glVertex2f(150, 152);
        glVertex2f(81,152);
        glVertex2f(60,90);
        glVertex2f(150,91);
    glEnd();

     glBegin(GL_POLYGON);//BackUpper
        glVertex2f(140, 195);
        glVertex2f(95,195);
        glVertex2f(81,152);
        glVertex2f(190,152);
    glEnd();








    //box in back
     glBegin(GL_POLYGON);//trolly-cargo
     //glColor3ub(169, 120, 53);//brown
     glColor3f(0.0f, 0.1f, 0.0f);//Forest Green
    glVertex2f(50,140);
    glVertex2f(120,152);
    glVertex2f(120, 90);
    glVertex2f(50,90);
    glEnd();



    glColor3ub(9, 12, 53);//black
     //text(90.0,130.0,text3);
    glBegin(GL_POLYGON); //back-light
    //glColor3ub(255, 0, 0);
    //glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red

    glVertex2f(100-50, 105);
    glVertex2f(105-50, 105);
    glVertex2f(105-50, 125);
    glVertex2f(100-50, 125);
    glEnd();


    glBegin(GL_POLYGON); //window
    glColor3ub(0, 0, 0);//black-window-in-day
    //glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    //glColor3ub(128,128,0);

    if(!day)
    glColor3ub(163, 228, 215);//gray-window-in-night
    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(90, 127);
    glVertex2f(80, 127);
    glEnd();





    glBegin(GL_POLYGON); //window-Divider
    glColor3ub(192, 192, 192);
    glVertex2f(170, 152);
    glVertex2f(165, 152);
    glVertex2f(165, 127);
    glVertex2f(170, 127);
    glEnd();


    glBegin(GL_POLYGON); //roof-plate
   // glColor3ub(168, 169, 173);
    glColor3f(1.0f, 0.5f, 0.0f);//Orange

    glVertex2f(86, 152);
    glVertex2f(190, 152);
    glVertex2f(185, 157);
    glVertex2f(86, 157);
    glEnd();


    glBegin(GL_POLYGON); //window-holder-front
    glColor3ub(168, 169, 173);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(185, 152);
    glEnd();

//    glBegin(GL_POLYGON); //window-holder-back
//    glColor3ub(168, 169, 173);
//    glVertex2f(140+20-10, 157);
//    glVertex2f(115+20, 127);
//    glVertex2f(125+20, 127);
//    glVertex2f(140+20-10, 152);
//    glEnd();



    glBegin(GL_POLYGON); //foot-holder
    glColor3ub(168, 169, 173);
    //glColor3f(0.0f, 0.5f, 1.0f);//baby Blue

    glVertex2f(242, 92);
    glVertex2f(52, 92);
    glVertex2f(52, 97);
    glVertex2f(242, 97);
    glEnd();


//    glBegin(GL_POLYGON);      //mirror
//    glColor3f(0, 0, 0.1373);
//    glVertex2f(211.5, 134.5);
//    glVertex2f(204.5, 135.5);
//    glVertex2f(203.5, 129);
//    glVertex2f(210.5, 127);
//    glEnd();

    glBegin(GL_POLYGON);      //redYellow-headlight
    //glColor3f(1.0, 1.0, 0.0); //body
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(210.5+28, 134.5-10);
    glVertex2f(203.5+28, 135.5-10);
    glVertex2f(203.5+28, 129-10);
    glVertex2f(210.5+28, 127-10);
    glEnd();

    if(!day)
    {
        glBegin(GL_POLYGON);      //red-headlight
        //glColor3f(1.0, 1.0, 1.0); //body
        glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
        glVertex2f(210.5+28+90, 134.5-10-0);
        glVertex2f(205.5+28, 134.5-10);
        glColor3f(0.8, 0.9, 0.0);
        glVertex2f(205.5+28, 127-10);
        glVertex2f(210.5+28+90, 127-10-30);
        glEnd();

    }

    glBegin(GL_POLYGON); //window-opener-1
    glColor3ub(192, 192, 192);
    glVertex2f(150-15-5+20, 127-5-3);
    glVertex2f(155-5-5+20, 127-5-3);
    glVertex2f(155-5-5+20, 129-5);
    glVertex2f(150-15-5+20, 129-5);
    glEnd();
    glBegin(GL_POLYGON); //window-opener-2
    glColor3ub(192, 192, 192);
    glVertex2f(150-15+40, 127-5-3);
    glVertex2f(155-5+40, 127-5-3);
    glVertex2f(155-5+40, 129-5);
    glVertex2f(150-15+40, 129-5);
    glEnd();

    glBegin(GL_POLYGON); //window-opener-3
    glColor3ub(192, 192, 192);
    glVertex2f(150-15+60, 127-5-3);
    glVertex2f(155-5+60, 127-5-3);
    glVertex2f(155-5+60, 129-5);
    glVertex2f(150-15+60, 129-5);
    glEnd();

    glBegin(GL_POLYGON); //window-opener-4
    glColor3ub(192, 192, 192);
    glVertex2f(150-15+80, 127-5-3);
    glVertex2f(155-5+80, 127-5-3);
    glVertex2f(155-5+80, 129-5);
    glVertex2f(150-15+80, 129-5);
    glEnd();

     glBegin(GL_POLYGON); //window-opener-5
    glColor3ub(192, 192, 192);
    glVertex2f(150-15+0, 127-5-3);
    glVertex2f(155-5+0, 127-5-3);
    glVertex2f(155-5+0, 129-5);
    glVertex2f(150-15+0, 129-5);
    glEnd();

     glBegin(GL_POLYGON); //window-opener-5
    glColor3ub(192, 192, 192);
    glVertex2f(150-5, 127-5-3);
    glVertex2f(70, 127-5-3);
    glVertex2f(70, 129-5);
    glVertex2f(150-5, 129-5);
    glEnd();


}

void TankThrust()
{
    if(day)
    {
        glBegin(GL_POLYGON);
        glColor3ub(168, 169, 173);
        glVertex2f(110-50, 92);
        glColor3ub(255, 255, 255);
        glVertex2f(00-50, 80);
        glVertex2f(00-50, 110);
        glColor3ub(0, 0, 0);
        glVertex2f(110-50, 97);
        glEnd();
    }


}

void fullTank()
{

    TankBody();
    glPushMatrix();
    glTranslatef(79,0,0);
    TankScaledTire();

    glTranslatef(-44,0,0);
    TankScaledTire();

    glTranslatef(-47,0,0);
    TankScaledTire();

     glTranslatef(-45,0,0);
    TankScaledTire();

    glPopMatrix();

}

void TankReverse()
{
    glLineWidth(1);

    glTranslatef(-100.5, 0, 0);

    fullTank();


}

void ScaledTankReverse()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(800,80,0);
    glScalef(-0.7,0.7,0);
    TankReverse();
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glTranslatef(527,127,0);
    glScalef(0.8,0.4,0);
    tankrocket();
    glPopMatrix();

     glPushMatrix();
    //glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glTranslatef(527,115,0);
    glScalef(0.8,0.4,0);
    tankrocket();
    glPopMatrix();

    glPushMatrix();
    //glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glTranslatef(620,77,0);
    glScalef(0.6,0.7,0);
    tankrocket();
    glPopMatrix();



}


/////////////////////////////////////////////////
////////////////-----------////////////


///Main
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0,0.0,1.0);

	sky();

	star();
	sun();
    moon();
    cloud1();
    cloud2();
    cloud3();
    cloud4();
    cloud5();
    airPlane();
    tilla1();
    tilla2();
    tilla3();
    tilla4();
    field();
    tree1();
    tree2();
    tree3();
    tree4();
    tree5();
    tree6();
    tree7();
    tree8();
    tree9();
    tree10();
    tree11();
    tree12();
    tree13();
    tree14();
    tree15();
    tree16();
    tree17();
    tree18();
    tree19();
    tree20();
    ScaledTruckReverse();
    ScaledTruck2Reverse();
    ScaledTruck3Reverse();
    ScaledTruck4Reverse();

    ScaledTankReverse();
	glFlush();
}
void init(void){
	glClearColor(0.65, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void update(int value){

    ///Cloud Control
    if(cpos1>750)cpos1=-320;
    if(cpos2<-350)cpos2=650;
    if(cpos3>750)cpos3=-320;
    if(cpos4>750)cpos4=-320;
    if(cpos5<-350)cpos5=650;
    cpos1+=sp1;
    cpos2-=sp1;
    cpos3+=sp1;
    cpos4+=sp1;
    cpos5-=sp1;
    ///Sun Control
    if(sun_y>480){
        sun_x=650;
        sun_y=290;
        day=0;
    }
    sun_x-=sp_x;
    sun_y+=sp_y;
    ///AirPlane Control
    if(plane_x>1000){
        plane_x=-100;
    }
    plane_x+=plane_speed;

    glutTimerFunc(100, update, 0);
    glutPostRedisplay();

    ///Bullet Control
    bul -= 20;
	if (bul <-410)
    {
        bul = 0;
    }

}

void Rain(int value){

if(rainday){

    _rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}



void handleKeypress(unsigned char key, int x, int y){
	switch (key){
        case 'd':
            day=1;
            break;
        case 'n':
            day=0;
            break;
            case 'r':
        rainday = true;
        Rain(_rain);
        //sndPlaySound("River.wav",SND_ASYNC|SND_LOOP);
        //sndPlaySound("River.wav",SND_MEMORY|SND_ASYNC);
        break;

    case 's':
        rainday = false;
		//sndPlaySound(NULL,SND_ASYNC);
        break;

        case 'f':
        fire = true;
		//sndPlaySound(NULL,SND_ASYNC);
        break;

        case 'o':
        fire = false;
		//sndPlaySound(NULL,SND_ASYNC);
        break;

        glutPostRedisplay();
	}
}
void credit(){

    cout<<"------------------------------------------------------"<<endl;
    cout<<"Press d for Day "<<endl;
    cout<<"Press n for Night "<<endl;
    cout<<"Press r for Rain "<<endl;
    cout<<"Press s for Stop Rain "<<endl;
    cout<<"Press f for Fire "<<endl;
    cout<<"Press o for Stop Fire "<<endl;

    cout<<"------------------------------------------------------"<<endl;

}
int main(int argc, char** argv){
    credit();
    ///Music Background
    //PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
    ///system("pause");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("CG Project- War Zone");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);

    glutTimerFunc(1000, update, 0);
    glutMainLoop();
}

