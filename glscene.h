#ifndef GLSCENE_H
#define GLSCENE_H
#include <QGLWidget>
#include <QGLShader>
#include <QGLShaderProgram>
#include "vaomanager.h"
#include "camera.h"
class GLScene: public QGLWidget
{
private:
	VAOManager					m_VAOmanager;

	Camera						cam;

	int							WIDTH;
	int							HEIGHT;
	float						angle;
	float						translation;

	QBasicTimer					timer;

	QMatrix4x4					modelMatrix;

	QGLShader*					vShader;
	QGLShader*					fShader;
	QGLShaderProgram*			shaderProgram;

	GLfloat						x_Rotate;
	GLfloat						y_Rotate;

private:
	void				initShaders();
	void				updateModel();

public:
						GLScene(QWidget *parent = 0);

	void				paintGL();
	void				initializeGL();
	void				resizeGL(int w, int h);

	void				keyPressEvent(QKeyEvent *e);
	void				timerEvent(QTimerEvent *e);

	QGLShaderProgram*	getShaderProgram();

};

#endif // GLSCENE_H
