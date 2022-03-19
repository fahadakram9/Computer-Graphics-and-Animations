#include <Windows.h>
#include<glew.h>
#include <gl/GL.h>
#include<gl/GLU.h>
#include<glut.h>
#include <iostream>
#include<math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void display();
void reshape(int, int);
static int window;
static int clockwisesub;
static int rotateoptionsub;
static int speedoptionsub;
static int justslowsub;
static int fastsub;
static int crazyfastsub;

void ferriswheelHandle();
void ferriswheelCircle(int , int);
void ferris();


float  counter = 3.0;
float frameNumber = 0;
float xposition = 0;
float yposition = 3;


float rotaions[1] = {3};
//float speeds[4] = { frameNumber*3, 0, 0,1 };

int state = 1;

void init() {

    glClearColor(255, 255, 255, 1.0);


}

int main(int argc, char** args) {


    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(800, 800);

    window = glutCreateWindow("Ferris wheel");

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    init();

    glutMainLoop();

}


void rotation(int num) {

    switch (num) {
    case 1:
        rotaions[0] = { -3 };
        
        break;

    case 2:
        rotaions[0] = { 3 };

        break;
    
    }
}


void speed(int num) {

    switch (num) {
    case 1:

        rotaions[0] = { 2};
        break;

    case 2:
        rotaions[0] = { 4 };
        break;
    case 3:
        rotaions[0] = { 6 };
        break;
    case 4:
        rotaions[0] = { 9 };
        break;
    
    }
}


void menu(int num) {

    switch (num)
    {
    case 1:
        glutDestroyWindow(window);
        exit(0);
        break;
 

    }
}


void createMenu(void) {

    
   rotateoptionsub = glutCreateMenu(rotation);
    glutAddMenuEntry("Clockwise", 1);
    glutAddMenuEntry("Counter clockwise", 2);
   

   speedoptionsub = glutCreateMenu(speed);
    glutAddMenuEntry("painfully slow", 1);
    glutAddMenuEntry("just slow", 2);
    glutAddMenuEntry("fast ", 3);
    glutAddMenuEntry("crazy fast", 4);
   

    glutCreateMenu(menu);
    glutAddSubMenu("Rotate option:", rotateoptionsub);
    glutAddSubMenu("Speed Option", speedoptionsub);
    
    glutAddMenuEntry("Quit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    //glutMainLoop();
}


void ferriswheelHandle()
{

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-2.5, -1.3);
    glVertex2f(-1, -2);
    glVertex2f(-1.5, -5);
    glVertex2f(-4, -5);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(2.5, -1.3);
    glVertex2f(1, -2);
    glVertex2f(1.5, -5);
    glVertex2f(4, -5);
    glEnd();


}







void ferriswheelCircle(int x, int y)
{

    glPushMatrix();
   
    glTranslatef(x, y, 0.0);
    glRotatef(frameNumber * rotaions[0], 0, 0, 1);
    glTranslatef(-x, -y, 0.0);
   
    // outer line of frris wheel
    float th;
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.141 / 180);
        glVertex2f(x+5 * cos(th), y+5 * sin(th));
    }


    glEnd();



   // inner line of ferris wheel
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.141 / 180);
        glVertex2f(x + 4 * cos(th), y + 4 * sin(th));
    }


    glEnd();




    // outer hole of ferris wheel
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.141 / 180);
        glVertex2f(x + 0.5 * cos(th), y + 0.5 * sin(th));
    }


    glEnd();



    // inner hole of ferris wheel
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.141 / 180);
        glVertex2f(x + 1 * cos(th), y + 1 * sin(th));
    }


    glEnd();

   // #############################################################
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1, 3);
    glVertex2f(4, 2.5);
    glVertex2f(1, 3);
    glVertex2f(4,3.5);
    glEnd();

   
    glBegin(GL_LINE_LOOP);
    glLineWidth(1);
    glVertex2f(0.7, 2.3);
    glVertex2f(2.7, 0);
    glEnd();


    
    glBegin(GL_LINE_LOOP);
    glLineWidth(3);
    glVertex2f(-1, 3);
    glVertex2f(-4, 2.5);
    glVertex2f(-1, 3);
    glVertex2f(-4, 3.5);
    glEnd();
    

    
    glBegin(GL_LINE_LOOP);
    glLineWidth(1);
    glVertex2f(0.6, 3.8);
    glVertex2f(3, 5.6);
    glEnd();

    
    glBegin(GL_LINE_LOOP);
    glLineWidth(3);
    glVertex2f(0, 4);
    glVertex2f(-0.5, 7 );
    glVertex2f(0, 4);
    glVertex2f(0.5, 7);
    glEnd();

   
    glBegin(GL_LINE_LOOP);
    glLineWidth(1);
    glVertex2f(-0.6, 3.8);
    glVertex2f(-3, 5.6);
    glEnd();


   
    glBegin(GL_LINE_LOOP);
    glLineWidth(3);
    glVertex2f(0, 2);
    glVertex2f(-0.5, -1);
    glVertex2f(0, 2);
    glVertex2f(0.5, -1);
    glEnd();

    
    glBegin(GL_LINE_LOOP);
    glLineWidth(1);
    glVertex2f(-0.7, 2.3);
    glVertex2f(-2.7, 0);
    glEnd();

    glPopMatrix();
}




void ferris() {

    glPushMatrix();
    glTranslatef(0, 3, 0.0);
    glRotatef(frameNumber *rotaions[0], 0, 0,1);
    glTranslatef(0, -3, 0.0);
   
    
    
    // yellow ferris /////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(255, 255, 0);
    glVertex2f(-1.3 , 8.5);
    glVertex2f(0,9.5);
    glVertex2f(1.3, 8.5);
    glEnd();

  
    glBegin(GL_POLYGON);
    glColor3f(255, 255, 0);
    glVertex2f(-1.3, 8.5);
    glVertex2f(1.3, 8.5);
    glVertex2f(1.3, 6.5);
    glVertex2f(-1.3, 6.5);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(255, 255, 255);
    glVertex2f(-1, 8.2);
    glVertex2f(1, 8.2);
    glVertex2f(1, 7.5);
    glVertex2f(-1, 7.5);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0, 3, 0.0);
    glRotatef(frameNumber * rotaions[0], 0, 0, 1);
    glTranslatef(0, -3, 0.0);
    // green ferris /////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0, 255, 0);
    glVertex2f(-1.3, -1);
    glVertex2f(0, 0);
    glVertex2f(1.3, -1);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0, 255, 0);
    glVertex2f(-1.3, -1);
    glVertex2f(1.3, -1);
    glVertex2f(1.3, -3);
    glVertex2f(-1.3, -3);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(255, 255, 255);
    glVertex2f(-1, -1.3);
    glVertex2f(1, -1.3);
    glVertex2f(1, -2);
    glVertex2f(-1, -2);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 3, 0.0);
    glRotatef(frameNumber * rotaions[0], 0, 0, 1);
    glTranslatef(0, -3, 0.0);
    // red ferris /////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(255, 0, 0);
    glVertex2f(-6, 4);
    glVertex2f(-4.7, 5);
    glVertex2f(-3.5, 4);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(255, 0, 0);
    glVertex2f(-6, 4);
    glVertex2f(-3.5, 4);
    glVertex2f(-3.5, 2);
    glVertex2f(-6, 2);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(255, 255, 255);
    glVertex2f(-5.7, 3.8);
    glVertex2f(-3.8, 3.8);
    glVertex2f(-3.8, 3);
    glVertex2f(-5.7, 3);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0, 3, 0.0);
    glRotatef(frameNumber* rotaions[0], 0, 0, 1);
    glTranslatef(0, -3, 0.0);
    // Blue ferris /////////////////////////////
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 255);
    glVertex2f(6, 4);
    glVertex2f(4.7, 5);
    glVertex2f(3.5, 4);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0, 0, 255);
    glVertex2f(6, 4);
    glVertex2f(3.5, 4);
    glVertex2f(3.5, 2);
    glVertex2f(6, 2);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(255, 255, 255);
    glVertex2f(5.7, 3.8);
    glVertex2f(3.8, 3.8);
    glVertex2f(3.8, 3);
    glVertex2f(5.7, 3);
    glEnd();

    glPopMatrix();
   
    glutSwapBuffers();

}






void display() {
    frameNumber++;
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    ferriswheelHandle();
    ferriswheelCircle(0, 3);
    ferris();
    
    glFlush();


}


void doFrame(int v) {
    //frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(200, doFrame, 0);


   /* switch (state)
    {
    case 1:
        if (xposition == 0 && yposition == 3) {
            xposition += 0.15;
            yposition += 0.15;
        }
        else 
            state = -1;
        break;

   }*/

}



void reshape(int w, int h) {

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
     glutTimerFunc(400, doFrame, 0);
     createMenu();
}
