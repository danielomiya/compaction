# compaction

An C-language application with the implementation of [these requirements](docs/EP___Alg1.pdf).

## Contributors

- Daniel Omiya - 41995449
- Hugo Amorim - 41991184
- Nicole Martins - 41990277

## Built with

- C/C++ languages
- Catch2 (for unit tests)
- CMake
- Docker

## Project structure

- app: application's entry point;
- includes: headers used through the app;
- src: library implementation; and
- tests: unit tests written in C++.

## How to run it

Just docker it (`Makefile` included).

    make dev ALGORITHM=prog WORD=aaabbb

### Locally

    make clean build
    ./build/app/main [algorithm] [word?]

## How to test it

`Makefile` also has a target for our unit tests.

    make test

---

That's all folks!
