/******************************************************************************
 * Script Name   : Demoblaze_Modular_Workload
 * File Name     : util_random.c
 *
 * Description   :
 *   Randomization helpers used by workload model and business actions.
 *
 * Author        : ERX
 * Created Date  : 2026-02-21
 * Version       : 1.0.0
 *
 *****************************************************************************/

#include "workload.h"
#include <stdlib.h>
#include <time.h>

static int g_seeded = 0;

int rnd_int(int min_inclusive, int max_inclusive)
{
    int span;

    if (!g_seeded) {
        srand((unsigned)time(NULL));
        g_seeded = 1;
    }

    if (max_inclusive <= min_inclusive) {
        return min_inclusive;
    }

    span = (max_inclusive - min_inclusive) + 1;
    return min_inclusive + (rand() % span);
}

void think_random(int min_sec, int max_sec)
{
    int seconds = rnd_int(min_sec, max_sec);
    lr_think_time(seconds);
}
