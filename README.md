# ysvb-bug-proof

This project consists mainly of a set of general purpose compile time activatable macros that create log file alerts in case of run time tests (set in coding time) occur.

It is the only of its category (to the author's knowledge) that not only logs the error message, but also indicates the operation that operands were expected to have. Example:

`YSVB_CHECK_1(m_status, ==, MyClass::Status::case_xyz, "The only possible way that this line happen to be executed is case xyz to have happened")`

In this example, programmer believes that there is no possible way that a particular block of code is reached by the program flow but a given _xyz_ situation. This is a typical good usage case for the YSVB_CHECK_1 macro, because it actually check out whether or not the programmer conception is well defined and properly expressed in the code, for any of those does not hold, a log message of that error case will flag what was the actual value m_status. Notice that this YSVB_CHECK's can also be used as a documentation tool, for it registers in an organized and clear way what are the expectations for each excerpt of the code.

The advantage of this in comparison with running the program in the step by step mode is that an investigation of a very long execution is made easier. Looking for the error, is made as simple as a search with Ctrl+F in the execution log.
