#ifndef CAMERA_H
#define CAMERA_H
#include <QMatrix4x4>

class Camera
{
private:
	QMatrix4x4					projectionMatrix;
	QMatrix4x4					viewMatrix;

	QVector3D					position;
	QVector3D					view;
	QVector3D					up;

	int							width;
	int							height;
	int							depth;

	float						speed;

private:
	void				update();

public:
						Camera(int x, int y, int z, int width, int height, int depth);

	QMatrix4x4&			getProjectionMatrix();
	QMatrix4x4&			getViewMatrix();

	void				moveDown();
	void				moveUp();
	void				moveLeft();
	void				moveRight();
};

#endif // CAMERA_H
