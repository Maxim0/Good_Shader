#include "vaomanager.h"
#include <glscene.h>

VAOManager::VAOManager(GLScene* current)
	:currentScene(current)
{

}

void VAOManager::generateArrays()
{
	//axes (GL_LINES)
	//x
	vector_Verts.push_back(0); vector_Verts.push_back(0); vector_Verts.push_back(0);
	vector_Colors.push_back(1); vector_Colors.push_back(0); vector_Colors.push_back(0);
	vector_Verts.push_back(1000); vector_Verts.push_back(0); vector_Verts.push_back(0);
	vector_Colors.push_back(1); vector_Colors.push_back(0); vector_Colors.push_back(0);
	//y
	vector_Verts.push_back(0); vector_Verts.push_back(0); vector_Verts.push_back(0);
	vector_Colors.push_back(0); vector_Colors.push_back(1); vector_Colors.push_back(0);
	vector_Verts.push_back(0); vector_Verts.push_back(1000); vector_Verts.push_back(0);
	vector_Colors.push_back(0); vector_Colors.push_back(1); vector_Colors.push_back(0);
	//z
	vector_Verts.push_back(0); vector_Verts.push_back(0); vector_Verts.push_back(0);
	vector_Colors.push_back(0); vector_Colors.push_back(0); vector_Colors.push_back(1);
	vector_Verts.push_back(0); vector_Verts.push_back(0); vector_Verts.push_back(1000);
	vector_Colors.push_back(0); vector_Colors.push_back(0); vector_Colors.push_back(1);

	for (int i = 0; i < vector_Verts.size()/3; ++i)
		vector_Indices.push_back(i);

	vertsCount = vector_Indices.size();
}

void VAOManager::initVAO()
{
	generateArrays();
	m_vao = new QOpenGLVertexArrayObject(currentScene);
	m_vao->create();
	m_vao->bind();

	QOpenGLBuffer vertexBuffer;
	vertexBuffer.create();
	vertexBuffer.bind();
	vertexBuffer.allocate(vector_Verts.data(), vector_Verts.size()*sizeof(GLfloat));
	currentScene->getShaderProgram()->enableAttributeArray("vertex");
	currentScene->getShaderProgram()->setAttributeBuffer("vertex", GL_FLOAT, 0, 3);

	QOpenGLBuffer colorBuffer;
	colorBuffer.create();
	colorBuffer.bind();
	colorBuffer.allocate(vector_Colors.data(), vector_Colors.size()*sizeof(GLfloat));
	currentScene->getShaderProgram()->enableAttributeArray("color");
	currentScene->getShaderProgram()->setAttributeBuffer("color", GL_FLOAT, 0, 3);

	QOpenGLBuffer indexBuffer(QOpenGLBuffer::IndexBuffer);
	indexBuffer.create();
	indexBuffer.bind();
	indexBuffer.allocate(vector_Indices.data(), vector_Indices.size()*sizeof(GLuint));
	m_vao->release();
}

QOpenGLVertexArrayObject* VAOManager::getVAO()
{return m_vao;}

int VAOManager::getVertsCount()
{return vertsCount;}

VAOManager::~VAOManager()
{}
