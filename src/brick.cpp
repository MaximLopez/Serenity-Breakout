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

#include "brick.hpp"
#include "painter.hpp"
#include "ball.hpp"

Brick::Brick(int col, int row): 
  col_(col), 
  row_(row),  
  countDownTimer_(-1) 
{}

void Brick::draw(Painter &p) const
{
  if (countDownTimer_ == -1)
  {
    p.setColor(static_cast<Painter::Color>(row_ / 2));
    p.bar(col_ * WIDTH + 1, row_ * HEIGHT + 1,
	  (col_ + 1) * WIDTH - 1, (row_ + 1) * HEIGHT - 1);
  }
  else if (countDownTimer_ != 0)
  {
    p.setColor
      (static_cast<Painter::Color>
       (countDownTimer_ / 10));
    p.bar(col_ * WIDTH + 1, row_ * HEIGHT + 1,
	  (col_ + 1) * WIDTH - 1, (row_ + 1) * HEIGHT - 1);
  }
}

Force Brick::tick(const Ball &ball) 
{
  if (countDownTimer_ == 0)
    return Force(0, 0);
  if (countDownTimer_ > 0)
    --countDownTimer_;

  Force result(0, 0);
  float f1 = (ball.y() - row_ * HEIGHT) * WIDTH - 
    (ball.x() - col_ * WIDTH) * HEIGHT;
  float f2 = (ball.y() - row_ * HEIGHT - HEIGHT) * WIDTH +
    (ball.x() - col_ * WIDTH) * HEIGHT;
  bool d = f1 < 0;
  bool u = f2 < 0;
  if (d && u) // top
  {
    if (row_ * HEIGHT - ball.y() - 1 < 0)
      result += Force(0, row_ * HEIGHT - ball.y() - 1);
  }
  else if (d && !u) // right
  {
    if (col_ * WIDTH + WIDTH - ball.x() + 1 > 0)
      result += Force(col_ * WIDTH + WIDTH - ball.x() + 1, 
		      0);
  }
  else if (!d && u) // left
  {
    if (col_ * WIDTH - ball.x() - 1 < 0)
      result += Force(0, col_ * WIDTH - ball.x() - 1);
  }
  else // if (!d && !u) // bottom
  {
    if (row_ * HEIGHT + HEIGHT - ball.y() + 1 > 0)
      result += Force
	(0, row_ * HEIGHT + HEIGHT - ball.y() + 1);
  }
  return result;
}

void Brick::destroy()
{
  if (countDownTimer_ == -1)
    countDownTimer_ = Painter::BLACK * 10;
}