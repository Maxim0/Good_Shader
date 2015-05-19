#ifndef VAOMANAGER_H
#define VAOMANAGER_H

#include <QtOpenGL>

class GLScene;

class VAOManager
{
public:
    VAOManager(GLScene* current);
    ~VAOManager();
    void initVAO();
    int getVertsCount();
    QOpenGLVertexArrayObject *getVAO();
private:
    GLScene* currentScene;
    QOpenGLVertexArrayObject* vao;
    QVector<GLfloat> verts;
    QVector<GLfloat> colors;
    QVector<GLuint> indices;
    int vertsCount;
    void generateArrays();
};

#endif VAOMANAGER_H
