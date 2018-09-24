//
//  main.cpp
//  opengl
//
//  Created by Maria Khaleta on 18.09.2018.
//  Copyright © 2018 Maria Khaleta. All rights reserved.
//
#include <stdlib.h>

/* подключаем библиотеку GLUT */
#include <glut/glut.h>

/* начальная ширина и высота окна */
GLint Width = 1000, Height = 700;

int bx = 0,by=0,bz=0;
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
    
    glClearColor(0, 255,  8 , 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3ub(94, 84, 00);
    glTranslatef(bx, by,bz);
    
    //1
    glBegin(GL_TRIANGLES);
    glVertex2f(bx+200, 500+by);
    glVertex2f(bx+300, 500+by);
    glVertex2f(bx+300, 600+by);
    glEnd();
    
    //2
    glBegin(GL_TRIANGLES);
    glVertex2f(bx+300, 570+by);
    glVertex2f(bx+300, 500+by);
    glVertex2f(bx+400, 500+by);
    glEnd();
    
    //3
    glBegin(GL_TRIANGLES);
    glVertex2f(bx+300, 570+by);
    glVertex2f(bx+400, 500+by);
    glVertex2f(bx+500, 570+by);
    glEnd();
    
    //4
    glBegin(GL_TRIANGLES);
    glVertex2f(bx+400, 500+by);
    glVertex2f(bx+455, 540+by);
    glVertex2f(bx+500, 500+by);
    glEnd();
    
    //5
    glBegin(GL_TRIANGLES);
    glVertex2f(bx+300, 500+by);
    glVertex2f(bx+350, 500+by);
    glVertex2f(bx+300, 450+by);
    glEnd();

    //1
    glBegin(GL_QUAD_STRIP);
    glVertex2f(bx+500, 570+by);
    glVertex2f(bx+540, 540+by);
    glVertex2f(bx+455, 540+by);
    glVertex2f(bx+500, 500+by);
    glEnd();
    
    //2
    glBegin(GL_QUAD_STRIP);
    glVertex2f(bx+540, 470+by);
    glVertex2f(bx+540, 540+by);
    glVertex2f(bx+500, 440+by);
    glVertex2f(bx+500, 500+by);
    
    glBegin(GL_QUAD_STRIP);
    
    glVertex2f(600, 150);
    glEnd();
    
    //1
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2f(bx+200, 500+by);
    glVertex2f(bx+300, 500+by);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(bx+200, 500+by);
    glVertex2f(bx+300, 600+by);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(bx+300, 500+by);
    glVertex2f(bx+300, 600+by);
    glEnd();

    //2
    glBegin(GL_LINES);
    glVertex2f(bx+300, 570+by);
    glVertex2f(bx+300, 500+by);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(bx+300, 500+by);
    glVertex2f(bx+400, 500+by);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(bx+300, 570+by);
    glVertex2f(bx+400, 500+by);
    glEnd();
    
    //3
    glBegin(GL_LINES);
    glVertex2f(bx+300, 570+by);
    glVertex2f(bx+400, 500+by);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(bx+400, 500+by);
    glVertex2f(bx+500, 570+by);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(bx+300, 570+by);
    glVertex2f(bx+400, 500+by);
    glEnd();
    
    //4
    glBegin(GL_LINES);
    glVertex2f(bx+455, 540+by);
    glVertex2f(bx+500, 500+by);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(bx+400, 500+by);
    glVertex2f(bx+500, 500+by);
    glEnd();
    
    //5
    glBegin(GL_LINES);
    glVertex2f(bx+300, 500+by);
    glVertex2f(bx+350, 500+by);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(bx+350, 500+by);
    glVertex2f(bx+300, 450+by);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(bx+300, 500+by);
    glVertex2f(bx+300, 450+by);
    glEnd();
    
    //1 квадратик
    
    glBegin(GL_LINES);
    glVertex2f(bx+500, 570+by);
    glVertex2f(bx+540, 540+by);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(bx+540, 540+by);
    glVertex2f(bx+500, 500+by);
    glEnd();
    
    //2 ромбик
    
    glBegin(GL_LINES);
    glVertex2f(bx+540, 540+by);
    glVertex2f(bx+540, 470+by);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(bx+540, 470+by);
    glVertex2f(bx+500, 440+by);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(bx+500, 500+by);
    glVertex2f(bx+500, 440+by);
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

void PressKey(int key, int x, int y)
{
    bx = 0;
    switch(key)
    {
        case GLUT_KEY_RIGHT:
            bx = bx + 10;
            break;
        case GLUT_KEY_LEFT:
            bx = bx - 10;
            break;
        case GLUT_KEY_UP:
            by = by + 10;
            break;
        case GLUT_KEY_DOWN:
           by = by - 10;
        default:
            break;

    }
    glutPostRedisplay();
}

/* Главный цикл приложения */
/*int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("какая-то хрень");
    
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(PressKey);
    glutMainLoop();
}*/
