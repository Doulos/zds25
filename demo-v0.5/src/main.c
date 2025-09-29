/****************************************************************************
 * DEMO CODE / "Zephyr Workqueues. How they work and queue"
 ****************************************************************************
 * Copyright (c) 2025 by Doulos
 * Author : Loic Domaigne
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Demo code shown during Loic's talk at the Zephyr Developer Summit in 
 * Amsterdam. 
 ****************************************************************************/

/*================================================*
 * version 0.5- Passing data to work handler
 *================================================*/
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define DEMO_VERSION "0.5"
#define DEMO_DURATION 12

LOG_MODULE_REGISTER(demo);


/**
 * Timer expiry function 
 */

struct ctx_data {
    atomic_t counter;
    struct k_work work;
};

struct ctx_data ctx;

void expiry_fn(struct k_timer *t) {
    static uint32_t counter=0;
    atomic_set(&ctx.counter, counter);
    LOG_INF("whhoossshh %02u",counter);
    if (counter>0 && (counter%8==0)) {
        k_work_submit(&ctx.work);
    }
    counter++;
}

void deadline_passing_by(struct k_work *w) {
    // Pause 500 ms before/after logging
    // This should infuse an element of "drama" and "suspens"
    // to capture the audience
    struct ctx_data *ctx = CONTAINER_OF(w, struct ctx_data, work);
    k_msleep(500);
    LOG_WRN("deadlines passing by... (missed %02u of those)", atomic_get(&ctx->counter));
    k_msleep(500);
}


/**
 * define a timer with expiry_fn and stop_fn as expiry/time function resp.
 * you can either use the K_TIMER_DEFINE macro, or
 * a struct k_timer initialized with k_timer_init() 
 */
K_TIMER_DEFINE(timer0, expiry_fn, NULL);

int main()
{
    LOG_WRN("Running demo v" DEMO_VERSION);

    /* initialize work item */
    k_work_init(&ctx.work, deadline_passing_by);

    /*
     * timer should fire the first time after 1 second, then every 250 msec
     */
    k_timer_start(&timer0, K_SECONDS(1), K_MSEC(250));

    /*
     * stop the demo after DEMO_DURATION seconds
     */
    k_sleep(K_SECONDS(DEMO_DURATION));
    k_timer_stop(&timer0);
    LOG_INF("bye for now!");
}
