# Zephyr Workqueues- How they Work and Queue 
<img src="https://www.doulos.com/media/1009/doulos-logo-header.svg" alt="Doulos" style="width: 150px;" align="right"/>

Presenter: **Loïc Domaigné** at OSS'25 in Amsterdam<br/>
Senior Members Technical Staff, Doulos <br/>
25<sup>th</sup> August 2025

Recording: [available on Youtube](https://www.youtube.com/watch?v=SG3NSGGrUdk) <br/>
Slides   : [available on Sched](https://osseu2025.sched.com/event/25Vmf/zephyr-workqueues-how-they-work-and-queue-loic-domaigne-doulos-gmbh)

## Code Samples

| demo      |  description   |
|:----------|:---------------|
| demo-v0.1 | simple timer, see talk |
| demo-v0.2 | adding sleep, see talk |
| demo-v0.3 | using system workqueue, see talk |
| demo-v0.4 | submit work item twice in a row (only the first is processed) |
| demo-v0.5 | example how to pass data to work handler using atomic type |
| demo-v0.6 | like demo-v0.5, but with delayable work. Similar pattern for cancellation |

## Q&A Session

We didn't had a mic for the Q&A session. You'll find a transcript below, with some addendums including the Q&A that occurred
post-talk.

- [Q01: memory allocation pattern](QA.md#q01-memory-allocation-pattern)
- [Q02: system workqueue and managing the latency](QA.md#q02-system-workqueue-and-managing-the-latency)
- [Q03: Why Zephyr doesn't have a low/high priority system workqueue?](QA.md#q03-why-zephyr-doesnt-have-a-lowhigh-priority-system-workqueue)
- [Q04: In the demo, the deadline logging message is called in ISR!](QA.md#q04-in-the-demo-the-deadline-logging-message-is-called-in-isr)
- [Q05: Using a sleep in the work handler is a bad practice, right?](QA.md#q05-using-a-sleep-in-the-work-handler-is-a-bad-practice-right)
- [Q06: Can I use floating point with the workqueue?](QA.md#q06-can-i-use-floating-point-with-the-workqueue)

## 📚 Looking for training?

Looking to find out if Zephyr could be a great fit for your next product? Or looking to upskill your teams with Zephyr?
Check-out our [Doulos Zephyr Essentials](https://www.doulos.com/training/arm-and-embedded-software/rtos/zephyr-essentials/)

This training will help you maximise the potential of Zephyr for developing embedded products and get project ready in
record time 😄 We offer both public and team-based events, live online or in-persons.

💬 Contact a [Doulos Representative](https://forms.doulos.com/enquiry?url=%2ftraining%2farm-and-embedded-software%2frtos%2fzephyr-essentials%2f&title=Zephyr%20Essentials)

## Trivia
**Yesternight** This is an archaic word derived from old English, which means "last night". We had a gathering on Sunday prior
to the event, where we happen to discuss the work *yesteryear* and wondered about the yester suffix and its use.
We joked about placing one one of this "yester"-word in our talks...
