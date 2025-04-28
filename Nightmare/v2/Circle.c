#include "Circle.h"


void circle_draw(Circle* this, canvas *c){
	canvas_set(c, this->base.x_, this->base.y_, this->base.style_);
}
Circle* circle_create(Circle *this, int x, int y, int r, char style){
	shape_create((void*)this, x, y,style);
	this->base.draw = v(circle_draw);
	this->x1_ = x;
	this->y1_ = y;
    this->r_ = r;
    this->test_ = malloc(sizeof(int));
	return this;
}

Circle* circle_destroy(Circle *this){shape_destroy(v(this)); free(this->test_); return this;}

Circle* new_circle(int x, int y, int r, char style){
	return circle_create(malloc(sizeof(Circle)),x,y,r,style);
}
void delete_circle(Circle *this){
	free(circle_destroy(this));
}
void circle_create_formfile(Circle* this,FILE *f){
	fprintf(stderr, "Shapes should not be read from file");
	exit(EXIT_FAILURE);
}