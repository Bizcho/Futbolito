/// motor de fisica ///
#include "figuras.h"
#include <math.h>

class Pared;

class Pelota {
public:
	int pos_x, pos_y, radio;
	int velocidad;
	int direccion;
	int vel_x, vel_y;
	int right_bound, top_bound, left_bound, down_bound;

	Pelota(int, int);

	void bounds(void);
	void bounce(Pared paredes[12]);
	void draw();
	void move();
};

class Pared {
public:
	int pos_x, pos_y;
	int height, width;
	int right_bound, top_bound, left_bound, down_bound;
	bool activa;

	Pared();

	void bounds(void);
	void prender();
	void apagar();
	void set(int, int, int, int);
};

Pelota::Pelota(int vel, int dir) {
	velocidad = vel;
	direccion = dir;
	radio = 30;
	vel_x = velocidad * cos(direccion * (3.1416 / 180));
	vel_y = velocidad * sin(direccion * (3.1416 / 180));
	bounds();
}

void Pelota::bounds() {
	top_bound = pos_y + radio;
	down_bound = pos_y - radio;
	right_bound = pos_x + radio;
	left_bound = pos_x - radio;
}

void Pelota::draw() {
	dibujaCirculo(radio, pos_x, pos_y);
}

void Pelota::move() {
	pos_x += vel_x;
	pos_y += vel_y;
}

void Pelota::bounce(Pared paredes[12]) {
	for each (Pared pared in paredes)
	{
		if (pared.activa) {
			if (right_bound >= pared.left_bound &&  pos_y > pared.down_bound
				&& pos_y < pared.top_bound && left_bound < pared.left_bound) {
				vel_x *= -1;
			}
			if (left_bound < pared.right_bound && pos_y > pared.down_bound
				&& pos_y < pared.top_bound && right_bound > pared.right_bound) {
				vel_x *= -1;
			}
			if (top_bound >= pared.down_bound && pos_x > pared.left_bound
				&& pos_x < pared.right_bound && down_bound < pared.down_bound) {
				vel_y *= -1;
			}
			if (down_bound <= pared.top_bound && pos_x > pared.left_bound
				&& pos_x < pared.right_bound && top_bound > pared.top_bound) {
				vel_y *= -1;
			}
		}
	}
}

Pared::Pared() {
	pos_x = 0;
	pos_y = 0;
	height = 0;
	width = 0;

}

void Pared::prender() {
	activa = true;
	bounds();
}
void Pared::apagar() {
	activa = false;
}

void Pared::bounds() {
	top_bound = pos_y;
	down_bound = pos_y - height;
	right_bound = pos_x + width;
	left_bound = pos_x;
}

void Pared::set(int x, int y, int h, int w) {
	pos_x = x;
	pos_y = y;
	height = h;
	width = w;
}