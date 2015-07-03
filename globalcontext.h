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

//Column index in conf_sat.txt
static const unsigned int GROUPS_FILE_INDEX = 0;
static const unsigned int NAME_FILE_INDEX = 1;
static const unsigned int TYPE_FILE_INDEX = 2;
static const unsigned int TYPE_UNIT_FILE_INDEX = 3;
static const unsigned int VALUE_FILE_INDEX = 4;
static const unsigned int NOTE_FILE_INDEX = 5;

static const QString sat_config_path = "conf_sat.txt";

static const QString scc_str = "SCC";
static const QString mpc_pl_str = "MPC_PL";
static const QString mpc_aocs_str = "MPC_AOCS";
static const QString fds_str = "FDS";

#endif // GLOBALCONTEXT

