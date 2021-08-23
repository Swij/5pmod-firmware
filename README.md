# 5PMOD board firmware

## Quick start
0. Initialize and update dependencies using West
1. Load Zephyr toolchain
2. Navigate to the correct application 
3. Use West to build and flash firmware

```
# Initial repository setup
#   Warning! Make sure that the parent folder is empty,
#   West will clone a bunch of repositories to the parent folder. 
west init -l .
west update

# Build and flash application
. ../zephyr/zephyr-env.sh
cd blinky
west build -b 5pmod_nrf52840
west flash --softreset
```

## Visual Studio Code integration
### Compilation database and intelligent code completion (IntelliSense)
Intellisense can be enabled by installing the [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) extension and configuring it correctly.

The `c_cpp_properties.json` contains the [IntelliSense settings](https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference). Each application should have its own configuration. The easiest way to get the correct configuration for an application is to set the `compileCommands` config option to the applications `compile_commands.json` file path.

For IntelliSense to work correctly you must also select the correct configuration for the application you are viewing. To select a configuration, make sure you have a .c/.h file open from the application. The easiest way to pick configuration is to press the C/C++ extension button in the bottom right corner of the editor (it shows the name of the currently selected configuration).

### Tasks
**Run Build Task** (`Ctrl+Shift+B`) runs the default build task.

To run a task press **Quick Open** (`Ctrl+P`) type 'task', `Space` and then select the task.

A quicker way to run tasks is to add a keybinding (e.g. `Ctrl+Shift+R`) to the command `workbench.action.tasks.runTask` 

It is also possible add keybindings to run specific tasks, this is done by adding the task name to the `args` field in the keybinding.

### Debugging

### Tips and tricks
Install the [CMake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake) extension to get syntax highlighting and code completion in CMake files. 

Install the [ShellCheck](https://marketplace.visualstudio.com/items?itemName=timonwong.shellcheck) extension for amazing shell script linting.

Install the [DeviceTree](https://marketplace.visualstudio.com/items?itemName=plorefice.devicetree) extension to get syntax highlighting in .dts files.

Add `"files.associations": {"*.overlay": "dts"}` to your settings.json for devicetree syntax highlighting in overlay files. 
