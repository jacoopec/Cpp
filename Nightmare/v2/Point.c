#include "Point.h"
#include "Shape.h"

typedef struct point{
    shape base;
} point;

void point_draw(point* this, canvas *c){
	canvas_set(c, this->base.x_, this->base.y_, this->base.style_);
}
point* point_create(point *this, int x, int y, char style){
	shape_create((void*)this, x, y,style); // we can just use "this" because the location in memory is the same.
	// shape_create(&this->base, x, y,style);
	this->base.draw = v(point_draw);
    this->base.destroy = v(point_destroy);
	return this;
}

point* point_destroy(point *this){shape_destroy(v(this)); return this;}

point* new_point(int x, int y, char style){
	return point_create(malloc(sizeof(point)),x,y,style);
}
void delete_point(point *this){
	free(point_destroy(this));
}
void point_create_formfile(point* this,FILE *f){
	fprintf(stderr, "Shapes should not be read from file");
	exit(EXIT_FAILURE);
}