# Elementary Arithmetic Calculator
A simple implementation of calculator that does elementary arithmetic.

[TOC]

## Features
* Support for elementary arithmetic calculations (+ - * / and () )
* Some robustness. "- -3" and "+3" will render "3", and "1+ 2" will render "3"

## Build & Clean
* To build on Unix-like systems, just run ```make build```. The executable file ```calculator``` will appear in the directory where the code is.
* On Windows, you may want to use ```nmake``` bundled with Microsoft Visual Studio instead of ```make```. For more infomation please check [here](https://stackoverflow.com/questions/2532234/how-to-run-a-makefile-in-windows), or you may want to check out [Cygwin](http://www.cygwin.com/), [GnuWin](http://gnuwin32.sourceforge.net/) and [MinGW](http://www.mingw.org/).

To clean the generated object files (*.o files), please run ```make clean```.

## Notice
* Currently you may only perform one calculation per execution.
* Currently no exception handling is made. The calculator will check the syntax before calculation, but it will just **crash and force close** when an syntax error is detected.
* Feel free to open issues and make commits.

## License
This repository is available under [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html).
