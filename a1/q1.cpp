#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h>
#include <iostream>
using namespace std;

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0); // Set display-window color to white.
	glMatrixMode (GL_PROJECTION); // Set projection parameters.
	gluOrtho2D (0, 500, 0, 500);// Orthogonal projection: [x,y,z]--->[x,y,0]
}

void midPoint(void){
    glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f (0.0, 0.0, 1.0);
	glPointSize(2.0f); // Set point size
	glBegin(GL_POINTS);// Marks the beginning of the vertices list

    int x0 = 150;
    int y0 = 150;
    int x1 = 300;
    int y1 = 300;

    int dx = x1 - x0;
    int dy = y1 - y0;
   
    if(dy<=dx){
        int d = dy - (dx/2);
        int x = x0, y = y0;
 
        // Plot initial given point
        glVertex2i(x, y);

        // iterate through value of X
        while (x < x1){
            x++;
 
            // E or East is chosen
            if (d < 0)
                d = d + dy;
 
            // NE or North East is chosen
            else{
                d += (dy - dx);
                y++;
            }
 
            // Plot intermediate points
            glVertex2i(x, y);
        
        }
    } else if(dx<dy){
        // initial value of decision parameter d
        int d = dx - (dy/2);
        int x = x0, y = y0;
    
        // Plot initial given point
        glVertex2i(x, y);

        // iterate through value of X
        while (y < y1){
            y++;
    
            // E or East is chosen
            if (d < 0)
                d = d + dx;
    
            // NE or North East is chosen
            // NE or North East is chosen
            else{
                d += (dx - dy);
                x++;
            }
    
            // Plot intermediate points
            glVertex2i(x, y);
        }
    }
    glEnd();
    glFlush(); 
}

int main(int argc, char** argv){
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.
	glutInitWindowPosition(10, 30); // Set top-left display-window position.
	glutInitWindowSize(500, 500); // Set display-window width and height.
	glutCreateWindow("Assignment 1: Q1"); // Create display window.
	init(); // Execute initialization procedure.
	glutDisplayFunc(midPoint); // Send graphics to display window.
	glutMainLoop(); // Display everything and wait.
}
