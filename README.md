# PicoWlendar

A connected clock and calendar for the Pico W paired with the [Pico Inky Pack](https://shop.pimoroni.com/products/pico-inky-pack)

## Building

This application is written in C++ (or, at least, C); you will want to have a
normal Pico development environment in order to build it. I've included the
basic instructions for a Linux / Raspberry Pi / WSL type setup.

If you insist on using Windows, I think the steps are similar but you're mostly
on your own :-)


Install build requirements:

```bash
sudo apt update
sudo apt install cmake gcc-arm-none-eabi build-essential
```

And the Pico SDK:

```
git clone https://github.com/raspberrypi/pico-sdk
cd pico-sdk
git submodule update --init
export PICO_SDK_PATH=`pwd`
cd ../
```

The `PICO_SDK_PATH` set above will only last the duration of your session.

You should should ensure your `PICO_SDK_PATH` environment variable is set by `~/.profile`:

```
export PICO_SDK_PATH="/path/to/pico-sdk"
```

## Grab the Pimoroni libraries

```
git clone https://github.com/pimoroni/pimoroni-pico
```

## Clone this repository

```
git clone https://github.com/ahnlak/picowlendar
cd picowlendar
```

# Build!

```
mkdir build
cd build
cmake ..
make
```

## LICENSE

As I've leaned on Pimoroni's (rather outdated) template, I'm sticking to their provided
BSD 3-Clause License rather than my usual MIT one. It's pretty similar though; feel
free to use is as you see fit, credit is appreciated.

*Share and Enjoy*