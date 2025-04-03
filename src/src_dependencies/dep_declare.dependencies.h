#if defined(__linux__)
#include <sys/wait.h>
#endif

#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>


#if !defined(cJSON__h) && !defined(CHASH_MANIPULATOR_MOCK_CJSON)
#include "../../dependencies/cJSON.h"
#define CHASH_MANIPULATOR_CJSON_DECLARATED
#endif

#if !defined(CTextEngine_fdeclare) && !defined(CHASH_MANIPULATOR_MOCK_CTEXT_ENGINE)
#include "../../dependencies/CTextEngine.h"
#define CHASH_MANIPULATOR_CTEXT_ENGINE_DECLARATED
#endif