/**
 * @file shape.h
 * @author chatayap
 * @brief Header file for parser, scale and rotation
 * @version 0.1
 * @date 2023-07-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_BACK_SHAPE_H
#define SRC_BACK_SHAPE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef M_PI
/**
 * @brief Definition for Valgrind memory testing on Linux distribution,
 * where M_PI is not defined in C standard
 */
#define M_PI 3.14159265358979323846
#endif

/**
 * @brief Adding one element to an array with memory realocation
 *
 * @param array Pointer to an array
 * @param count Array counter
 * @param elem The element being added
 */
#define ADD_ELEM(array, count, elem)                        \
  (count)++;                                                \
  (array) = realloc((array), (count) * sizeof((array)[0])); \
  (array)[(count)-1] = (elem)

/**
 * @brief Structure for storing the frame of the figure
 */
typedef struct Shape_ {
  int countVertexes;    /**< Number of vertices of the frame */
  double* vertexesInit; /**< Array of coordinates of the vertices of the initial
                           figure*/
  double* vertexes; /**< Array of coordinates of the vertices of the rotated,
                       moved figure*/
  int countLines;   /**< Number of edges of the frame */
  unsigned* lines; /**< Array of sides of the frame. The segments go in pairs */
  double scale;    /**< Scale of the figure */
  double angles[3]; /**< Rotation angles relative to three axes */
  double shifts[3]; /**< Shift along three coordinate axes */
} Shape;

/**
 * @brief Struct for storing frame elements,
 * where V - list of geometric vertices,
 * VT - texture coordinates,
 * VN - normals.
 */
typedef struct FrameElement_ {
  unsigned mask; /**< Data fullness mask */
  unsigned v;    /**< List of geometric vertices */
  unsigned vt;   /**< Texture coordinates */
  unsigned vn;   /**< Normals */
} FrameElement;

/**
 * @brief Enumerable type for coordinate axes
 */
typedef enum Axis_ { AXIS_X, AXIS_Y, AXIS_Z } Axis;

/**
 * @addtogroup Initialization
 * @{
 */

/**
 * @brief The function of reading the object file and initializing the shape
 * structure
 *
 * @param shape Pointer to the structure in which the frame is written
 * @param file The .obj file name to read
 * @return int 1 - success
 * @return int 0 - fail
 */
int initShape(Shape* shape, const char* file);

/**
 * @brief Structure zeroing function
 *
 * @param shape Pointer to the structure of the figure
 */
void zeroingShape(Shape* shape);

/**
 * @brief Adding a vertex to the shape structure
 *
 * @param shape Pointer to the structure of the figure
 * @param s A single line from the file
 */
void addVertex(Shape* shape, char* s);

/**
 * @brief Adding wireframe lines to the shape structure
 *
 * @param shape Pointer to the structure of the figure
 * @param s A single line from the file
 */
void addFrame(Shape* shape, char* s);

/**
 * @brief Reads the coordinate of the polygon vertex
 *
 * @param elem The structure in which the polygon coordinate is written
 * @param s Pointer to a part of a string
 * @return int 1 - success
 * @return int 0 - fail
 */
int readElem(FrameElement* elem, char** s);

/**
 * @brief Сoordinate transformation to fit into area 1 < x, y, z < -1
 *
 * @param shape Pointer to the structure of the figure
 */
void centring(Shape* shape);

/**
 * @}
 *
 */

/**
 * @addtogroup Scaling
 * @{
 */

/**
 * @brief Setting the scale of the object
 *
 * @param shape Pointer to the structure of the figure
 * @param scale Scale of the figure
 * @return int 1 - success
 * @return int 0 - fail
 */
int setScale(Shape* shape, double scale);

/**
 * @}
 *
 */

/**
 * @addtogroup Shifting
 * @{
 */

/**
 * @brief Performs the shift of vertices along one axis
 *
 * @param shape Pointer to the structure of the figure
 * @param coord The number by which each coordinate of a certain axis is shifted
 * @param axis One of the three coordinate axes
 * @return int 1 - success
 * @return int 0 - fail
 */
int shifting(Shape* shape, double coord, Axis axis);

/**
 * @}
 *
 */

/**
 * @addtogroup Rotation
 * @{
 */

/**
 * @brief Performs rotation along three coordinate axes
 *
 * @param shape Pointer to the structure of the figure
 * @param dAngles An array of three rotation angles
 * @return int 1 - success
 * @return int 0 - fail
 */
int rotation(Shape* shape, const double dAngles[3]);

/**
 * @brief Rotation matrix creation function
 *
 * @param dAngles [3] Rotation angle relative to the Ox, Oy, Oz axises
 * @param rotationMatrix Rotation matrix
 */
void initRotationMatrix(double dAngles[3], double rotationMatrix[3][3]);

/**
 * @}
 *
 */

/**
 * @addtogroup Destructor
 * @{
 */

/**
 * @brief Memory release function
 *
 * @param shape Pointer to the structure of the figure
 */
void clearShape(Shape* shape);

/**
 * @}
 *
 */

#endif  // SRC_BACK_SHAPE_H
