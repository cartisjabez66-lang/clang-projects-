#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 40

float A = 0, B = 0, C = 0; // Rotation angles
float zBuffer[WIDTH * HEIGHT];
char buffer[WIDTH * HEIGHT];
int backgroundASCIICode = ' ';
float cubeWidth = 20;
int distanceFromCam = 100;
float K1 = 40; // Projection scale factor

float calculateX(int i, int j, int k) {
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

float calculateY(int i, int j, int k) {
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
           j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
           i * cos(B) * sin(C);
}

float calculateZ(int i, int j, int k) {
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
    float x = calculateX(cubeX, cubeY, cubeZ);
    float y = calculateY(cubeX, cubeY, cubeZ);
    float z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

    float ooz = 1 / z; // One over Z (depth)

    // Perspective Projection onto 2D screen
    int xp = (int)(WIDTH / 2 + K1 * ooz * x * 2);
    int yp = (int)(HEIGHT / 2 + K1 * ooz * y);

    int idx = xp + yp * WIDTH;
    if (idx >= 0 && idx < WIDTH * HEIGHT) {
        if (ooz > zBuffer[idx]) {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

int main() {
    printf("\x1b[2J"); // Clear screen once

    while (1) {
        memset(buffer, backgroundASCIICode, WIDTH * HEIGHT);
        memset(zBuffer, 0, sizeof(zBuffer));

        // Render faces of the 3D cube
        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += 0.6) {
            for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += 0.6) {
                calculateForSurface(cubeX, cubeY, -cubeWidth, '@');
                calculateForSurface(cubeWidth, cubeY, cubeX, '$');
                calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
                calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
                calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
                calculateForSurface(cubeX, cubeWidth, cubeY, '+');
            }
        }

        // Draw buffer to terminal
        printf("\x1b[H"); // Reset cursor to top-left
        for (int k = 0; k < WIDTH * HEIGHT; k++) {
            putchar(k % WIDTH ? buffer[k] : 10);
        }

        // Increment rotation angles
        A += 0.05;
        B += 0.05;
        C += 0.01;

        usleep(16000); // ~60 FPS delay
    }
    return 0;
}
