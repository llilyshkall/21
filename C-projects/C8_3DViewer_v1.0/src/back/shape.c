/**
 * @file shape.c
 * @author chatayap
 * @brief Parser, scale and rotation of the frame
 * @version 0.1
 * @date 2023-07-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "shape.h"

/**
 * The function reads all vertices and surfaces from a given file,
 * converts them into a structure for drawing,
 * finds the center of mass of the frame,
 * initializes shifts and rotations along the axes with zeros.
 */
int initShape(Shape* shape, const char* file) {
  if (!shape || !file) return 0;
  FILE* fp = NULL;
  if ((fp = fopen(file, "r")) == NULL) return 0;
  char s[200];
  zeroingShape(shape);
  while (fgets(s, 200, fp) && s[0]) {
    char c = 0;
    int shift = 0;
    sscanf(s, " %c%n", &c, &shift);
    if (c == 'v' && s[shift] == ' ') addVertex(shape, s + 1);
    if (c == 'f' && s[shift] == ' ') addFrame(shape, s + 1);
  }
  shape->vertexesInit = malloc(shape->countVertexes * sizeof(double));
  centring(shape);
  for (int i = 0; i < shape->countVertexes; ++i)
    shape->vertexesInit[i] = shape->vertexes[i];
  for (int i = 2; i < shape->countVertexes; i += 3) shape->vertexes[i] -= 2;
  fclose(fp);
  return 1;
}

/**
 * Initial initialization of the structure and zeroing of all fields
 */
void zeroingShape(Shape* shape) {
  shape->countLines = 0;
  shape->countVertexes = 0;
  shape->lines = NULL;
  shape->vertexes = NULL;
  shape->vertexesInit = NULL;
  shape->scale = 1;
  for (int i = 0; i < 3; ++i) {
    shape->angles[i] = 0;
    shape->shifts[i] = 0;
  }
}

/**
 * Reading the three coordinates of the vertex and adding it to the shape
 * structure
 */
void addVertex(Shape* shape, char* s) {
  double coord;
  int shift;
  for (int i = 0; i < 3; ++i) {
    sscanf(s, "%lf%n", &coord, &shift);
    ADD_ELEM(shape->vertexes, shape->countVertexes, coord);
    s += shift;
  }
}

/**
 * Reading coordinates of the wireframe lines and adding it to the shape
 * structure
 */
void addFrame(Shape* shape, char* s) {
  FrameElement elem, firstElem;
  if (readElem(&firstElem, &s)) {
    ADD_ELEM(shape->lines, shape->countLines, firstElem.v - 1);
  }
  while (readElem(&elem, &s)) {
    ADD_ELEM(shape->lines, shape->countLines, elem.v - 1);
    ADD_ELEM(shape->lines, shape->countLines, elem.v - 1);
  }
  if (firstElem.mask) {
    ADD_ELEM(shape->lines, shape->countLines, firstElem.v - 1);
  }
}

/**
 * A part of the string is read in which there can be
 * either a vertex with a texture or a vertex with a normal
 * or a vertex with a texture and a normal
 */
int readElem(FrameElement* elem, char** s) {
  int shift = 0;
  elem->mask = 0;
  if (sscanf(*s, "%u%n", &elem->v, &shift) == 1) {
    elem->mask = 4;
    *s += shift;
  }
  if (elem->mask == 4 &&
      sscanf(*s, "/%u/%u%n", &elem->vt, &elem->vn, &shift) == 2) {
    *s += shift;
    elem->mask = 7;
  }
  if (elem->mask == 4 && sscanf(*s, "//%u%n", &elem->vn, &shift) == 1) {
    *s += shift;
    elem->mask = 5;
  }
  if (elem->mask == 4 && sscanf(*s, "/%u%n", &elem->vt, &shift) == 1) {
    *s += shift;
    elem->mask = 6;
  }
  return elem->mask;
}

/**
 * The function transforms the shape by scaling and shifting coordinates
 */
void centring(Shape* shape) {
  double minCoord[3] = {shape->vertexes[0], shape->vertexes[1],
                        shape->vertexes[2]};
  double maxCoord[3] = {shape->vertexes[0], shape->vertexes[1],
                        shape->vertexes[2]};
  for (int i = 0; i < shape->countVertexes; ++i) {
    if (shape->vertexes[i] < minCoord[i % 3])
      minCoord[i % 3] = shape->vertexes[i];
    if (shape->vertexes[i] > maxCoord[i % 3])
      maxCoord[i % 3] = shape->vertexes[i];
  }
  double center[3], minScale = 1, maxScale = 1;
  for (int i = 0; i < 3; ++i) {
    center[i] = (maxCoord[i] + minCoord[i]) / 2;
    maxCoord[i] -= center[i];
    minCoord[i] -= center[i];
    minScale = minScale > fabs(maxCoord[i]) ? fabs(maxCoord[i]) : minScale;
    minScale = minScale > fabs(minCoord[i]) ? fabs(minCoord[i]) : minScale;
    maxScale = maxScale < fabs(maxCoord[i]) ? fabs(maxCoord[i]) : maxScale;
    maxScale = maxScale < fabs(minCoord[i]) ? fabs(minCoord[i]) : maxScale;
  }
  shape->scale = maxScale >= 1 || minScale < 1e-6 ? 1 / maxScale : 1 / minScale;
  for (int i = 0; i < shape->countVertexes; ++i)
    shape->vertexes[i] =
        (shape->vertexes[i] - center[i % 3]) * shape->scale * 0.8;
  shape->scale = 1;
}

/**
 * Shape transformation function relative to scale
 */
int setScale(Shape* shape, double scale) {
  if (!shape) return 0;
  double shift = scale / shape->scale;
  for (int i = 0; i < shape->countVertexes; ++i) {
    shape->vertexes[i] =
        (shape->vertexes[i] - shape->shifts[i % 3] + (i % 3 == 2 ? 2 : 0)) *
            shift +
        shape->shifts[i % 3] - (i % 3 == 2 ? 2 : 0);
    shape->vertexesInit[i] *= shift;
  }
  shape->scale = scale;
  return 1;
}

/**
 * The function searches for the desired coordinate of each point and changes it
 */
int shifting(Shape* shape, double coord, Axis axis) {
  if (!shape) return 0;
  double shift = coord - shape->shifts[axis];
  for (int i = 0; i < shape->countVertexes; i += 3)
    shape->vertexes[i + axis] += shift;
  shape->shifts[axis] = coord;
  return 1;
}

/**
 * The shape and angles of rotations around the three axes are transmitted,
 * the rotation matrix is set and multiplied by three coordinates of each vertex
 */
int rotation(Shape* shape, const double dAngles[3]) {
  if (!shape) return 0;
  double rotationMatrix[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  double coord[3];

  for (int i = 0; i < 3; ++i)
    shape->angles[i] = (shape->angles[i] + dAngles[i]) / 360 * 2 * M_PI;

  initRotationMatrix(shape->angles, rotationMatrix);

  for (int i = 0; i < shape->countVertexes / 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      coord[j] = shape->shifts[j] - (j == 2 ? 2 : 0);
      for (int k = 0; k < 3; ++k) {
        coord[j] += shape->vertexesInit[i * 3 + k] * rotationMatrix[j][k];
      }
      shape->vertexes[i * 3 + j] = coord[j];
    }
  }

  for (int i = 0; i < 3; ++i)
    shape->angles[i] = fmod(shape->angles[i % 3], 2 * M_PI) / (2 * M_PI) * 360;
  return 1;
}

/**
 * Сreating a rotation matrix for subsequent rotation
 * of the coordinates of the figure
 */
void initRotationMatrix(double dAngles[3], double rotationMatrix[3][3]) {
  double Mx[3][3] = {{1, 0, 0},
                     {0, cos(dAngles[0]), -sin(dAngles[0])},
                     {0, sin(dAngles[0]), cos(dAngles[0])}},
         My[3][3] = {{cos(dAngles[1]), 0, sin(dAngles[1])},
                     {0, 1, 0},
                     {-sin(dAngles[1]), 0, cos(dAngles[1])}},
         Mz[3][3] = {{cos(dAngles[2]), -sin(dAngles[2]), 0},
                     {sin(dAngles[2]), cos(dAngles[2]), 0},
                     {0, 0, 1}};
  double tmp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k) tmp[i][j] += Mx[i][k] * My[k][j];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      for (int k = 0; k < 3; ++k) rotationMatrix[i][j] += tmp[i][k] * Mz[k][j];
}

/**
 * Freeing up memory in the structure before program termination
 */
void clearShape(Shape* shape) {
  if (shape->vertexes) free(shape->vertexes);
  if (shape->vertexesInit) free(shape->vertexesInit);
  if (shape->lines) free(shape->lines);
}
