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

#include "wall.hpp"
#include "ball.hpp"

Wall::Wall()
{
  for (int row = 0; row < 8; ++row)
    for (int col = 0; col < COLS_COUNT; ++col)
      bricks_.push_back(Brick(col, row));
}

void Wall::draw(Painter &p) const
{
  for (Bricks::const_iterator i = bricks_.begin(); 
       i != bricks_.end(); ++i)
    i -> draw(p);
}

Force Wall::tick(const Ball &ball)
{
  Force result(0, 0);
  if (1 - ball.x() > 0)
    result += Force(1 - ball.x(), 0);
  if (WIDTH - ball.x() -1 < 0)
    result += Force(WIDTH - ball.x() -1, 0);
  if (1 - ball.y() > 0)
    result += Force(0, 1 - ball.y());

  for (Bricks::iterator i = bricks_.begin(); 
       i != bricks_.end(); ++i)
  {
    Force f = i -> tick(ball);
    result += f;
    if (f.x != 0 || f.y != 0)
      i -> destroy();
  }

  return result;
}