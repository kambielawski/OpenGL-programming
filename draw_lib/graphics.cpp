#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include "../linmath.h"

void grid (int x_gridlines, int y_gridlines) {
  float x_width = 2.0 / (float) x_gridlines;
  float y_width = 2.0 / (float) y_gridlines;

  glBegin(GL_LINES);
  glColor3f(1,1,1);
  for (float i = -1.0; i <= 1.0; i += x_width) {
    glVertex3f(-1.1, i, 0);
    glVertex3f(1.1, i, 0);
  }

  for (float i = -1.0; i <= 1.0; i += y_width) {
    glVertex3f(i, -1.1, 0);
    glVertex3f(i, 1.1, 0);
  }
  glEnd();
}

void circle (float x, float y, float radius) {
  glBegin(GL_POLYGON);
  for (int i = 0; i < 360; i++) {
    glVertex3f(radius * cos((float)i), radius * sin((float)i), 0);
  }
  glEnd();
}

void draw_i (float size, float x = 0.0, float y = 0.0, GLfloat r = 1.0f, GLfloat g = 0.0f, GLfloat b = 0.0f) {
  glBegin(GL_LINES);
  glColor3f(r, g, b);
  // bottom
  glVertex3f(-0.25 * size + x, -0.5 * size + x, 0);
  glVertex3f(-0.25 * size + x, -0.375 * size + y, 0);

  glVertex3f(-0.25 * size + x, -0.5 * size + y, 0);
  glVertex3f(0.25 * size + x, -0.5 * size + y, 0);

  glVertex3f(0.25 * size + x, -0.5 * size + y, 0);
  glVertex3f(0.25 * size + x, -0.375 * size + y, 0);

  glVertex3f(-0.25 * size + x, -0.375 * size + y, 0);
  glVertex3f(-0.0625 * size + x, -0.375 * size + y, 0);

  glVertex3f(0.25 * size + x, -0.375 * size + y, 0);
  glVertex3f(0.0625 * size + x, -0.375 * size + y, 0);
  
  // middle
  glVertex3f(-0.0625 * size + x, -0.375 * size + y, 0);
  glVertex3f(-0.0625 * size + x, 0.375 * size + y, 0);

  glVertex3f(0.0625 * size + x, -0.375 * size + y, 0);
  glVertex3f(0.0625 * size + x, 0.375 * size + y, 0);

  // top
  glVertex3f(-0.25 * size + x, 0.5 * size + y, 0);
  glVertex3f(0.25 * size + x, 0.5 * size + y, 0);

  glVertex3f(0.25 * size + x, 0.5 * size + y, 0);
  glVertex3f(0.25 * size + x, 0.375 * size + y, 0);

  glVertex3f(-0.25 * size + x, 0.5 * size + y, 0);
  glVertex3f(-0.25 * size + x, 0.375 * size + y, 0);
  
  glVertex3f(-0.25 * size + x, 0.375 * size + y, 0);
  glVertex3f(-0.0625 * size + x, 0.375 * size + y, 0);

  glVertex3f(0.25 * size + x, 0.375 * size + y, 0);
  glVertex3f(0.0625 * size + x, 0.375 * size + y, 0);
}