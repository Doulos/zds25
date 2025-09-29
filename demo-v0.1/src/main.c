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
 * version 0.1- Simple Timer                      *
 *================================================*/
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define DEMO_VERSION "0.1"
#define DEMO_DURATION 12

LOG_MODULE_REGISTER(demo);

/**
 * Timer expiry function 
 */
void expiry_fn(struct k_timer *t) {
    static uint32_t counter=0;
    LOG_INF("whhoossshh %02u",counter);
    if (counter>0 && (counter%8==0)) {
        LOG_WRN("deadlines passing by");
    }
    counter++;
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
