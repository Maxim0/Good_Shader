#include "camera.h"
#include <QDebug>

Camera::Camera(int x, int y, int z, int width, int height, int depth)
	:position(x,y,z), view(0,0,0), up(0,1,0), width(width), height(height), depth(depth), speed(5)
{
	update();
}

void Camera::update()
{
	projectionMatrix.setToIdentity();
	projectionMatrix.ortho(-width/2., width/2., -height/2., height/2., -depth/2., depth/2.);

	viewMatrix.setToIdentity();
	viewMatrix.lookAt(position, view, up);
}

void Camera::moveLeft()
{
	position.setX(position.x()-speed);
	view.setX(view.x()-speed);
	update();
}

void Camera::moveRight()
{
	position.setX(position.x()+speed);
	view.setX(view.x()+speed);
	update();
}

void Camera::moveUp()
{
	position.setY(position.y()+speed);
	view.setY(view.y()+speed);
	update();
}

void Camera::moveDown()
{
	position.setY(position.y()-speed);
	view.setY(view.y()-speed);
	update();
}

QMatrix4x4& Camera::getProjectionMatrix()
{
	return projectionMatrix;
}

QMatrix4x4& Camera::getViewMatrix()
{
	return viewMatrix;
}
