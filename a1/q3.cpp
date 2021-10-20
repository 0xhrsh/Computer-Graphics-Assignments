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

void midPointCircleDraw(void){
    glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f (1.0, 1.0, 0.0);
	glPointSize(7.0f); // Set point size
	glBegin(GL_POINTS);// Marks the beginning of the vertices list

    int x_centre = 200;
    int y_centre = 200;
    int r = 100;

	int x = r*cos(135*PI/180), y = r*sin(135*PI/180);
   
    glVertex2i(x+x_centre, y+y_centre);

    int d = 1.25 + r*sin(135*PI/180);

    int dsw = 2*x + 2*y +5;
    int dw = 2*y + 3;

    while (y-- > 0){
        if (d < 0){
            d = d + dw;
            dw = dw - 2;
            dsw = dsw - 2;
        }
        else{
            d = d + dsw;
            x--;
            dw = dw -2;
            dsw = dsw - 4;
        }
        glVertex2i(x + x_centre, y + y_centre);
    }

    while (y-- > r*sin(215*PI/180)){	
        if (d < 0){
            d = d + dw;
            dw = dw + 2;
            dsw = dsw + 2;
        }
        else{
            d = d + dsw;
            y--;
            x++;
            dw = dw + 2;
            dsw = dsw + 4;
        }
        glVertex2i(x + x_centre, y + y_centre);
	}

    glEnd();
	glFlush(); 

}

int main(int argc, char** argv){
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.
	glutInitWindowPosition(0, 0); // Set top-left display-window position.
	glutInitWindowSize(700, 700); // Set display-window width and height.
	glutCreateWindow("Assignment 1: Q3"); // Create display window.
	init(); // Execute initialization procedure.
	glutDisplayFunc(midPointCircleDraw); // Send graphics to display window.
	glutMainLoop(); // Display everything and wait.
}
