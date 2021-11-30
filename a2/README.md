# Assignment 2

Running the assignment: 
- Run the following command: `g++ main.cpp -lGL -lGLU -lglut && ./a.out`
- The program will then ask you to select a mesh:
```
    Press 1 for cat01.off
    Press 2 for gorilla05.off
    Press 3 for michael18.off
    Press 4 for wolf02.off
```
- press a number from 1, 2, 3, 4 and then press enter to view the model.
- Change camera position from line 42, 43, 44 from the file `main.cpp`

Example:

![image](https://user-images.githubusercontent.com/44001232/144097897-903947ab-5d53-4b19-a8f1-8957e38f59a5.png)

(see example.png)

## Contribution:	
- Harsh Anand (B18CSE016) - Camera co-ordinate system, normal for each triangle, back face culling, widow and viewport size. also helped with phong shading.
- Yashvi Ramanuj (B18CSE045) - phong shading, rendering the object, file I/O, View frutum size and normalised device coordinates, transformation of co-ordinates. also helped in back face culling.
