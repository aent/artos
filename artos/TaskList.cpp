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

#include "TaskList.h"

#include <stdexcept>

namespace artos
{

/**************************************************************************************
 * PUBLIC FUNCTIONS
 **************************************************************************************/

void TaskList::addTask(Task *task)
{
  /* Determine if a task with the same priority number is already in the list */

  {
    std::list<Task *>::iterator iter = this->task_list.begin();
    for (; iter != this->task_list.end(); iter++)
    {
      Task *current_task = *iter;

      bool const is_task_with_same_priority_in_task_list =
          current_task->getPriority() == task->getPriority();

      if (is_task_with_same_priority_in_task_list)
      {
        throw std::runtime_error(
            "insertTask() failed: Task with identical priority number already in the task list");
      }
    }
  }

  /* Find out the position where the task needs to be inserted */

  {
    std::list<Task *>::iterator iter = this->task_list.begin();
    for (; iter != this->task_list.end(); iter++)
    {
      Task *current_task = *iter;

      if(current_task->getPriority() > task->getPriority())
      {
        break;
      }
    }

    this->task_list.insert(iter, task);
  }

}

Task *TaskList::getTaskByPriority(uint16_t const priority)
{
  std::list<Task *>::iterator iter = this->task_list.begin();
  for (; iter != this->task_list.end(); iter++)
  {
    Task *current_task = *iter;

    if(current_task->getPriority() == priority)
    {
      return current_task;
    }
  }

  throw std::runtime_error("getTaskByPriority() - invalid priority number");
}

Task *TaskList::getHighestPriorityReadyTask()
{
  std::list<Task *>::iterator iter = this->task_list.begin();
  for (; iter != this->task_list.end(); iter++)
  {
    Task *current_task = *iter;

    if(current_task->getState() == Task::READY)
    {
      return current_task;
    }
  }

  throw std::runtime_error("getHighestPriorityReadyTask() - no ready task available in list");
}

} // namespace artos
