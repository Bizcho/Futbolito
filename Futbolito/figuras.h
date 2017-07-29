#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int pex0,pey0,pex1,pey1,pex2,pey2,pex3,pey3,pex4,pey4;

void dibujaCirculo(float radio, float x, float y){
	glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(double i=0;i<10;i+=.01){
		glVertex2f((radio*cos(i)+x),(radio*sin(i)+y));
    }
    glEnd();
}

void DrawCircle(float cx, float cy, float r)
{
	glBegin(GL_LINE_LOOP);
	for(int ii = 0; ii < 100; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(100);

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);

	}
	glEnd();
}

void dibujaPunto(int x, int y){
    glBegin (GL_POINTS);
	glVertex2i (x, y);
	glEnd();
}

void dibujaLinea(int x0,int y0, int x1,int y1){
    glBegin (GL_LINES);
    glVertex2i (x0, y0);
    glVertex2i (x1, y1);
	glEnd();
}
void dibujaTriangulo(int x0, int y0, int x1, int y1, int x2, int y2){
	glBegin (GL_TRIANGLES);
    glVertex2i (x0, y0);
    glVertex2i (x1, y1);
    glVertex2i (x2, y2);
	glEnd();
}

void dibujaRectangulo(int x, int y, int base, int altura){
    glBegin (GL_LINE_LOOP);

    glVertex2i(x, y);
    glVertex2i(x+base, y);
    glVertex2i(x+base, y+altura);
    glVertex2i(x, y+altura);

    glEnd();
}
void poligono(int x, int y, int base, int altura){
    glBegin (GL_POLYGON);

    glVertex2i(x, y);
    glVertex2i(x+base, y);
    glVertex2i(x+base, y+altura);
    glVertex2i(x, y+altura);

    glEnd();
}
void dibujaCuadrado(int x, int y, int lado){
    glBegin (GL_POLYGON);

    glVertex2i(x, y);
    glVertex2i(x+lado, y);
    glVertex2i(x+lado, y+lado);
    glVertex2i(x, y+lado);

    glEnd();
}
void pentagono(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	pex0=x0;
	pey0=y0;
	pex1=x1;
	pey1=y1;
	pex2=x2;
	pey2=y2;
	pex3=x3;
	pey3=y3;
	pex4=x4;
	pey4=y4;
}
void dibujarPentagono(){
	glBegin (GL_POLYGON);
    glVertex2i (pex0, pey0);
    glVertex2i (pex1, pey1);
    glVertex2i (pex2, pey2);
    glVertex2i (pex3, pey3);
    glVertex2i (pex4, pey4);
	glEnd();
}
