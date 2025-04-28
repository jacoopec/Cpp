#include "Shape.h"
#include "../../cheaders.h"

#define v(x) (void*)(x)
typedef void(*draw_fn)(struct shape *this, canvas *c);

//all of the shapes have something in common
typedef struct shape{
    int x_, y_; //reference point
    char style_;
	char *name_;
	draw_fn draw;  //virtual dispatching
} shape;

shape* shape_create(shape *this, int x, int y, char style){
	this->x_ = x; this->y_ = y; this->style_ = style; this->name_ = NULL; this->draw = shape_draw; return this;
}
shape* shape_destroy(shape *this){free(this->name_);return this;}
shape* new_shape(int x, int y, char style){
	return shape_create(malloc(sizeof(shape)),x,y,style);
}
void delete_shape(shape *this){
	free(this->destroy(this));
}
void shape_draw(shape* this, canvas *c){
	canvas_set(c, this->x_, this->y_, this->style_);
}
void shape_create_formfile(shape* this,FILE *f){
	fprintf(stderr, "Shapes should not be read from file");
	exit(EXIT_FAILURE);
}
void shape_set_name(shape *this, const char *name){
	free(this->name_);
	this->name_ = malloc(strlen(name)+1);
	strcpy(this->name_, name);
}
const char* shape_name(shape *this){
	return this->name_;
}