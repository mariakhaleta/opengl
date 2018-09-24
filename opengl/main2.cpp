//
//  main2.cpp
//  opengl
//
//  Created by Maria Khaleta on 20.09.2018.
//  Copyright © 2018 Maria Khaleta. All rights reserved.
//
#include <stdlib.h>

/* подключаем библиотеку GLUT */
#include <GLUT/GLUT.h>

/* начальная ширина и высота окна */
GLint Width = 1000, Height = 700;

/* размер куба */
const int CubeSize = 100;

/* эта функция управляет всем выводом на экран */
void Display(void)
{
    //int left, right, top, bottom;
    
    //left = (Width - CubeSize) / 3;  // (512 - 200) /2 = 156
    //right = left + CubeSize;   // 156 + 200 = 356
    //bottom = (Height - CubeSize) / 1,7; // 512 - 200 = 312
    //top = bottom + CubeSize;  // 312 + 200 = 512
    
    glClearColor(148, 0, 211, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3ub(255, 233, 31);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(200, 500);
    glVertex2f(300, 500);
    glVertex2f(300, 600);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(300, 500);
    glVertex2f(300, 300);
    glVertex2f(500, 300);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(300, 350);
    glVertex2f(250, 300);
    glVertex2f(300, 250);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(450, 300);
    glVertex2f(550, 300);
    glVertex2f(550, 200);
    
    
    glBegin(GL_TRIANGLES);
    glVertex2f(400, 150);
    glVertex2f(500, 250);
    glVertex2f(600, 150);
    
    
    
    
    glEnd();
    glColor3ub(255,0, 0);
    
    glBegin(GL_QUAD_STRIP);
    glVertex2f(450, 300);
    glVertex2f(500, 250);
    glVertex2f(400, 250);
    glVertex2f(450, 200);
    
    glBegin(GL_QUAD_STRIP);
    
    glVertex2f(600, 150);
    
    
    glEnd();
    
    glFinish();
}

/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
    Width = w;
    Height = h;
    
    /* устанавливаем размеры области отображения */
    glViewport(0, 0, w, h);
    
    /* ортографическая проекция */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* Функция обрабатывает сообщения от клавиатуры */
void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'
    
    if (key == ESCAPE)
        exit(0);
    
    
    
}

/* Главный цикл приложения */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Red square example");
    
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    
    glutMainLoop();
}
