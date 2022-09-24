Fork of [official](https://github.com/ftexchange/ftx) examples repository

### TO-DO

Must start downloading data from an arbitrary point in time, following the next algorithm:
1. Write a message about the launch to the logs in the `logs` folder
2. Create a file for the current data, called `dd-mm-yyyy`. *!*Each *new* file should start with a snapshot of the orderbook.
3. Record incoming updates to the file before the occurrence of stopping events
4. When an error occurs, write its text to the telegram and log the error message and stop the download
5. At the onset of 23:59:59 begin with step 1)


### Building
To install dependencies project uses [conan](https://github.com/conan-io/conan):

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