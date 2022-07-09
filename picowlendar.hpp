/*
 * picowlendar.hpp - part of PicoWlendar
 *
 * Copyright (C) 2022 Pete Favelle <rp2040@ahnlak.com>
 *
 * Prototypes and constants for the project.
 *
 */

#pragma once

/* Constants. */

#define DISPLAY_WIDTH   296
#define DISPLAY_HEIGHT  128


/* Function prototypes. */

bool display_init( void );
bool display_update( void );


/* End of picowlendar.hpp */
