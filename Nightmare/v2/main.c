#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>

#include "canvas.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Circle.h"
#include "Point.h"
#include "string.h"
#include "../../cheaders.h"

#define v(x) (void*)(x)
typedef void(*draw_fn)(struct shape *this, canvas *c);

//you can use the derived instead of the base, the behaviors are different, but the interface is the same. 
//How do we say that a point is a shape?
//you should use inheritance when you want to model IS A. this relationallows you to use the derived class
//whenyou can use the base class. Use the derived instead of the based, with the same interface
//but different behaviors.
//if you give a function the address of point, the compiler will find the address of base shape
//in memory they will be exactly the same thing.

/*
type_of_object parameter_1 parameter_2 ... parameter_n

rectangle 0 0 79 24 *
Rectangle 5 15 ?
circle 10 10 4 @
circle 70 10 4 @
line 40 15 40 20 |
*/

void draw_file(FILE *f, canvas *c)
{
	char type[30];
	while (fscanf(f, "%29s", type) == 1) {  //limit to 29 chars, skip white spaces, we read the name of the obj
		if (strcmp(type, "point") == 0) {
			int x, y;
			char ch;
			fscanf(f, "%d%d %c", &x, &y, &ch);  //skip spaces, read the char
			canvas_set(c, x, y, ch);
		}
		else if (strcmp(type, "line") == 0) {
			int x0, y0, x1, y1;
			char ch;
			fscanf(f, "%d%d%d%d %c", &x0, &y0, &x1, &y1, &ch);
			canvas_line(c, x0, y0, x1, y1, ch);
		}
		else if (strcmp(type, "rectangle") == 0) {
			int x0, y0, x1, y1;
			char ch;
			fscanf(f, "%d%d%d%d %c", &x0, &y0, &x1, &y1, &ch);
			canvas_rectangle(c, x0, y0, x1, y1, ch);
		}
		else if (strcmp(type, "circle") == 0) {
			int xm, ym, r;
			char ch;
			fscanf(f, "%d%d%d %c", &xm, &ym, &r, &ch);
			canvas_circle(c, xm, ym, r, ch);
		}
	}
}

int main(void)
{
	canvas* c = new_canvas(80, 25);
	point* p = new_point(10,10,'^');
	Circle* c1 = new_circle(10,10,4,'?');
	Rectangle *r = new_rectangle(20,10,'=');
	// line*  l = new_line(39,49,29,39,'£');
	shape*  s = new_line(39,49,29,39,'£');
	shape *arr[5] = {s,p,c1,r};
	for(size_t i = 0; i < 5; ++i){
		puts(shape_name(arr[i]));  //calling the base methods on the derived.
		//it is not real polymorphism, we are calling the methods of shape with things that are compatible
		//with shape
	}

	point_draw(p,c);
	rectangle_draw(p,c);
	line_draw(p,c);

	for(size_t i = 0; i < 5; ++i){
		arr[i]->draw(arr[i], c); //we want to detect the type of the obj and call a function
		//based on that type
	}

	draw_file(stdin, c);

	shape_set_name(r, "Rectangle"); //calling a base class method on a base class obj

	canvas_out(c, stdout);

	//-----------------------------------------------------
	// delete_point(p);
	// delete_circle(c1);
	// delete_rectangle(r);
	//delteing objs loop
	for(size_t i = 0; i < 5; ++i){
		delete_shape(arr[i]);
	}
	delete_canvas(c);

}