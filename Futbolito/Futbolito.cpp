#include "stdafx.h"
#include "fisica.h"
#include <GL/glut.h>
#include "stdafx.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#  include <GL/glut.h>
//#include <figuras.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <Windows.h>

// Rojo:        glColor3f(1,0,0);
// verde:       glColor3f(0,1,0);
// azul:        glColor3f(0,0,1);
// blanco:      glColor3f(1,1,1);
// negro:       glColor3f(0,0,0);
// amarillo:    glColor3f(1,1,0);
// magenta:     glColor3f(1,0,1);
// cyan:        glColor3f(0,1,1);

using namespace std;

// metods //
void init();
void mostrar();
void dibujaPlano();
void mk_paredes_cancha();
void mk_paredes_equipo_1();
void mk_paredes_equipo_2();
void centra();

string lel = "0";

// variables globales //
int velocidad_jugador = 50;
Pelota plop = Pelota(8, 45);
Pared paredes_cancha[12];
Pared paredes_equipo_1[12];
Pared paredes_equipo_2[12];
int gol_equipo_1 = 1280;
int gol_equipo_2 = -1280;
int goles_equipo_1 = 0;
int goles_equipo_2 = 0;


  //equipo 1
int   equipo_1_height[4]    = { 0, 0, 0, 0 };
bool  equipo_1_isPresed[4]  = { false, false, false, false };

  //equipo 2
int equipo_2_height[4] = { 0, 0, 0, 0 };
bool  equipo_2_isPresed[4] = { false, false, false, false };


/// implementation ///

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1280, 1280, -720, 720);
	mk_paredes_cancha();
	mk_paredes_equipo_1();
	mk_paredes_equipo_2();
}

void dibujaPlano(){
    glColor3f(0,0,0);

    int px = 1280;
    int py = 720;
    int line = 4;

	
    // Eje X
    dibujaLinea(0,0,px,0);
    for(int x=0; x<px;x+=10){
        dibujaLinea(x,-line,x,line);
    }

    dibujaLinea(0,0,-px,0);
    for(int x=-px; x<=0;x+=10){
        dibujaLinea(x,-line,x,line);
    }

    //Eje Y
    dibujaLinea(0,0,0,py);
    for(int x=0; x<py;x+=10){
        dibujaLinea(-line,x,line,x);
    }

    dibujaLinea(0,0,0,-py);;
    for(int x=-py; x<=0;x+=10){
        dibujaLinea(-line,x,line,x);
    }
}

void SpecialInput(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
			centra();
        break;
        case GLUT_KEY_DOWN:
        //do something here
        break;
        case GLUT_KEY_LEFT:
        //do something here
        break;
        case GLUT_KEY_RIGHT:
        //do something here
        break;
    }

    glutPostRedisplay();
}

void cancha() {
	// Cancha
	glColor3f(1, 1, 1);
	dibujaRectangulo(-1260, -700, 2520, 1400);
	dibujaLinea(0, -700, 0, 700);
	DrawCircle(0, 0, 150);

	// Porteria Izquierda
	dibujaRectangulo(-1260, -350, 300, 700);
	dibujaRectangulo(-1260, -175, 100, 350);
	dibujaCirculo(10, -1050, 0);

	// Porteria Derecha
	dibujaRectangulo(960, -350, 300, 700);
	dibujaRectangulo(1160, -175, 100, 350);
	dibujaCirculo(10, 1050, 0);
}

void mk_paredes_cancha() {

	Pared pared;
	for each (Pared par in paredes_cancha)
	{
		par = pared;
	}

	//poner las paredes para que se vean como la foto que mande a messenger
	paredes_cancha[0].set(-1280, -720, 50, 1280 * 2);

	paredes_cancha[1].set(1280, -175, 545, 50);
	paredes_cancha[2].set(1280, -175, 50, 300);

	paredes_cancha[3].set(1530, 175, 350, 50);

	paredes_cancha[4].set(1280, 225, 50, 300);
	paredes_cancha[5].set(1280, 720, 545, 50);



	paredes_cancha[6].set(-1280, 770, 50, 1280 * 2);

	paredes_cancha[7].set(-1330, 720, 545, 50);
	paredes_cancha[8].set(-1630, 225, 50, 300);

	paredes_cancha[9].set(-1630, 175, 350, 50);

	paredes_cancha[10].set(-1630, -175, 50, 300);
	paredes_cancha[11].set(-1330, -175, 545, 50);

	paredes_cancha[0].prender();
	paredes_cancha[1].prender();
	paredes_cancha[2].prender();
	paredes_cancha[3].prender();
	paredes_cancha[4].prender();
	paredes_cancha[5].prender();
	paredes_cancha[6].prender();
	paredes_cancha[7].prender();
	paredes_cancha[8].prender();
	paredes_cancha[9].prender();
	paredes_cancha[10].prender();
	paredes_cancha[11].prender();
}

void mk_paredes_equipo_1() {
	Pared pared;
	for each (Pared par in paredes_equipo_1)
	{
		par = pared;
	}
}

void mk_paredes_equipo_2() {
	Pared pared;
	for each (Pared par in paredes_equipo_2)
	{
		par = pared;
	}
}

int check_gol() {
	if (plop.pos_x > gol_equipo_1)
		return 1;

	if (plop.pos_x < gol_equipo_2)
		return 2;

	return 0;
}

void centra() {
	plop.pos_x = 0;
	plop.pos_y = 0;
}

void bounce1(Pared& pared) {

	if (pared.activa) {
		if (plop.right_bound >= pared.left_bound &&  plop.pos_y > pared.down_bound
			&& plop.pos_y < pared.top_bound && plop.left_bound < pared.left_bound) {
			plop.vel_x *= -1;
		}
		if (plop.left_bound < pared.right_bound && plop.pos_y > pared.down_bound
			&& plop.pos_y < pared.top_bound && plop.right_bound > pared.right_bound) {
			plop.vel_x *= -1;
		}
		if (plop.top_bound >= pared.down_bound && plop.pos_x > pared.left_bound
			&& plop.pos_x < pared.right_bound && plop.down_bound < pared.down_bound) {
			plop.vel_y *= -1;
		}
		if (plop.down_bound <= pared.top_bound && plop.pos_x > pared.left_bound
			&& plop.pos_x < pared.right_bound && plop.top_bound > pared.top_bound) {
			plop.vel_y *= -1;
		}
	}
}

void bounce2(Pared paredes[12]) {
	for (int i = 0; i < 12; i++)
	{
		bounce1(paredes[i]);
	}
}

void check_walls() {
	bounce2(paredes_cancha);
}

void escribe(void *font, char *string)
{
	char *c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

void puntaje() {
	glColor3f(1, 1, 1);

	glRasterPos3f(-1230, 650.0, 0.0);
	escribe(GLUT_BITMAP_HELVETICA_18, "equipo 1: ");
	glRasterPos3f(1000.0, 650.0, 0.0);
	escribe(GLUT_BITMAP_HELVETICA_18, "Equipo 2: ");
}

void seleccion_color(int seleccion) {
	switch (seleccion) {
	case 1:
		glColor3f(1.0, 0.0, 0.0);
		break;
	case 2:
		glColor3f(0.0, 1.0, 0.0);
		break;
	case 3:
		glColor3f(1.0, 0.0, 1.0);
		break;
	case 4:
		glColor3f(0.7, 0.2, 0.8);
		break;
	}
}

void jugador_activado(float yx, float yy, int color, int altura, Pared& pared) {
	//cabeza
	glColor3f(1.0, 0.8, 0.6);
	dibujaCirculo(16.0, yx, yy + altura);
	//cuello
	poligono(yx - 7.5, yy + altura - 10, 15.0, -15.0);
	//cuerpo
	seleccion_color(color);
	poligono(yx - 12.5, yy + altura - 25.0, 25.0, -50.0);
	//piernas
	glColor3f(0.0, 0.0, 0.0);
	poligono(yx - 10.0, yy + altura - 75.0, 20.0, -20.0);

	//pared
	//dibujaRectangulo(yx - 12.5, yy + altura + 16, 25, -111);//hitbox
	pared.set(yx - 12.5, yy + altura + 16, 111, 25);
	pared.prender();
}

void jugador(float yx, float yy, int color, int altura, Pared& pared) {
	//cabeza
	glColor3f(1.0, 0.8, 0.6);
	dibujaCirculo(16.0, yx, yy + altura);
	//cuello
	poligono(yx - 10.0, yy + altura + 7.5, -15.0, -15.0);
	//cuerpo
	seleccion_color(color);
	poligono(yx - 25.0, yy + altura + 12.5, -50.0, -25.0);
	//piernas
	glColor3f(0.0, 0.0, 0.0);
	poligono(yx - 75.0, yy + altura + 10.0, -20.0, -20.0);

	//pared
	pared.apagar();

}

void jugador2(float yx, float yy, int color, int altura, Pared& pared) {
	//cabeza
	glColor3f(1.0, 0.8, 0.6);
	dibujaCirculo(16.0, yx, yy + altura);
	//cuello
	poligono(yx + 10.0, yy + altura + 7.5, 15.0, -15.0);
	//cuerpo
	seleccion_color(color);
	poligono(yx + 25.0, yy + altura + 12.5, 50.0, -25.0);
	//piernas
	glColor3f(0.0, 0.0, 0.0);
	poligono(yx + 75.0, yy + altura + 10.0, 20.0, -20.0);

	//pared
	pared.apagar();
}

void equipo1a(float yx, float yy, int alturas[]) {
	//portero
	if (!equipo_1_isPresed[0]) {
		jugador(yx + 35, yy, 4, alturas[0], paredes_equipo_1[0]);
	} else {
		jugador_activado(yx + 35, yy, 4, alturas[0], paredes_equipo_1[0]);
	}
	//defenza
	if(!equipo_1_isPresed[1]){
		jugador(yx + 250, yy + 50,  1, alturas[1], paredes_equipo_1[1]);
		jugador(yx + 250, yy - 110, 1, alturas[1], paredes_equipo_1[2]);
		jugador(yx + 250, yy + 270, 1, alturas[1], paredes_equipo_1[3]);
		jugador(yx + 250, yy - 330, 1, alturas[1], paredes_equipo_1[4]);
	} else {
		jugador_activado(yx + 250, yy + 50, 1, alturas[1], paredes_equipo_1[1]);
		jugador_activado(yx + 250, yy - 110, 1, alturas[1], paredes_equipo_1[2]);
		jugador_activado(yx + 250, yy + 270, 1, alturas[1], paredes_equipo_1[3]);
		jugador_activado(yx + 250, yy - 330, 1, alturas[1], paredes_equipo_1[4]);
	}
	//medios
	if(!equipo_1_isPresed[2]){
		jugador(yx + 1050, yy      , 1, alturas[2], paredes_equipo_1[5]);
		jugador(yx + 1050, yy - 230, 1, alturas[2], paredes_equipo_1[6]);
		jugador(yx + 1050, yy + 170, 1, alturas[2], paredes_equipo_1[7]);
	} else {
		jugador_activado(yx + 1050, yy, 1, alturas[2], paredes_equipo_1[5]);
		jugador_activado(yx + 1050, yy - 230, 1, alturas[2], paredes_equipo_1[6]);
		jugador_activado(yx + 1050, yy + 170, 1, alturas[2], paredes_equipo_1[7]);
	}
	//delanteros
	if(!equipo_1_isPresed[3]){
		jugador(yx + 1850, yy      , 1, alturas[3], paredes_equipo_1[8]);
		jugador(yx + 1850, yy - 230, 1, alturas[3], paredes_equipo_1[9]);
		jugador(yx + 1850, yy + 170, 1, alturas[3], paredes_equipo_1[10]);
	} else {
		jugador_activado(yx + 1850, yy, 1, alturas[3], paredes_equipo_1[8]);
		jugador_activado(yx + 1850, yy - 230, 1, alturas[3], paredes_equipo_1[9]);
		jugador_activado(yx + 1850, yy + 170, 1, alturas[3], paredes_equipo_1[10]);
	}
}

void equipo2a(float yx, float yy, int alturas[]) {
	//portero
	if (!equipo_2_isPresed[0]) {
		jugador2(yx - 35, yy, 3, alturas[0], paredes_equipo_2[0]);
	} else {
		jugador_activado(yx -35 , yy, 3, alturas[0], paredes_equipo_2[0]);
	}
	//defenza
	if (!equipo_2_isPresed[1]) {
		jugador2(yx - 250, yy + 50,  2, alturas[1], paredes_equipo_2[1]);
		jugador2(yx - 250, yy - 110, 2, alturas[1], paredes_equipo_2[2]);
		jugador2(yx - 250, yy + 270, 2, alturas[1], paredes_equipo_2[3]);
		jugador2(yx - 250, yy - 330, 2, alturas[1], paredes_equipo_2[4]);
	} else {
		jugador_activado(yx - 250, yy + 50, 2, alturas[1], paredes_equipo_2[1]);
		jugador_activado(yx - 250, yy - 110, 2, alturas[1], paredes_equipo_2[2]);
		jugador_activado(yx - 250, yy + 270, 2, alturas[1], paredes_equipo_2[3]);
		jugador_activado(yx - 250, yy - 330, 2, alturas[1], paredes_equipo_2[4]);
	}
	//medios
	if (!equipo_2_isPresed[2]) {
		jugador2(yx - 1050, yy,       2, alturas[2], paredes_equipo_2[5]);
		jugador2(yx - 1050, yy - 230, 2, alturas[2], paredes_equipo_2[6]);
		jugador2(yx - 1050, yy + 170, 2, alturas[2], paredes_equipo_2[7]);
	} else {
		jugador_activado(yx - 1050, yy, 2, alturas[2], paredes_equipo_2[5]);
		jugador_activado(yx - 1050, yy - 230, 2, alturas[2], paredes_equipo_2[6]);
		jugador_activado(yx - 1050, yy + 170, 2, alturas[2], paredes_equipo_2[7]);
	}

	//delanteros
	if (!equipo_2_isPresed[3]) {
		jugador2(yx - 1850, yy,       2, alturas[3], paredes_equipo_2[8]);
		jugador2(yx - 1850, yy - 230, 2, alturas[3], paredes_equipo_2[9]);
		jugador2(yx - 1850, yy + 170, 2, alturas[3], paredes_equipo_2[10]);
	} else {
		jugador_activado(yx - 1850, yy, 2, alturas[3], paredes_equipo_2[8]);
		jugador_activado(yx - 1850, yy - 230, 2, alturas[3], paredes_equipo_2[9]);
		jugador_activado(yx - 1850, yy + 170, 2, alturas[3], paredes_equipo_2[10]);
	}
}

void keyInput(unsigned char key, int x, int y){
	switch (key) {
		// patear equipo 1
	case 'a':
		equipo_1_isPresed[0] = !equipo_1_isPresed[0];
		break;
	case 's':
		equipo_1_isPresed[1] = !equipo_1_isPresed[1];
		break;
	case 'd':
		equipo_1_isPresed[2] = !equipo_1_isPresed[2];
		break;
	case 'f':
		equipo_1_isPresed[3] = !equipo_1_isPresed[3];
		break;
	//mover equipo 1
		//mover arriba
	case 'q':
		if (equipo_1_height[0] < 120) {
			equipo_1_height[0] += velocidad_jugador;
		}
		break;
	case 'w':
		if (equipo_1_height[1] < 350) {
			equipo_1_height[1] += velocidad_jugador;
		}
		break;
	case 'e':
		if (equipo_1_height[2] < 400) {
			equipo_1_height[2] += velocidad_jugador;
		}
		break;
	case 'r':
		if (equipo_1_height[3] < 400) {
			equipo_1_height[3] += velocidad_jugador;
		}
		break;
		//mover abajo
	case 'z':
		if (equipo_1_height[0] > -120) {
			equipo_1_height[0] -= velocidad_jugador;
		}
		break;
	case 'x':
		if (equipo_1_height[1] > -200) {
			equipo_1_height[1] -= velocidad_jugador;
		}
		break;
	case 'c':
		if (equipo_1_height[2] > -400) {
			equipo_1_height[2] -= velocidad_jugador;
		}
		break;
	case 'v':
		if (equipo_1_height[3] > -400) {
			equipo_1_height[3] -= velocidad_jugador;
		}
		break;
	// patear equipo 2
	case 'l':
		equipo_2_isPresed[0] = !equipo_2_isPresed[0];
		break;
	case 'k':
		equipo_2_isPresed[1] = !equipo_2_isPresed[1];
		break;
	case 'j':
		equipo_2_isPresed[2] = !equipo_2_isPresed[2];
		break;
	case 'h':
		equipo_2_isPresed[3] = !equipo_2_isPresed[3];
		break;
	//mover equipo 2
		//mover arriba
	case 'o':
		if (equipo_2_height[0] < 120) {
			equipo_2_height[0] += velocidad_jugador;
		}
		break;
	case 'i':
		if (equipo_2_height[1] < 350) {
			equipo_2_height[1] += velocidad_jugador;
		}
		break;
	case 'u':
		if (equipo_2_height[2] < 400) {
			equipo_2_height[2] += velocidad_jugador;
		}
		break;
	case 'y':
		if (equipo_2_height[3] < 400) {
			equipo_2_height[3] += velocidad_jugador;
		}
		break;
		//mover abajo
	case '.':
		if (equipo_2_height[0] > -120) {
			equipo_2_height[0] -= velocidad_jugador;
		}
		break;
	case ',':
		if (equipo_2_height[1] > -200) {
			equipo_2_height[1] -= velocidad_jugador;
		}
		break;
	case 'm':
		if (equipo_2_height[2] > -400) {
			equipo_2_height[2] -= velocidad_jugador;
		}
		break;
	case 'n':
		if (equipo_2_height[3] > -400) {
			equipo_2_height[3] -= velocidad_jugador;
		}
		break;
	}
	glutPostRedisplay();
}

void idle(void) {
	plop.move();
	plop.bounds();
	glutPostRedisplay();
	bounce2(paredes_cancha);
	bounce2(paredes_equipo_1);
	bounce2(paredes_equipo_2);
	switch (check_gol()/*este metodo revisa si alguin metio gol regresa int*/) {
	case 1:
		//mete gol equipo 1
		goles_equipo_1++;
		centra();
		break;
	case 2:
		//mete gol equipo 2
		goles_equipo_2++;
		centra();
		break;
	}
	Sleep(5);

}

void mostrar() {
	glClear(GL_COLOR_BUFFER_BIT);
	cancha();
	glColor3f(0, 0, 0);
	plop.draw();
	equipo1a(-1200 ,30 ,equipo_1_height);
	equipo2a(1200, 30, equipo_2_height);
	puntaje();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Futbolito");
	init();
	glClearColor(0.0,0.3,0.01,0.0);
	glutSpecialFunc(SpecialInput);
	glutKeyboardFunc(keyInput);
	glutDisplayFunc(mostrar);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
