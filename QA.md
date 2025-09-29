# Q&A Session 

## Q01: memory allocation pattern
Would you say it is good practice to allocate memory in the ISR, and free it in the work handler thread?

Loic: From memory, I've seen this pattern in certain drivers like network. <br/>
Andy: You can do that, but it's a recipe for trouble/memory leak.

Addendum: <br/>
I've checked the source. This pattern is indeed used in certain network and USB driver, like for example: [USB's Kinetis driver](https://github.com/zephyrproject-rtos/zephyr/blob/6eebe0acf081c1a363c02fe518222810f4022ae9/drivers/usb/udc/udc_kinetis.c)  <br/>
What make this patern challenging to use:
- Managing properly all possible paths for the alloc/free, especially when delayable work / cancellation is needed.
- Allocating memory in ISR is possible, but you need to choose a) an adequate memory pool, and b) you cannot wait: the timeout parameter must be set to K_NO_WAIT.

## Q02: System workqueue and managing the latency
The system workqueue is used by many drivers and subsystems, which introduces latency. Can it be monitored? What can we do about it?

Latency detection:
- During development, you can enable tracing and use tools like Percepio's tracealyzer or Segger SystemView to detect latency. 
- We don't have a runtime monitoring available out of the box in Zephyr. Of course, nothing prevents you to roll your own solution.

Mitigation:
- To avoid latency, you can create your own dedicated workqueues with thread priority of your choosing.
- If high performance / low latency is required, look at RTIO. RTIO is fairly new, so only a few drivers support it for now. But it is expected that more and more drivers will in the future. 

## Q03: Why Zephyr doesn't have a low/high priority system workqueue?
In some RTOS, we have a low and high priority system workqueue to deal with latency issues. Why does Zephyr only has one system qoekqueue?

I don't know what lead to that exact decision. But it's not restrictive, as you can create as many workqueues with the priority you want.

## Q04: In the demo, the deadline logging message is called in ISR!
No, it is not:
- the "whosh..." logging is happening in expiry_fn() function, which is the timer's callback. This is indeed running in interrupt context.
- the "deadline passing by" logging runs in the workqueue's thread, as shown in the logging.

## Q05: Using a sleep in the work handler is a bad practice, right?
Yes! You would delay the processing of other items! If you need this kind of feature, use **delayable work item** instead.

## Q06: Can I use floating point with the workqueue?
Workqueues have no way to pass the K_FP_REGS flag when creating the workqueue thread. 

Enabling CONFIG_FPU should be enough to get floating point working with workqueues. 


