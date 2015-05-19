#include "vaomanager.h"
#include <glscene.h>

VAOManager::VAOManager(GLScene* current)
    :currentScene(current)
{

}


void VAOManager::initVAO()
{
    generateArrays();
    vao = new QOpenGLVertexArrayObject(currentScene);
    vao->create();
    vao->bind();
    QOpenGLBuffer vertexBuffer;
    vertexBuffer.create();
    vertexBuffer.bind();
    vertexBuffer.allocate(verts.data(), verts.size()*sizeof(GLfloat));
    currentScene->getShaderProgram()->enableAttributeArray("vertex");
    currentScene->getShaderProgram()->setAttributeBuffer("vertex", GL_FLOAT, 0, 3);
    QOpenGLBuffer colorBuffer;
    colorBuffer.create();
    colorBuffer.bind();
    colorBuffer.allocate(colors.data(), colors.size()*sizeof(GLfloat));
    currentScene->getShaderProgram()->enableAttributeArray("color");
    currentScene->getShaderProgram()->setAttributeBuffer("color", GL_FLOAT, 0, 3);
    QOpenGLBuffer indexBuffer(QOpenGLBuffer::IndexBuffer);
    indexBuffer.create();
    indexBuffer.bind();
    indexBuffer.allocate(indices.data(), indices.size()*sizeof(GLuint));
    vao->release();
}

QOpenGLVertexArrayObject* VAOManager::getVAO()
{
    return vao;
}

void VAOManager::generateArrays()
{
    //axes (GL_LINES)
    //x
    verts.push_back(0); verts.push_back(0); verts.push_back(0);
    colors.push_back(1); colors.push_back(0); colors.push_back(0);
    verts.push_back(1000); verts.push_back(0); verts.push_back(0);
    colors.push_back(1); colors.push_back(0); colors.push_back(0);
    //y
    verts.push_back(0); verts.push_back(0); verts.push_back(0);
    colors.push_back(0); colors.push_back(1); colors.push_back(0);
    verts.push_back(0); verts.push_back(1000); verts.push_back(0);
    colors.push_back(0); colors.push_back(1); colors.push_back(0);
    //z
    verts.push_back(0); verts.push_back(0); verts.push_back(0);
    colors.push_back(0); colors.push_back(0); colors.push_back(1);
    verts.push_back(0); verts.push_back(0); verts.push_back(1000);
    colors.push_back(0); colors.push_back(0); colors.push_back(1);

    for (int i = 0; i < verts.size()/3; ++i)
        indices.push_back(i);

    vertsCount = indices.size();
}

int VAOManager::getVertsCount()
{
    return vertsCount;
}

VAOManager::~VAOManager()
{

}
