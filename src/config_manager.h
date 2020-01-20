#include <iostream>
#include <fstream>
#include <QObject>

// Forward Declarations of Functions
class config_manager : public QObject
{
    Q_OBJECT
public slots:
    explicit config_manager (QObject* parent = 0) : QObject(parent){}
 Q_INVOKABLE    bool generateConfigFile( void );
 Q_INVOKABLE    bool sendConfigFile( void );
 Q_INVOKABLE    bool getConfigFile( void );
};
