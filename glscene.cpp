#include "glscene.h"
#include <QDebug>

GLScene::GLScene(QWidget* parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
	m_VAOmanager(this), cam(0,0,100, 400,400,1000), angle(0), translation(0)
{
	QGLFormat frmt;
	frmt.setSwapInterval(0);
	setFormat(frmt);
	setFocusPolicy(Qt::StrongFocus);
	timer.start(100, this);
}

void GLScene::initShaders()
{
	vShader = new QGLShader(QGLShader::Vertex);
	vShader->compileSourceCode(
				"attribute vec3 vertex;\n"
				"attribute vec4 color;\n"
				"uniform mat4 projectionMatrix;\n"
				"uniform mat4 viewMatrix;\n"
				"uniform mat4 modelMatrix;\n"
				"varying vec4 f_color;\n"
				"void main()\n"
				"{\n"
				"   gl_Position = projectionMatrix * viewMatrix * modelMatrix *  vec4(vertex,1);\n"
				"   "
				"   f_color = color;\n"
				"}\n");

	fShader = new QGLShader(QGLShader::Fragment);
	fShader->compileSourceCode(
				"varying vec4 f_color;\n"
				"void main()\n"
				"{\n"
				"   gl_FragColor = f_color;\n"
				"}\n");

	shaderProgram = new QGLShaderProgram(this->context());
	shaderProgram->addShader(vShader);
	shaderProgram->addShader(fShader);

	shaderProgram->link();
}

void GLScene::initializeGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	initShaders();
	m_VAOmanager.initVAO();
}

void GLScene::resizeGL(int w, int h)
{
	if(h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	updateGL();
}

void GLScene::paintGL()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	shaderProgram->bind();
		shaderProgram->setUniformValue("projectionMatrix", cam.getProjectionMatrix());
		shaderProgram->setUniformValue("viewMatrix", cam.getViewMatrix());
		shaderProgram->setUniformValue("modelMatrix", modelMatrix);

		m_VAOmanager.getVAO()->bind();
			glDrawElements(GL_LINES, m_VAOmanager.getVertsCount(), GL_UNSIGNED_INT, 0);
		m_VAOmanager.getVAO()->release();
	shaderProgram->release();
}


void GLScene::timerEvent(QTimerEvent *e)
{
	if (e->timerId() == timer.timerId())
	{
		updateModel();
	}
}

void GLScene::updateModel()
{
	modelMatrix.setToIdentity();
	modelMatrix.rotate(x_Rotate, 1, 0, 0);
	modelMatrix.rotate(y_Rotate, 0, 1, 0);
	updateGL();
}

void GLScene::keyPressEvent(QKeyEvent *e)
{
	switch (e->key())
	{
		case Qt::Key_Left: cam.moveLeft(); break;
		case Qt::Key_Right: cam.moveRight(); break;
		case Qt::Key_Up: cam.moveUp(); break;
		case Qt::Key_Down: cam.moveDown(); break;

		case Qt::Key_W: ++y_Rotate; break;
		case Qt::Key_S: --y_Rotate; break;
		case Qt::Key_A: --x_Rotate; break;
		case Qt::Key_D: ++x_Rotate; break;
	}
	updateGL();
}

QGLShaderProgram* GLScene::getShaderProgram()
{
	return shaderProgram;
}
