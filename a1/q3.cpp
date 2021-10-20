#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0); // Set display-window color to white.
	glMatrixMode (GL_PROJECTION); // Set projection parameters.
	gluOrtho2D (0, 400, 0, 400);// Orthogonal projection: [x,y,z]--->[x,y,0]
}

// Implementing Mid-Point Circle Drawing Algorithm
void midPointCircleDraw(void){
    glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f (1.0, 1.0, 0.0); // Set point color to green.
	glPointSize(10.0f); // Set point size
	glBegin(GL_POINTS);// Marks the beginning of the vertices list

    int x_centre = 200;
    int y_centre = 200;
    int r = 100;

	int x = r*cos(135*PI/180), y = r*sin(135*PI/180);
	// Printing the initial point on the axes
	// after translation
   
    glVertex2i(x+x_centre, y+y_centre);

	// Initialising the value of P
    
	int d = x*x + y*y - r*r;

    while (y > 0){
        y--;
        if (d < 0){
            x--;
            d += x*x + y*y - r*r;
        }
        else{
            d = x*x + y*y - r*r;
        }
        glVertex2i(x + x_centre, y + y_centre);
    }

    while (y > r*sin(215*PI/180)){	
        y--;
		if (d <= 0){
            d = x*x + y*y - r*r;
        }
		else{
            x++;
            d = x*x + y*y - r*r;
		}		
        glVertex2i(x+x_centre, y+y_centre);
	}
    
    glEnd();
	glFlush(); 

}

int main(int argc, char** argv){
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.
	glutInitWindowPosition(0, 0); // Set top-left display-window position.
	glutInitWindowSize(700, 700); // Set display-window width and height.
	glutCreateWindow("Assignment 1: Q2"); // Create display window.
	init(); // Execute initialization procedure.
	glutDisplayFunc(midPointCircleDraw); // Send graphics to display window.
	glutMainLoop(); // Display everything and wait.
}
