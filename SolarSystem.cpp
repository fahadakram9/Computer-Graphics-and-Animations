#include <Windows.h>
#include<glew.h>
#include <gl/GL.h>
#include<gl/GLU.h>
#include<glut.h>
#include <iostream>
#include<math.h>
#include <string.h>
#include <stdlib.h>


static int window;


float  counter = 3.0;
float frameNumber = 0;



void display();
void reshape(int, int);

void earth(int, int);


void sun(int, int);







void init() {

    glClearColor(0.6, 0.6, 0.6, 1.0);


}


int main(int argc, char** args) {


    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    window = glutCreateWindow("Solar System");
    //createMenu();
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    init();


    glutMainLoop();

}




void sun(int x, int y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glRotatef(frameNumber, 0, 0, 1);

    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.5, 0.0);
    for (int i = 0; i <= 360; i++)
    {
        th = i * (3.141 / 180);
        glVertex2f(x + 1.2 * cos(th), y + 1.2 * sin(th));
    }

    glEnd();

    glPopMatrix();

}



void earth(int x, int y)
{
    glPushMatrix();
    glTranslatef(0, 0, 0.0);
    glRotatef(frameNumber * 3, 0, 0, 1);
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0, 0.8);
    for (int i = 0; i <= 360; i++)
    {
        th = i * (3.141 / 180);
        glVertex2f(x + 0.5 * cos(th), y + 0.5 * sin(th));
    }


    glEnd();

    glTranslatef(-1, 4, 0);
    glRotatef(-frameNumber * 8, 0, 0, 1);
    glTranslatef(3, -4, 0);



    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    for (int i = 0; i <= 360; i++)
    {
        th = i * (3.141 / 180);
        glVertex2f(-4 + 0.2 * cos(th), 4 + 0.2 * sin(th));
    }

    glEnd();
    glPopMatrix();

}

void display() {
    frameNumber++;
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    sun(0, 0);
    earth(-1, 4);
    glFlush();
}



void doFrame(int v) {
    //frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(200, doFrame, 0);
}



void reshape(int w, int h) {

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    glutTimerFunc(400, doFrame, 0);

}

