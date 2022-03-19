#include <Windows.h>
#include<glew.h>
#include <gl/GL.h>
#include<gl/GLU.h>
#include<glut.h>
#include<stdlib.h>
#include <iostream>
#include<math.h>
#include<fstream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
void display();
void reshape(int, int);
void road();
void tree();
void school();
void student();
float  counter = 3.0;
void init() {

    glClearColor(255, 255, 255, 1.0);


}

int main(int argc, char** args) {


    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 80);
    glutInitWindowSize(1100, 600);

    glutCreateWindow("School bus and some kids");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();

}

void drawtext(const char* text, int length, int x, int y)
{
    glMatrixMode(GL_PROJECTION);
    double* matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    for (int i = 0; i <= length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);

}


void road() {

  // road
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-10, -5);
    glVertex2f(10, -5);
    glVertex2f(10, -10);
    glVertex2f(-10, -10);
    glEnd();


    // ground of school
    glBegin(GL_POLYGON);
    glColor3f(1, 0.8, 0.4);
    glVertex2f(-10, 2);
    glVertex2f(10, 2);
    glVertex2f(10, -5);
    glVertex2f(-10, -5);
    glEnd();

    // sky
    glBegin(GL_POLYGON);
    glColor3f(0.7, 1, 1);
    glVertex2f(-10, 10);
    glVertex2f(10, 10);
    glVertex2f(10, 2);
    glVertex2f(-10, 2);
    glEnd();


    // zebra crossing
    int i = -10;
    while (i < 10) {
        int a = i;
        int b = i+2; 

        glBegin(GL_POLYGON);
        glColor3f(255, 255, 255);
        glVertex2f(a, -7);
        glVertex2f(b, -7);
        glVertex2f(b, -8);
        glVertex2f(a, -8);
        glEnd();

        i +=3;
    }
}

void school() {

    // building
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.1, 0);
    glVertex2f(-4, 7);
    glVertex2f(4, 7);
    glVertex2f(4, -1);
    glVertex2f(-4, -1);
    glEnd();

    //board
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-2, 9);
    glVertex2f(2, 9);
    glVertex2f(2, 7.5);
    glVertex2f(-2, 7.5);
    glEnd();

   string text = "  Be Prince Kids School";
    glColor3f(255, 255, 255);
    drawtext(text.data(), text.size(), -2,8 );

    //stick 1
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(-2, 7.5);
    glVertex2f(-1.9, 7.5);
    glVertex2f(-1.9, 7);
    glVertex2f(-2, 7);
    glEnd();

    //stick 1
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(1.9, 7.5);
    glVertex2f(2, 7.5);
    glVertex2f(2, 7);
    glVertex2f(1.9, 7);
    glEnd();


    //gate 
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0.7);
    glVertex2f(-0.5, 2);
    glVertex2f(0.5, 2);
    glVertex2f(0.5, -1);
    glVertex2f(-0.5, -1);
    glEnd();


    //left window 1
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 1);
    glVertex2f(-3.5, 6);
    glVertex2f(-2.5, 6);
    glVertex2f(-2.5, 5);
    glVertex2f(-3.5, 5);
    glEnd();

    //left window 2
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 1);
    glVertex2f(-3.5, 4.5);
    glVertex2f(-2.5, 4.5);
    glVertex2f(-2.5, 3.5);
    glVertex2f(-3.5, 3.5);
    glEnd();


    //left window 3
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 1);
    glVertex2f(-2, 6);
    glVertex2f(-1, 6);
    glVertex2f(-1, 5);
    glVertex2f(-2, 5);
    glEnd();

    //left window 4
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 1);
    glVertex2f(-2, 4.5);
    glVertex2f(-1, 4.5);
    glVertex2f(-1, 3.5);
    glVertex2f(-2, 3.5);
    glEnd();


    //right window 1
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 1);
    glVertex2f(1, 6);
    glVertex2f(2, 6);
    glVertex2f(2, 5);
    glVertex2f(1, 5);
    glEnd();

    //right window 2
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 1);
    glVertex2f(1, 4.5);
    glVertex2f(2, 4.5);
    glVertex2f(2, 3.5);
    glVertex2f(1, 3.5);
    glEnd();


    //right window 3
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 1);
    glVertex2f(2.5, 6);
    glVertex2f(3.5, 6);
    glVertex2f(3.5, 5);
    glVertex2f(2.5, 5);
    glEnd();

    //right window 4
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.8, 1);
    glVertex2f(2.5, 4.5);
    glVertex2f(3.5, 4.5);
    glVertex2f(3.5, 3.5);
    glVertex2f(2.5, 3.5);
    glEnd();

}



void tree() {

    //wood 1
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.1, 0.1);
    glVertex2f(-8.5, 3);
    glVertex2f(-8, 3);
    glVertex2f(-8, -1);
    glVertex2f(-8.5, -1);
    glEnd();


    //leaf 1.1
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(-9, 3.7);
    glVertex2f(-7.5, 3.7);
    glVertex2f(-7, 3);
    glVertex2f(-9.5, 3);
    glEnd();

    //leaf 1.2
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(-8.9, 4.4);
    glVertex2f(-7.7, 4.4);
    glVertex2f(-7, 3.7);
    glVertex2f(-9.5, 3.7);
    glEnd();

    //leaf 1.3
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(-9.5, 4.4);
    glVertex2f(-8.1, 6);
    glVertex2f(-7, 4.4);
   
    glEnd();



    //wood 2
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.1, 0.1);
    glVertex2f(-6, 3);
    glVertex2f(-5.5, 3);
    glVertex2f(-5.5, -1);
    glVertex2f(-6, -1);
    glEnd();

    //leaf 2.1
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(-6.5, 3.7);
    glVertex2f(-5, 3.7);
    glVertex2f(-4.5, 3);
    glVertex2f(-7, 3);
    glEnd();

    //leaf 2.2
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(-6.4, 4.4);
    glVertex2f(-5.2, 4.4);
    glVertex2f(-4.5, 3.7);
    glVertex2f(-7, 3.7);
    glEnd();

    //leaf 2.3
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2f(-7, 4.4);
    glVertex2f(-5.5, 6);
    glVertex2f(-4.5, 4.4);

    glEnd();



}


void student() {

    glLoadIdentity();
    counter = counter - 0.9;
    glTranslated(counter, -0.5, 0.0);

    float theta;
    glBegin(GL_POLYGON);
    glColor3f(1, 0.8, 0.1);
    for (int i = 0; i <= 360; i++) {
        
        theta =i*( 3.142 / 180);
        glVertex2f(0+0.3*cos(theta),0.5+0.3*sin(theta));

    }

    glEnd();

    //float theta;
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    for (int i = 0; i <= 360; i++) {

        theta = i * (3.142 / 180);
        glVertex2f(0 + 0.3 * cos(theta), 0.5 + 0.3 * sin(theta));

    }

    glEnd();


    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    glVertex2f(-0.1, 0.6);
    glEnd();

    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0);
    glVertex2f(0.1, 0.6);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(0, 0.5);
    glVertex2f(0, 0.4);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex2f(0,0.2);
    glVertex2f(0,-0.5);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(0, 0.1);
    glVertex2f(-0.3, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(0, 0.1);
    glVertex2f(0.3, -0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(0, -0.5);
    glVertex2f(-0.2, -0.9);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(0, -0.5);
    glVertex2f(0.2, -0.9);
    glEnd();

}


void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    road();
    school();
    tree();
    student();
    glFlush();


}

void reshape(int w, int h) {

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);

}
