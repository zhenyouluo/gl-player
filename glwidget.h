#include <QGLWidget>

class VisFrame;

class GLWidget : public QGLWidget
{
	Q_OBJECT
public:
	GLWidget(QWidget *parent = NULL);
	~GLWidget();

	void rotateY(double dy);

	void setVisFrame(VisFrame *f);

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void updateScene();

	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);

signals:
	void needsUpdate();

private:
	double xRot, yRot, zRot;
	VisFrame *scene;

	QPoint clickPoint;
};

