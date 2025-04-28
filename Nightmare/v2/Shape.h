#include "canvas.h"
#include "canvas.h"

#define v(x) (void*)(x)
typedef void(*draw_fn)(struct shape *this, canvas *c); //virtual dispatching
typedef void(*destroy_fn)(struct shape *this);   //virtual desctructor

//all of the shapes have something in common
typedef struct shape{
    int x_, y_; //reference point
    char style_;
	char *name_;
	draw_fn draw;
	destroy_fn destroy;
} shape;

shape* shape_create(shape *this, int x, int y, char style);
shape* shape_destroy(shape *this);
shape* new_shape(int x, int y, char style);
void delete_shape(shape *this);
void shape_draw(shape* this, canvas *c);
void shape_create_formfile(shape* this,FILE *f);
void shape_set_name(shape *this, const char *name);
const char* shape_name(shape *this);