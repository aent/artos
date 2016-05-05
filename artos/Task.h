/**
 * Copyright (c) 2016, Alexander Entinger
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of artos nor the names of its
 *  contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
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

#ifndef ARTOS_TASK_H_
#define ARTOS_TASK_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <stdint.h>

namespace artos
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class Task
{

public:

  typedef enum { READY, RUNNING, BLOCKED, SUSPENDED } ETaskState;

  /* Constructor / Destructor */

  Task          (uint16_t const priority);
  virtual ~Task ();

  /* Public class methods */

  void run();

  /* Getter */

  uint16_t    getPriority () const;
  ETaskState  getState    () const;

  /* Setter */

  void setState(ETaskState const state);

protected:

  virtual void task_init_function () = 0;
  virtual void task_run_function  () = 0;

private:

  uint16_t priority;
  ETaskState state;

  void runInitFunctionOnlyOnce();
  void runTaskFunction        ();

};

} // namespace artos

#endif /* ARTOS_TASK_H_ */
