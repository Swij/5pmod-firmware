# 5PMOD board firmware

## Quick start
0. Initialize and update dependencies using West
1. Load Zephyr toolchain
2. Navigate to the correct application 
3. Use West to build and flash firmware

```
# Initial repository setup
cd ..
west init -l 5pmod-firmware
west update
cd 5pmod-firmware

# Build and flash application
. ../zephyr/zephyr-env.sh
cd example_app
west build -b 5pmod_nrf52840
west flash --softreset
```
