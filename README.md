# MetaData

Is a small type library reconstructs [CastXML](https://github.com/CastXML/CastXML) files for use as meta information.

## Testing

The Test directory is setup to work with [googletest](https://github.com/google/googletest).

## Building

![A1](https://github.com/chcly/Module.MetaData/actions/workflows/build-linux.yml/badge.svg)
![A2](https://github.com/chcly/Module.MetaData/actions/workflows/build-windows.yml/badge.svg)

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
