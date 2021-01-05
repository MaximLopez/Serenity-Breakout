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

#include "ball.hpp"
#include "painter.hpp"
#include "wall.hpp"

Ball::Ball(): x_(Wall::WIDTH / 2), 
	      y_(Wall::HEIGHT - 3), 
	      vx_(80), 
	      vy_(-80) {}

void Ball::draw(Painter &p) const
{
  p.setColor(Painter::WHITE);
  p.ball(x_, y_);
}

void Ball::tick(Force f)
{
  float x = f.x;
  float y = f.y;
  const float LIM = .2;
  if (x > LIM)
    x = LIM;
  if (x < -LIM)
    x = -LIM;
  if (y > LIM)
    y = LIM;
  if (y < -LIM)
    y = -LIM;

  vx_ += 20 * x;
  vy_ += 20 * y;
  x_ += vx_ * DT;
  y_ += vy_ * DT;
}