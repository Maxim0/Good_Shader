#ifndef VAOMANAGER_H
#define VAOMANAGER_H

#include <QtOpenGL>

class GLScene;

class VAOManager
{
private:
	GLScene*						currentScene;
	QOpenGLVertexArrayObject*		m_vao;
	QVector<GLfloat>				vector_Verts;
	QVector<GLfloat>				vector_Colors;
	QVector<GLuint>					vector_Indices;
	int								vertsCount;

private:
	void						generateArrays();

public:
								VAOManager(GLScene* current);
								~VAOManager();
	void						initVAO();
	int							getVertsCount();
	QOpenGLVertexArrayObject*	getVAO();
};

#endif VAOMANAGER_H
