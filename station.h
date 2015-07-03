#ifndef STATION_H
#define STATION_H

#include <QList>
#include <QModelIndex>


class Station
{
public:
    Station();
    ~Station();
    QModelIndex name_index;
    QList<QModelIndex> ciphering_keys_index;
};

#endif // STATION_H
