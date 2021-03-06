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

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "Task.h"

namespace artos
{

/**************************************************************************************
 * STATIC MEMBER VARIABLES
 **************************************************************************************/

uint16_t Task::task_id_cnt = 0;

/**************************************************************************************
 * PUBLIC FUNCTIONS
 **************************************************************************************/

Task::Task(uint16_t const priority)
{
  this->id        = task_id_cnt++;
  this->priority  = priority;
  this->state     = READY;
}

Task::~Task()
{

}

void Task::run()
{
  runInitFunctionOnlyOnce();
  runTaskFunction();
}

uint16_t Task::getId() const
{
  return this->id;
}

uint16_t Task::getPriority() const
{
  return this->priority;
}

Task::ETaskState Task::getState() const
{
  return this->state;
}

uint16_t Task::setPriority (uint16_t const priority)
{
  this->priority = priority;
}

void Task::setState(ETaskState const state)
{
  this->state = state;
}

/**************************************************************************************
 * PRIVATE FUNCTIONS
 **************************************************************************************/

void Task::runInitFunctionOnlyOnce()
{
  static bool was_init_function_executed = false;

  if(!was_init_function_executed)
  {
    was_init_function_executed = true;

    task_init_function();
  }
}

void Task::runTaskFunction()
{
  task_run_function();
}

} // namespace artos
