# Elementary Arithmetic Calculator
A simple implementation of calculator that does elementary arithmetic.

## Features
* Support for elementary arithmetic calculations (+ - * / and () )
* Some robustness. "- -3" and "+3" will render "3", and "1+ 2" will render "3"
* You can perform multiple calculations per execution. To quit, give an empty expression.
* You will get notified whenever there is an error, and you can continue yo your next expression.

## Build & Clean
* To build on Unix-like systems, just run ```make build```. The executable file ```calculator``` will appear in the directory where the code is.
* On Windows, you may want to use ```nmake``` bundled with Microsoft Visual Studio instead of ```make```. For more infomation please check [here](https://stackoverflow.com/questions/2532234/how-to-run-a-makefile-in-windows), or you may want to check out [Cygwin](http://www.cygwin.com/), [GnuWin](http://gnuwin32.sourceforge.net/) and [MinGW](http://www.mingw.org/).

To clean the generated object files (*.o files), please run ```make clean```.

## Notice
* Feel free to open issues and make commits.

## License
This repository is available under [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.en.html).
