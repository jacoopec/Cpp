#include "Shape.h"
#include "canvas.h"
#include "../../cheaders.h"

typedef struct point{
    shape base;
} point;

void point_draw(point* this, canvas *c);
point* point_create(point *this, int x, int y, char style);
point* point_destroy(point *this);
point* new_point(int x, int y, char style);
void delete_point(point *this);
void point_create_formfile(point* this,FILE *f);