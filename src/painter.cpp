/*
 * Copyright (c) 2020, the SerenityOS developers.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
* A breakout clone for Serenity
* My first time coding in CPP (using some tutorials) and i will to contribute to Serenity.
* Hope it's working ! 
* - WouJy
*/

#include "painter.hpp"
#include "glut.h"

void Painter::bar(int x1, int y1, int x2, int y2)
{
  glBegin(GL_QUADS);
  glVertex2f(x1, y1);
  glVertex2f(x2, y1);
  glVertex2f(x2, y2);
  glVertex2f(x1, y2);
  glEnd();
}

void Painter::ball(int x, int y)
{
  glBegin(GL_POLYGON);
  glVertex2f(x + 3, y);
  glVertex2f(x, y + 3);
  glVertex2f(x - 3, y);
  glVertex2f(x, y - 3);
  glEnd();
}

void Painter::setColor(Color color)
{
  static const struct
  {
    float r, g, b;
  } colors[] = 
      {
	{ 1, 1, 0 }, // yellow
	{ 0, 1, 0 }, // green
	{ 1, 0.5, 0 }, // orange
	{ 1, 0, 0 }, // red
	{ 1, 1, 1 }, // yellow
	{ 0, 0, 0 }, // black
      };
  glColor3f(colors[color].r, 
	    colors[color].g, 
	    colors[color].b);
}