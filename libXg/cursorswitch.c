/* Copyright (c) 1998 Lucent Technologies - All rights reserved. */
#include <u.h>
#include <libc.h>
#include <libg.h>
#include "libgint.h"

#include "../config.h"

#include <X11/cursorfont.h>

static Bitmap *bsrc, *bmask;
static Rectangle crect = { 0, 0, 16, 16 };

extern Window _topwindow;

static Cursor sweep;
static Cursor crosshair;
static Cursor pirate;
static Cursor watch;
static Cursor defcursor;

void
cursorswitch(unsigned int c)
{
    Cursor i = defcursor;

    switch (c){
        case SweepCursor:    i = sweep;     break;
        case BullseyeCursor: i = crosshair; break;
        case DeadCursor:     i = pirate;    break;
        case LockCursor:     i = watch;     break;
        default:             i = defcursor; break;
    }

    XDefineCursor(_dpy, _topwindow, i);
}

#ifndef DEFAULT_CURSOR
#define DEFAULT_CURSOR XC_left_ptr
#endif

void
initcursors(void)
{
    sweep = XCreateFontCursor(_dpy, XC_sizing);
    crosshair = XCreateFontCursor(_dpy, XC_crosshair);
    pirate = XCreateFontCursor(_dpy, XC_pirate);
    watch = XCreateFontCursor(_dpy, XC_watch);
    defcursor = XCreateFontCursor(_dpy, DEFAULT_CURSOR);
}

