#pragma once

#include "SignatureVersionGetter.h"

bool check_version() {
	return get_version_local() != get_version_online();
}