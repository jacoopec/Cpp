#include "Rectangle.h"

typedef struct Rectangle{
    shape base;
	int x1_, y1_;
} Rectangle;

void rectangle_draw(Rectangle* this, canvas *c){
	canvas_set(c, this->base.x_, this->base.y_, this->base.style_);
}
Rectangle* rectangle_create(Rectangle *this, int x, int y, char style){
	shape_create((void*)this, x, y,style);
	this->base.draw = v(rectangle_draw);
	this->x1_ = x;
	this->y1_ = y;
	return this;
}

Rectangle* rectangle_destroy(Rectangle *this){shape_destroy(v(this)); return this;}

Rectangle* new_rectangle(int x, int y, char style){
	return rectangle_create(malloc(sizeof(Rectangle)),x,y,style);
}
void delete_rectangle(Rectangle *this){
	free(rectangle_destroy(this));
}
void rectangle_create_formfile(Rectangle* this,FILE *f){
	fprintf(stderr, "Shapes should not be read from file");
	exit(EXIT_FAILURE);
}