Fork of [official](https://github.com/ftexchange/ftx) examples repository

### Building
To install dependencies project uses conan:

```bash
pip install conan
```

To install C++ deps:
```bash
cd build
conan install ..
```
To build project:

```bash
cmake ..
make
```

### Running
Built scripts can be founded at `build/bin/{{script_name}}`
```bash
./build/bin/ws_example
```