//
//  version2.cpp
//  opengl
//
//  Created by Maria Khaleta on 23.09.2018.
//  Copyright © 2018 Maria Khaleta. All rights reserved.
//
#include<iostream>
#include<stdlib.h>
/* подключаем библиотеку GLUT */
#include<GLUT/GLUT.h>

float translate_x = 0.0f;
float translate_y = 0.0f;
float translate_z = 0.0f;

void renderTriangle(double first[], double second[], double third[]) {
    glColor3ub(94, 84, 00);
    glBegin(GL_POLYGON);
    glVertex2f(first[0], first[1]);
    glVertex2f(second[0], second[1]);
    glVertex2f(third[0], third[1]);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(first[0], first[1]);
    glVertex2f(second[0], second[1]);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(second[0], second[1]);
    glVertex2f(third[0], third[1]);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(first[0], first[1]);
    glVertex2f(third[0], third[1]);
    glEnd();
}
void renderKvadratik(double first[], double second[], double third[], double fourth[]) {
    glColor3ub(94, 84, 00);
    glBegin(GL_POLYGON);
    glVertex2f(first[0], first[1]);
    glVertex2f(second[0], second[1]);
    glVertex2f(third[0], third[1]);
    glVertex2f(fourth[0], fourth[1]);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(first[0], first[1]);
    glVertex2f(second[0], second[1]);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(second[0], second[1]);
    glVertex2f(third[0], third[1]);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(third[0], third[1]);
    glVertex2f(fourth[0], fourth[1]);
    glBegin(GL_LINES);
    glVertex2f(fourth[0], fourth[1]);
    glVertex2f(first[0], first[1]);
    glEnd();
}
void displayPicture(void) {
    
    glOrtho(-1.0, 2.0, -2.0, 1.0, -1.0, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(translate_x, translate_y, translate_z);
    glColor3f(0, 1, 0);
    double points1[3][2] = { { 0.0, 0.0 }, { 0.0, 0.6 }, { -0.6, 0.0 } };
    renderTriangle(points1[0], points1[1], points1[2]);
    double points2[3][2] = { { 0.0, 0.0 }, { 0.0, 0.4 }, { 0.4, 0.0 } };
    renderTriangle(points2[0], points2[1], points2[2]);
    double points3[3][2] = { { 0.0, 0.4 }, { 0.4, 0.0 }, { 0.8, 0.4 }};
    renderTriangle(points3[0], points3[1], points3[2]);
    double points4[3][2] = { { 0.6, 0.2 }, { 0.4, 0.0 }, { 0.8, 0.0}};
    renderTriangle(points4[0], points4[1], points4[2]);
    double points5[3][2] = { { 0.0, -0.3 }, { 0.0, 0.0 }, { 0.3, 0.0}};
    renderTriangle(points5[0], points5[1], points5[2]);
    double points6[4][2] = { { 0.6, 0.2 },{ 0.8, 0.4}, {1.0, 0.2}, { 0.8, 0.0 }};
    renderKvadratik(points6[0], points6[1], points6[2], points6[3]);
    double points7[4][2] = { { 0.8, 0.0 }, {1.0, 0.2},{ 1.0, -0.2}, { 0.8, -0.4 }};
    renderKvadratik(points7[0], points7[1], points7[2], points7[3]);

}

/* Функция обрабатывает сообщения от клавиатуры */
void keyPress(int key, int x, int y)
{
#define ESCAPE '\033'
    
    if (key == ESCAPE)
        exit(0);

    else{
    switch (key) {
        case GLUT_KEY_LEFT:
            translate_x -= 1.0f;
            break;
        case GLUT_KEY_RIGHT:
            translate_x += 1.0f;
            break;
        case GLUT_KEY_UP:
            translate_y += 1.0f;
            break;
        case GLUT_KEY_DOWN:
            translate_y -= 1.0f;
        default:
            break;
    }
    glutPostRedisplay();
    }
}

//Called when the window is resized
void handleResize(int w, int h) {
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
}

void drawScene()
{
    glClearColor(102, 0, 102, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    displayPicture();
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 0);
    glutCreateWindow("bebebe");
    glutDisplayFunc(drawScene);
    glutSpecialFunc(keyPress);
    glutReshapeFunc(handleResize);
    glutMainLoop();
    
    return 0;
}

