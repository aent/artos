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

#include "Scheduler.h"

#include <stdexcept>

namespace artos
{

/**************************************************************************************
 * PUBLIC FUNCTIONS
 **************************************************************************************/

Scheduler::Scheduler()
{
  this->current_task = 0;
}

void Scheduler::run()
{
  Task *task = this->task_list.getHighestPriorityReadyTask();

  bool const is_higher_priority_task_ready = task->getPriority()
      != current_task->getPriority();

  if (is_higher_priority_task_ready)
  {
    this->current_task->setState(Task::READY);
    this->current_task = task;

    this->current_task->setState(Task::RUNNING);
  }

  this->current_task->run();
}

bool Scheduler::registerTask(Task *task)
{
  bool const success = this->task_list.addTask(task);
  if(success)
  {
    this->current_task = this->task_list.getHighestPriorityReadyTask();
    return true;
  }
  else
  {
    return false;
  }
}

/**************************************************************************************
 * PRIVATE FUNCTIONS
 **************************************************************************************/

} // namespace artos
