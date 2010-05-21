#include <QDockWidget>
#include <QTextEdit>
#include <QLabel>

class CommentDock : public QDockWidget
{
public:
	CommentDock(QWidget *parent = NULL);

	void setText(QString s);

protected:
	virtual QSize sizeHint() const;

private:
	QLabel *widget;
};
