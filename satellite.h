#ifndef SATELLITE_H
#define SATELLITE_H

#include <QList>
#include <QModelIndex>


class Satellite
{
public:
    Satellite();
    ~Satellite();
    QModelIndex name_index;
    QList<QModelIndex> mission_constraints_name;
    QList<QModelIndex> system_constraints_name;
    QList<QModelIndex> mission_constraints_value;
    QList<QModelIndex> system_constraints_value;
};

#endif // SATELLITE_H
