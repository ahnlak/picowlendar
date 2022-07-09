/*
 * main.cpp - part of PicoWlendar
 *
 * Copyright (C) 2022 Pete Favelle <rp2040@ahnlak.com>
 *
 * This file is distributed under the BSD 3-Clause License; see LICENSE for details.
 *
 * Entry point; where we find main() and supporting code.
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include "pico/time.h"
#include "pico/platform.h"

#include "common/pimoroni_common.hpp"

#include "picowlendar.hpp"

using namespace pimoroni;

int main() {

  stdio_init_all();

  sleep_ms(500);

  printf("\n\n=======\nPicowlendar starting up\n\n");

  display_init();
  display_update();


}

/* End of main.cpp */
