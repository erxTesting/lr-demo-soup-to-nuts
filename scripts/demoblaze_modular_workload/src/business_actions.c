/******************************************************************************
 * Script Name   : Demoblaze_Modular_Workload
 * File Name     : business_actions.c
 *
 * Description   :
 *   Business actions (BA_*):
 *   - Each BA_* represents a business intent
 *   - Each BA_* should contain exactly one transaction
 *
 * Author        : ERX
 * Created Date  : 2026-02-21
 * Version       : 1.0.0
 *
 *****************************************************************************/

#include "workload.h"

static const char* CATS[] = { "phone", "notebook", "monitor" };
static const int   CAT_COUNT = 3;

static const char* DEMO_USERS[][2] = {
    { "demo", "demo" },
    { "test", "test" },
    { "performance", "performance" }
};
static const int DEMO_USER_COUNT = 3;

int BA_Browse(void)
{
    int idx = rnd_int(0, CAT_COUNT - 1);
    lr_save_string(CATS[idx], "p_cat");

    lr_start_transaction("BA_Browse");

    web_custom_request("entries",
        "URL=" BASE_URL "/entries",
        "Method=POST",
        "Resource=0",
        "EncType=application/json",
        "Body={\"cat\":\"{p_cat}\"}",
        LAST);

    lr_end_transaction("BA_Browse", LR_AUTO);
    return 0;
}

int BA_ViewProduct(void)
{
    int pid = rnd_int(1, 15);
    lr_save_int(pid, "p_pid");

    lr_start_transaction("BA_ViewProduct");

    web_custom_request("view",
        "URL=" BASE_URL "/view",
        "Method=POST",
        "Resource=0",
        "EncType=application/json",
        "Body={\"id\":\"{p_pid}\"}",
        LAST);

    lr_end_transaction("BA_ViewProduct", LR_AUTO);
    return 0;
}

int BA_AddToCart(void)
{
    int pid = rnd_int(1, 15);
    int uid = rnd_int(10000, 99999);

    lr_save_int(pid, "p_pid");
    lr_save_int(uid, "p_uid");

    lr_start_transaction("BA_AddToCart");

    web_custom_request("addtocart",
        "URL=" BASE_URL "/addtocart",
        "Method=POST",
        "Resource=0",
        "EncType=application/json",
        "Body={\"id\":\"{p_pid}\","
             "\"cookie\":\"user={p_uid}\","
             "\"prod_id\":{p_pid},"
             "\"flag\":true}",
        LAST);

    lr_end_transaction("BA_AddToCart", LR_AUTO);
    return 0;
}

int BA_Login(void)
{
    int idx = rnd_int(0, DEMO_USER_COUNT - 1);
    lr_save_string(DEMO_USERS[idx][0], "p_user");
    lr_save_string(DEMO_USERS[idx][1], "p_pass");

    lr_start_transaction("BA_Login");

    web_custom_request("login",
        "URL=" BASE_URL "/login",
        "Method=POST",
        "Resource=0",
        "EncType=application/json",
        "Body={\"username\":\"{p_user}\",\"password\":\"{p_pass}\"}",
        LAST);

    lr_end_transaction("BA_Login", LR_AUTO);
    return 0;
}
