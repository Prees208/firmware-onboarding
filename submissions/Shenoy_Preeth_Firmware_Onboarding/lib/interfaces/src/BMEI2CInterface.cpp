#include "BMEI2CInterface.h"

// Definition of the singleton instance required by etl::singleton
template <>
BMEI2CInterface& etl::singleton<BMEI2CInterface>::instance() {
    static BMEI2CInterface instance;
    return instance;
}