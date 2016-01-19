# Introduction #
**This is a work in progress**

This page is for a 4 channel bipolar output, motor controller. The controller will be capable of receiving commands via I2C, RS232 (5v) and SPI. The basic premise of the design is to make a single modular digital interface to various DC motors.

## Parts Selection ##
This design will most likley use one of the newer 16F pics as they are super cheap and contain the MSSP module necessary for easy I2C slave implementation. A Freescale MC33926 has been chosen as the motor driver. This allows 5A of current (most likely ~3A in this depending on heat sinking). Additionally, it has many integrated safety features that protect against short circuits and inductive kick.


# Details #

Add your content here.  Format your content with:
  * Text in **bold** or _italic_
  * Headings, paragraphs, and lists
  * Automatic links to other wiki pages