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
