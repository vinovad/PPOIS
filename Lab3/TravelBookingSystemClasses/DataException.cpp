#include "DataException.h"

DataException::DataException()
    : std::runtime_error("Data NOT valid") {}