# 3D_Viewer

<img src="../img/3d-model.png" alt="" width="40"> ``3D_Viewer`` is an educational project for <a href="https://21-school.ru">School 21</a> in Moscow.

## Introduction

This project implements a program to view 3D wireframe models (3D Viewer) consisting of two parts: back in C programming language and front in C++ and QT. The models themselves are loaded from .obj files and are viewable on the screen with the ability to rotate, scale and translate.

A wireframe model is a model of an object in 3D graphics, which is a set of vertices and edges that defines the shape of the displayed polyhedral object in three-dimensional space.

<a>
    <img src="../img/3D_Viewer_1.gif" alt="" width="1000">
</a>

### .Obj file format for representing the definition of 3D objects

.Obj file is a geometry definition file format first developed by Wavefront Technologies. The file format is open and accepted by many 3D graphics application vendors.
The .obj file format is a simple data format that represents only three-dimensional geometry, specifically the position of each vertex, the UV of each texture coordinate vertex, vertex normals and the faces that define each polygon as a list of vertices and texture vertices. Obj coordinates have no units, but Obj files can contain scale information in a readable comment line.
The example of .obj file format:

```
  # List of geometric vertices, with (x, y, z [,w]) coordinates, w is optional and defaults to 1.0.
  v 0.123 0.234 0.345 1.0
  v ...
  ...
  # Texture coordinates (u, [,v ,w]), w is optional and default to 0.
  vt 0.500 -1.352 [0.234]
  vt ...
  ...
  # Normals (x,y,z)
  vn 0.707 0.000 0.707
  vn ...
  ...
  # Parameter space vertices (u [,v] [,w])
  vn 0.707 0.000 0.707
  vn ...
  ...
  # Polygonal face element
  f v1 v2 v3
  f ...
  ...
  # Group
  g Group1
  ...
  # Object
  o Object1

```
<a>
    <img src="../img/3D_Viewer_2.gif" alt="" width="1000">
</a>

### Report

The project implements full coverage of library functions with Unit-tests using the ``Check library`` in C (<check.h> library).
The gcov_report target (a part of Makefile) generates a gcov-report in the form of an html page: <a href="../../back/gcov_report/gcov_report.html">GCOVR report</a>.

<a>
    <img src="../img/gcov_report.png" alt="" width="1000">
</a>

### The crew

<img src="../img/say_hi.gif" alt="" width="50"> *Polina* a.k.a **Polza** a.k.a <a href="https://github.com/cormacsi">cormacsi</a> a.k.a Polina Malina

<img src="../img/say_hi.gif" alt="" width="50"> *Ilusha* a.k.a **Supreme** a.k.a <a href="https://github.com/llilyshkall">chatayap</a> a.k.a Ilysha Hryusha
