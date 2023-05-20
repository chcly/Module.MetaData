# MetaData

Is a small type library reconstructs [CastXML](https://github.com/CastXML/CastXML) files for use as meta information.

## Testing

The Test directory is setup to work with [googletest](https://github.com/google/googletest).

## Building

Building with CMake and Make.

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
