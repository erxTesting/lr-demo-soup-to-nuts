/******************************************************************************
 * File Name     : vuser_end.c
 * Description   : Called once per Vuser at shutdown.
 *****************************************************************************/

#include "workload.h"

vuser_end()
{
    return WL_End();
}
