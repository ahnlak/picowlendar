/*
 * display.cpp - part of PicoWlendar
 *
 * Copyright (C) 2022 Pete Favelle <rp2040@ahnlak.com>
 *
 * This file is distributed under the BSD 3-Clause License; see LICENSE for details.
 *
 * We keep all display-related stuff in one place, in case the underlying
 * drivers have to change.
 */

#include "pico_graphics.hpp"
#include "uc8151.hpp"

#include "picowlendar.hpp"

using namespace pimoroni;


/* Module variables. */

static PicoGraphics_Pen1BitY *mGraphics;
static UC8151                *mDisplayDriver;


/* Functions. */

bool display_init( void )
{
  /* Create the display driver and graphics engine. */
  mGraphics = new PicoGraphics_Pen1BitY( DISPLAY_WIDTH, DISPLAY_HEIGHT, nullptr );
  mDisplayDriver = new UC8151( DISPLAY_WIDTH, DISPLAY_HEIGHT, Rotation::ROTATE_0 );

  /* Initial state, make sure we have a blank screen with a border. */
  Rect lBox( 0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT );
  mGraphics->set_pen( 0, 0, 0 );
  mGraphics->rectangle( lBox );
  lBox.deflate( 1 );
  mGraphics->set_pen( 255, 255, 255 );
  mGraphics->rectangle( lBox );

  /* All good. */
  return true;
}

bool display_update( void )
{
  /* Ask the display driver to update itself. */
  mDisplayDriver->update( mGraphics );

  /* All good. */
  return true;
}


/* End of file display.cpp */
