#ifndef UIController_H
#define UIController_H

#include <QObject>

class UIController : public QObject
{
    Q_OBJECT
public:
    explicit UIController(QObject *parent = 0);

signals:

public slots:
};

#endif // UIController_H
