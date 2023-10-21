/**************************************************************************************
 * rect.h - Define the structure to draw a Rectangule using OpenGL 1.0
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta
 *************************************************************************************/

// Define our lib to compiler
#ifndef RECT_H
#define	RECT_H

/*
 * Libraries Needed
 */
// C and C++ standard
#include <stdio.h>
#include <array>
#include <vector>

// OpenGL
#include <GL/gl.h>
#include <GL/glu.h>

/*
 * Constants and Default Values
 */
#define WIDTH		100
#define HEIGHT		100
#define ORIGIN_X	0
#define ORIGIN_Y	0


/*
 * Class Definition
 */
class Rect{
	public:
		// Determine the point of the object that will be on the origin when created
		enum Anchor
		{
			center,
			center_b,
			center_t,
			left,
			left_b,
			left_t,
			right,
			right_b,
			right_t
		};

	private:

		enum Colors{
			RED,
			GREEN,
			BLUE
		};

		// Class Atributes
		GLfloat width {WIDTH};	// inside {} is the default values. same as width = WIDTH
		GLfloat height {HEIGHT};
		GLfloat PositionX {ORIGIN_X};
		GLfloat PositionY {ORIGIN_Y};
		GLfloat Color[3] {1.0, 1.0, 1.0};	// Colors of the Rectangle - Default is White
		Anchor	anchorPlace {center};

		/*
		* Private Atributes and Methods of the Class
		*/

		/* Private Atributes */


		/* Private Methods */
		void DrawCenteredOn();

	/*
	 * Public Atributes and Methods of the Class
	 */
	public:
		/* Public Atributes */

		// Constructors of the Class
		Rect(){

		}
		Rect(float w, float h) : width{w}, height{h}{

		}
		Rect(float w, float h, float X, float Y): width{w}, height{h}, PositionX{X}, PositionY{Y}{

		}
		Rect(float w, float h, float X, float Y, GLfloat Red, GLfloat Green, GLfloat Blue) :
			 width{w}, height{h}, PositionX{X}, PositionY{Y}, Color{Red, Green, Blue}{

		}
		Rect(float w, float h, float X, float Y, Anchor centeredOn, GLfloat Red, GLfloat Green, GLfloat Blue) :
			 width{w}, height{h}, PositionX{X}, PositionY{Y}, anchorPlace{centeredOn}, Color{Red, Green, Blue}{

		}

		/*
		 * Setters and Getters
		 */
			// Getters
			GLfloat getwidth(){
				return this->width;
			}
			GLfloat getheight(){
				return this->height;
			}
			GLfloat getPositionX(){
				return this->PositionX;
			}
			GLfloat getPositionY(){
				return this->PositionY;
			}
			// GLfloat* getColor(){
			// 	GLfloat R = this->Color[RED];
			// 	GLfloat G = this->Color[GREEN];
			// 	GLfloat B = this->Color[BLUE];

			// 	GLfloat color[3] = {R, G, B};
			// 	return Color;
			// }
			int getanchorPlace(){
				return this->anchorPlace;
			}

			// Setters
			void setWidth(GLfloat w){
				this->width = w;
			}
			void setHeight(GLfloat h){
				this->height = h;
			}
			void setPositionX(GLfloat X){
				this->PositionX = X;
			}
			void setPositionY(GLfloat Y){
				this->PositionY = Y;
			}
			void setColor(GLfloat R, GLfloat G, GLfloat B){
				this->Color[RED] = R;
				this->Color[GREEN] = G;
				this->Color[BLUE] = B;

			}
			void setAnchorPlace(Anchor a){
				this->anchorPlace = a;
			}

		/* Public Methods */
		void Draw(){
			DrawCenteredOn();
		}

		// Destructor of the Class
};

class HLine : public Rect {
private:
	/* data */
	static constexpr GLfloat linewidth = 2.0f;

	bool dotted {false};
	float dotWidth {0};
	float spaceWidth {0};
	int numDots {1};

	std::vector<Rect*> dottedLine;	// Vector to Store Rectangles

public:
	HLine(float size, float X1, float Y1, GLfloat Red, GLfloat Green, GLfloat Blue, bool isDotted = false, int nDots = 10)
		: Rect(size, this->linewidth, X1, Y1, Rect::left, Red, Green, Blue), dotted(isDotted), numDots(nDots)
	{
		if (isDotted)
		{
			// TODO - Make the List of Rectangles for the 'dots', based on numDots
			// Calculate the width of a single dot based on available space
            if (numDots > 1){
                // Subtract the space between dots
                dotWidth = (size - spaceWidth * (numDots - 1)) / numDots;
            }
            // Create and store the 'dots' as Rectangles
            for (int i = 0; i < numDots; ++i){
                float dotX = X1 + i * (dotWidth + spaceWidth); // Calculate X position
                Rect* dot = new Rect(dotWidth, this->linewidth, dotX, Y1, Rect::left, Red, Green, Blue);
                dottedLine.push_back(dot); // Store the dot in the vector
            }
		}
	}

	void Draw() {
        if (dotted) { // Draw the dots if dotted
            for (Rect* dot : dottedLine){
				dot->Draw();
			}
        }
		else {
            // if Solid Line, Draw the Line Rectangle that defines the line
            Rect::Draw();
        }
    }


	~HLine(){
		for (Rect* dot : dottedLine)
        {
            delete dot; // Delete each Rectangle in the vector
        }
	}
};


#endif	/* RECT_H */

