/******************************************************************************
 * Script Name   : Demoblaze_Modular_Workload
 * File Name     : workload.c
 *
 * Description   :
 *   Workload model "brain":
 *   - chooses actions based on weights
 *   - runs multiple steps per iteration (session-like behavior)
 *   - enforces think time pacing
 *
 * Author        : ERX
 * Created Date  : 2026-02-21
 * Version       : 1.0.0
 *
 *****************************************************************************/

#include "workload.h"

static int pick_weighted_action(void)
{
    int total = W_BROWSE + W_VIEW + W_ADD_TO_CART + W_LOGIN;
    int roll  = rnd_int(1, total);
    int acc   = 0;

    acc += W_BROWSE;
    if (roll <= acc) return 1;

    acc += W_VIEW;
    if (roll <= acc) return 2;

    acc += W_ADD_TO_CART;
    if (roll <= acc) return 3;

    return 4;
}

int WL_Init(void)
{
    lr_output_message(
        "Starting script: %s | Version: %s | Created: %s | Owner: %s",
        SCRIPT_NAME, SCRIPT_VERSION, SCRIPT_CREATED, SCRIPT_OWNER
    );

    web_set_sockets_option("SSL_VERSION", "AUTO");
    web_set_max_html_param_len("1048576");
    web_add_auto_header("Content-Type", "application/json");

    return 0;
}

int WL_RunIteration(void)
{
    int steps = rnd_int(STEPS_PER_ITER_MIN, STEPS_PER_ITER_MAX);
    int i, which, rc;

    for (i = 0; i < steps; i++) {
        which = pick_weighted_action();

        switch (which) {
        case 1: rc = BA_Browse(); break;
        case 2: rc = BA_ViewProduct(); break;
        case 3: rc = BA_AddToCart(); break;
        case 4:
        default: rc = BA_Login(); break;
        }

        if (rc != 0) {
            lr_error_message("Business action failed. which=%d rc=%d", which, rc);
        }

        think_random(THINK_MIN_SEC, THINK_MAX_SEC);
    }

    return 0;
}

int WL_End(void)
{
    web_revert_auto_header("Content-Type");
    return 0;
}
