#include "canvas.h"
#include "Shape.h"
#include "../../cheaders.h"

#define v(x) (void*)(x)
typedef void(*draw_fn)(struct shape *this, canvas *c);

typedef struct Rectangle{
    shape base;
	int x1_, y1_;
} Rectangle;

void rectangle_draw(Rectangle* this, canvas *c);
Rectangle* rectangle_create(Rectangle *this, int x, int y, char style);
Rectangle* rectangle_destroy(Rectangle *this);
Rectangle* new_rectangle(int x, int y, char style);
void delete_rectangle(Rectangle *this);
void rectangle_create_formfile(Rectangle* this,FILE *f);