# Password Generator
A prototype to try out gtk and python embedding into c++

## Building
```
cd src; \
gcc -lpython3.12 $(pkg-config --cflags --libs gtk+-3.0 python3) py_interface.cpp main.cpp
```
