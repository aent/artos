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

TaskList::TaskList()
{
  this->task_list_head = 0;
}

bool TaskList::addTask(Task *task)
{
  /* Determine if a task with the same priority number is already in the list */

  bool const is_task_list_empty = (this->task_list_head == 0);

  if (is_task_list_empty)
  {
    STaskListEntry *new_task_list_entry = new STaskListEntry;
    new_task_list_entry->task = task;
    new_task_list_entry->next = 0;
    this->task_list_head = new_task_list_entry;

    return true;
  }
  else
  {
    STaskListEntry *current_task_list_entry = this->task_list_head;
    for (; current_task_list_entry->next != 0; current_task_list_entry = current_task_list_entry->next)
    {
      bool const is_task_with_same_priority_in_task_list = current_task_list_entry->task->getPriority() == task->getPriority();
      if (is_task_with_same_priority_in_task_list)
      {
        return false;
      }
    }
  }

  /* Find out the position where the task needs to be inserted */

  STaskListEntry *current_task_list_entry = this->task_list_head;
  STaskListEntry *prev_task_list_entry = 0;
  for (; current_task_list_entry->next != 0; current_task_list_entry = current_task_list_entry->next)
  {
    if(current_task_list_entry->task->getPriority() > task->getPriority())
    {
      STaskListEntry *new_task_list_entry = new STaskListEntry;
      new_task_list_entry->task = task;
      new_task_list_entry->next = current_task_list_entry;

      if(prev_task_list_entry != 0)
      {
        prev_task_list_entry->next = new_task_list_entry;
      }
      else
      {
        this->task_list_head = new_task_list_entry;
      }
    }

    prev_task_list_entry = current_task_list_entry;
  }

  return true;
}

Task *TaskList::getTaskById(uint16_t const id)
{
  STaskListEntry *current_task_list_entry = this->task_list_head;
  for (; current_task_list_entry->next != 0; current_task_list_entry = current_task_list_entry->next)
  {
    bool const is_task_with_same_id_in_task_list = current_task_list_entry->task->getId() == id;
    if (is_task_with_same_id_in_task_list)
    {
      return current_task_list_entry->task;
    }
  }

  return 0;
}

Task *TaskList::getHighestPriorityReadyTask()
{
  STaskListEntry *current_task_list_entry = this->task_list_head;
  for (; current_task_list_entry->next != 0; current_task_list_entry = current_task_list_entry->next)
  {
    if (current_task_list_entry->task->getState() == Task::READY)
    {
      return current_task_list_entry->task;
    }
  }

  return 0;
}

} // namespace artos
