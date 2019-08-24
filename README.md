# linked-list

Linked list implementation written in C. Documentation is currently [linkedlist.h](linkedlist.h). You can also look in the [tests](test.c) script to see some examples.

# Build and install

To build and install the linkedlist library (and the tests), run
```bash
autoreconf -if
./configure
make
# will probably require sudo
make install
```

# Tests

The tests are all in [tests.c](tests.c). They are built into an executable **tests** 
along with the linked list library when you run `make`. To run the tests, just run that executable

```bash
./tests
```

The output of the tests script isn't very useful right now. It's basically a bunch of function calls riddled with assert statments and a few `printf` calls to make things more visible.
