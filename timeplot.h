#include <QtGui>

class TimePlot : public QDockWidget
{
	Q_OBJECT

public:
	TimePlot(QWidget *parent = NULL);
	~TimePlot();

	void loadData(std::vector<float> data);
	void clear();

	void resizeGraphicsViewToFit();

	void setZeroFrame(int i);
	void setEpsilonCoeff(float x);

public slots:
	void moveCurrentMark(int val);

protected:
	virtual void resizeEvent(QResizeEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual QSize sizeHint() const;
	virtual void paintEvent(QPaintEvent *event);

private:
	void hideCurrentMark();
	void configureGrid();
	void buildMarksList(qreal begin, qreal end, int nMax, std::vector<qreal> &res);
	qreal mapFrameToX(int i);

private:
	QGraphicsScene *graphicsScene;
	QGraphicsView *graphicsView;

	QGraphicsRectItem *currentMark;
	bool currentMarkVisible;

	std::vector<float> data;
	float data_max;

	int leftMargin;
	int topMargin;
	int rightMargin;
	int bottomMargin;

	std::vector<QGraphicsLineItem *> xGrid;
	std::vector<QGraphicsLineItem *> yGrid;
	std::vector<qreal> xGridList;
	std::vector<qreal> yGridList;

	int zeroFrame;
	float epsilonCoeff;
};

