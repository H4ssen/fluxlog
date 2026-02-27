# fluxlog — High Performance C++ Logging Library

## Overview

fluxlog is a lightweight and extensible C++ logging library
designed with modern C++ principles and clean architecture.

It supports:

- Log levels
- Custom formatters
- Multiple sinks
- Extensible design
- Easy integration

---

## Architecture

The project follows:

- Facade Pattern (Logger)
- Strategy Pattern (Formatter + Sink)
- Layered Architecture

---

## Build Instructions

```bash
mkdir build
cd build
cmake ..
make