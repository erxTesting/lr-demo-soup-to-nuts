/******************************************************************************
 * Script Name   : Demoblaze_Modular_Workload
 * File Name     : workload.h
 *
 * Description   :
 *   Central header for the demo script. Keeps:
 *   - Standard LoadRunner includes in one place
 *   - Workload configuration knobs (weights, think times)
 *   - Script metadata (name/version/date/owner)
 *   - Function prototypes (so files stay decoupled and readable)
 *
 * Author        : ERX
 * Created Date  : 2026-02-21
 * Version       : 1.0.0
 *
 * Revision History
 * ---------------------------------------------------------------------------
 * Date         Version   Author        Description
 * ---------------------------------------------------------------------------
 * 2026-02-21   1.0.0     ERX           Initial version
 *
 *****************************************************************************/

#ifndef WORKLOAD_H
#define WORKLOAD_H

/* Script Metadata (Version Stamping) */
#define SCRIPT_NAME        "Demoblaze_Modular_Workload"
#define SCRIPT_VERSION     "1.0.0"
#define SCRIPT_CREATED     "2026-02-21"
#define SCRIPT_OWNER       "Performance Engineering (Training Repo)"

/* Standard LoadRunner Includes */
#include "lrun.h"
#include "globals.h"
#include "web_api.h"
#include "lrw_custom_body.h"

/* Configuration Knobs */
#define BASE_URL            "https://api.demoblaze.com"
#define THINK_MIN_SEC       1
#define THINK_MAX_SEC       4

/* Workload Weights (relative, not percentages) */
#define W_BROWSE            50
#define W_VIEW              30
#define W_ADD_TO_CART       15
#define W_LOGIN             5

/* Iteration Control */
#define STEPS_PER_ITER_MIN  2
#define STEPS_PER_ITER_MAX  6

/* Public Workload API */
int WL_Init(void);
int WL_RunIteration(void);
int WL_End(void);

/* Business Actions */
int BA_Browse(void);
int BA_ViewProduct(void);
int BA_AddToCart(void);
int BA_Login(void);

/* Utility Functions */
int  rnd_int(int min_inclusive, int max_inclusive);
void think_random(int min_sec, int max_sec);

#endif
