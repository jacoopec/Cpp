#include "canvas.h"
#include "Shape.h"
#include "../../cheaders.h"

typedef struct Circle{
    shape base;
	int x1_, y1_, r_;
    int *test_;
} Circle;

void circle_draw(Circle* this, canvas *c);
Circle* circle_create(Circle *this, int x, int y, int r, char style);
Circle* circle_destroy(Circle *this);
Circle* new_circle(int x, int y, int r, char style);
void delete_circle(Circle *this);
void circle_create_formfile(Circle* this,FILE *f);