# MetaData

Is a small type library reconstructs [CastXML](https://github.com/CastXML/CastXML) files for use as meta information.

## Testing

The testing directory is setup to work with [googletest](https://github.com/google/googletest).
It contains the initial setup for testing this library as a standalone module using GitHub actions.

## Building

It builds with cmake, and it has been tested on Windows and Unix platforms using
the Visual Studio an Unix MakeFile cmake generators.

### Building with CMake and Make

```sh
mkdir build
cd build
cmake .. -DMetaData_BUILD_TEST=ON -DMetaData_AUTO_RUN_TEST=ON
make
```

### Optional defines

| Option                      | Description                                          | Default |
| :-------------------------- | :--------------------------------------------------- | :-----: |
| MetaData_BUILD_TEST         | Build the unit test program.                         |   ON    |
| MetaData_AUTO_RUN_TEST      | Automatically run the test program.                  |   OFF   |
| MetaData_USE_STATIC_RUNTIME | Build with the MultiThreaded(Debug) runtime library. |   ON    |
