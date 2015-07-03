#ifndef SATCONFIGFILESAVE_H
#define SATCONFIGFILESAVE_H

#include <QTextStream>

class SatConfigFileSave
{
public:
    SatConfigFileSave();
    ~SatConfigFileSave();

    void saveSatConfig();

private:
    uint const group_start_index = 0;
    uint const param_name_start_index = 21;
    uint const type_start_index = 62;
    uint const type_unit_start_index = 79;
    uint const param_value_start_index = 90;
    uint const note_start_index = 111;
};


#endif // SATCONFIGFILESAVE_H
