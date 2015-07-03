#ifndef GLOBALCONTEXT
#define GLOBALCONTEXT

#include <QString>

static const unsigned int DATA_SIZE = 191;

//Column index in model
static const unsigned int GROUPS_INDEX = 0;
static const unsigned int NAME_INDEX = 1;
static const unsigned int VALUE_INDEX = 2;
static const unsigned int VALUE_NEW_INDEX = 3;
static const unsigned int TYPE_INDEX = 4;
static const unsigned int NOTE_INDEX = 5;
static const unsigned int TYPE_UNIT_INDEX = 6;

//Column index in conf_sat.txt
static const unsigned int GROUPS_FILE_INDEX = 0;
static const unsigned int NAME_FILE_INDEX = 1;
static const unsigned int TYPE_FILE_INDEX = 2;
static const unsigned int TYPE_UNIT_FILE_INDEX = 3;
static const unsigned int VALUE_FILE_INDEX = 4;
static const unsigned int NOTE_FILE_INDEX = 5;

//Starting position of each column in conf_sat.txt
static const unsigned int GROUP_START_INDEX = 0;
static const unsigned int PARAM_NAME_START_INDEX = 21;
static const unsigned int TYPE_START_INDEX = 62;
static const unsigned int TYPE_UNIT_START_INDEX = 79;
static const unsigned int PARAM_VALUE_START_INDEX = 90;
static const unsigned int NOTE_START_INDEX = 111;

//Starting length of each column in conf_sat.txt
static const int GROUP_LENGTH = 21;
static const int PARAM_NAME_LENGTH = 62- 21;
static const int TYPE_LENGTH =79- 62;
static const int TYPE_UNIT_LENGTH =90- 79;
static const int PARAM_VALUE_LENGTH =111- 90;
static const int NOTE_LENGTH = 0;

static const QString SAT_CONFIG_PATH = "conf_sat.txt";

static const QString SCC_STR = "SCC";
static const QString MPC_PL_STR = "MPC_PL";
static const QString MPC_AOCS_STR = "MPC_AOCS";
static const QString FDS_STR = "FDS";

#endif // GLOBALCONTEXT

