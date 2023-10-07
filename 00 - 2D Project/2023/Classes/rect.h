#ifndef RECT_H
#define	RECT_H

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Defaults
#define WIDTH		100
#define HEIGHT		100
#define ORIGIN_X	0
#define ORIGIN_Y	0


/* Class Definition */
class Rect
{
	// Class Atributes
    float width {WIDTH};
	float height{HEIGHT};
	float OriginX{ORIGIN_X};
	float OriginY{ORIGIN_Y};

/* Private Atributes and Methods of the Class */
private:
	/* Private Atributes */


	/* Private Methods */
    void DesenhaRect(GLint height, GLint width,
                    GLfloat R, GLfloat G, GLfloat B);

/* Public Methods of the Class */
public:
	/* Constructor of the Class Object*/
	Rect(){}
    Rect(float w, float h, float X, float Y): width{w}, height{h}, OriginX{X}, OriginY{Y}
	{}

    /* Public Methods */
	void Desenha();
};

#endif	/* RECT_H */

